#include <curl/curl.h>
#include <onnxruntime_cxx_api.h>
#include <stb_image.h>
#include <stb_image_resize2.h>

#include <CLI/CLI.hpp>
#include <fstream>
#include <iostream>

struct BoundingBox {
  std::array<float, 4> bbox;
  int label_idx;
  float prob;
};

bool file_exists(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

static size_t write_callback(void* contents, size_t size, size_t nmemb,
                             void* stream) {
  std::ofstream* out = static_cast<std::ofstream*>(stream);
  size_t total_size = size * nmemb;
  out->write(static_cast<char*>(contents), total_size);
  return total_size;
}

float sigmoid(float x) { return 1.0f / (1.0f + exp(-x)); }

std::vector<float> softmax(std::vector<float>& v) {
  float max_val = *max_element(v.begin(), v.end());
  std::vector<float> output(v.size());
  float sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    output[i] = exp(v[i] - max_val);
    sum += output[i];
  }
  for (size_t i = 0; i < v.size(); ++i) {
    output[i] /= sum;
  }
  return output;
}

float decode_distribution(std::vector<float>& v) {
  std::vector<float> prob = softmax(v);
  float result = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    result += prob[i] * i;
  }
  return result;
}

float clip(float val, float lower, float upper) {
  return fmin(fmax(val, lower), upper);
}

std::vector<BoundingBox> extract_bounding_box(
    std::vector<float>& output, std::array<int64_t, 4>& shape,
    std::array<int64_t, 2>& original_size, std::array<int64_t, 2>& input_size,
    float confidence_threshold, float stride, int reg_max = 16) {
  auto at = [&](int d1, int d2, int d3, int d4) -> float {
    return output[d1 * shape[1] * shape[2] * shape[3] +
                  d2 * shape[2] * shape[3] + d3 * shape[3] + d4];
  };

  std::vector<BoundingBox> result;
  int grid_h = shape[2], grid_w = shape[3];
  int bbox_offset = 4 * reg_max;
  for (int b = 0; b < 1; ++b) {
    for (int r = 0; r < grid_h; ++r) {
      for (int c = 0; c < grid_w; ++c) {
        std::vector<float> class_scores(80);
        for (int k = 0; k < 80; ++k) {
          class_scores[k] = at(b, k + bbox_offset, r, c);
        }
        int class_idx = max_element(class_scores.begin(), class_scores.end()) -
                        class_scores.begin();
        float class_score = sigmoid(class_scores[class_idx]);
        if (class_score < confidence_threshold) {
          continue;
        }
        std::vector<float> boxes(reg_max * 4);
        for (int k = 0; k < reg_max * 4; ++k) {
          boxes[k] = at(b, k, r, c);
        }
        std::vector<float> left(boxes.begin(), boxes.begin() + reg_max);
        std::vector<float> top(boxes.begin() + reg_max,
                               boxes.begin() + 2 * reg_max);
        std::vector<float> right(boxes.begin() + 2 * reg_max,
                                 boxes.begin() + 3 * reg_max);
        std::vector<float> bot(boxes.begin() + 3 * reg_max,
                               boxes.begin() + 4 * reg_max);
        float dist_left = decode_distribution(left);
        float dist_top = decode_distribution(top);
        float dist_right = decode_distribution(right);
        float dist_bot = decode_distribution(bot);
        float cy = (r + 0.5) * stride;
        float cx = (c + 0.5) * stride;
        float x0 = cx - dist_left * stride;
        float y0 = cy - dist_top * stride;
        float x1 = cx + dist_right * stride;
        float y1 = cy + dist_bot * stride;
        float scale_x = (float)original_size[0] / input_size[0];
        float scale_y = (float)original_size[1] / input_size[1];
        x0 = clip(x0 * scale_x, 0, original_size[0]);
        y0 = clip(y0 * scale_y, 0, original_size[1]);
        x1 = clip(x1 * scale_x, 0, original_size[0]);
        y1 = clip(y1 * scale_y, 0, original_size[1]);

        result.push_back(BoundingBox{
            .bbox = std::array<float, 4>{x0, y0, x1, y1},
            .label_idx = class_idx,
            .prob = class_score,
        });
      }
    }
  }

  return result;
}

void download_model(std::string model_path) {
  if (file_exists(model_path)) {
    return;
  }

  CURL* curl = curl_easy_init();

  std::cout << "downloading model..." << std::endl;
  std::ofstream onnx_model(model_path, std::ios::binary);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &onnx_model);

  std::string url =
      "https://huggingface.co/AXERA-TECH/YOLO11/resolve/main/yolo11s-cut.onnx";
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 0L);
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, nullptr);
  CURLcode res = curl_easy_perform(curl);
  if (res == CURLE_OK) {
    std::cout << "Downloaded successfully to " << model_path << std::endl;
  } else {
    std::cerr << "Download failed: " << curl_easy_strerror(res) << std::endl;
  }
  onnx_model.close();
  curl_easy_cleanup(curl);
  std::cout << "download done." << std::endl;
}

float iou(const BoundingBox& b1, const BoundingBox& b2) {
  float left = fmax(b1.bbox[0], b2.bbox[0]);
  float top = fmax(b1.bbox[1], b2.bbox[1]);
  float right = fmin(b1.bbox[2], b2.bbox[2]);
  float bot = fmin(b1.bbox[3], b2.bbox[3]);
  float w = right - left;
  float h = bot - top;
  return w * h;
}

std::vector<BoundingBox> non_max_suppress(
    std::vector<BoundingBox>& detected_boxes, float nms_threshold) {
  std::vector<BoundingBox> final_result;
  for (int class_idx = 0; class_idx < 80; ++class_idx) {
    std::vector<size_t> indices;
    for (size_t i = 0; i < detected_boxes.size(); ++i) {
      if (detected_boxes[i].label_idx == class_idx) {
        indices.push_back(i);
      }
    }
    if (indices.empty()) {
      continue;
    }

    sort(indices.begin(), indices.end(), [&](int i1, int i2) {
      return detected_boxes[i1].prob > detected_boxes[i2].prob;
    });

    std::vector<size_t> keep;

    auto found = [&](size_t i) -> bool {
      for (size_t j : keep) {
        if (iou(detected_boxes[j], detected_boxes[i]) >= nms_threshold) {
          return true;
        }
      }
      return false;
    };

    for (size_t idx : indices) {
      if (!found(idx)) {
        keep.push_back(idx);
      }
    }

    for (size_t idx : keep) {
      final_result.push_back(detected_boxes[idx]);
    }
  }
  return final_result;
}

int main(int argc, char* argv[]) {
  CLI::App app{"App description"};
  argv = app.ensure_utf8(argv);

  std::string filename = "test.jpg";
  app.add_option("-f,--file", filename, "image file");
  CLI11_PARSE(app, argc, argv);

  // download model
  std::string model_path = "yolo11s.onnx";
  download_model(model_path);

  // onnx runtime
  auto memory_info =
      Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
  Ort::Env env;
  Ort::Session session(env, model_path.c_str(), Ort::SessionOptions{nullptr});

  std::array<int64_t, 4> input_shape{1, 3, 640, 640};
  std::vector<std::array<int64_t, 4>> output_shape = {
      {1, 144, 80, 80}, {1, 144, 40, 40}, {1, 144, 20, 20}};
  std::vector<float> strides = {8, 16, 32};
  const char* input_names[] = {"images"};
  const char* output_names[] = {"/model.23/Concat_output_0",
                                "/model.23/Concat_1_output_0",
                                "/model.23/Concat_2_output_0"};

  // load image
  int width = 0, height = 0, channels = 0;
  unsigned char* data =
      stbi_load(filename.c_str(), &width, &height, &channels, 0);
  assert(channels == 3);

  // resize to 640x640
  int new_width = 640, new_height = 640;
  std::vector<uint8_t> resized(new_width * new_height * channels);
  stbir_resize_uint8_linear(data, width, height, 0, resized.data(), new_width,
                            new_height, 0, (stbir_pixel_layout)channels);

  std::vector<float> nchw(1 * channels * new_height * new_width);
  for (int h = 0; h < 640; ++h) {
    for (int w = 0; w < 640; ++w) {
      for (int c = 0; c < 3; ++c) {
        nchw[c * new_height * new_width + h * new_width + w] =
            resized[h * new_width * 3 + w * 3 + c] / 255.0;
      }
    }
  }

  Ort::Value input_tensor =
      Ort::Value::CreateTensor<float>(memory_info, nchw.data(), nchw.size(),
                                      input_shape.data(), input_shape.size());

  std::vector<Ort::Value> output_tensor;
  std::vector<std::vector<float>> outputs;
  for (int i = 0; i < 3; ++i) {
    int size = 1;
    for (int d = 0; d < 4; ++d) {
      size *= output_shape[i][d];
    }
    outputs.push_back(std::vector<float>(size));
    std::vector<float>& o = outputs.back();
    Ort::Value t = Ort::Value::CreateTensor<float>(
        memory_info, o.data(), o.size(), output_shape[i].data(),
        output_shape[i].size());
    output_tensor.push_back(std::move(t));
  }

  Ort::RunOptions run_options;
  session.Run(run_options, input_names, &input_tensor, 1, output_names,
              output_tensor.data(), 3);

  std::cout << "inference done." << std::endl;

  std::vector<std::string> COCO_CLASSES = {
      "person",        "bicycle",      "car",
      "motorcycle",    "airplane",     "bus",
      "train",         "truck",        "boat",
      "traffic light", "fire hydrant", "stop sign",
      "parking meter", "bench",        "bird",
      "cat",           "dog",          "horse",
      "sheep",         "cow",          "elephant",
      "bear",          "zebra",        "giraffe",
      "backpack",      "umbrella",     "handbag",
      "tie",           "suitcase",     "frisbee",
      "skis",          "snowboard",    "sports ball",
      "kite",          "baseball bat", "baseball glove",
      "skateboard",    "surfboard",    "tennis racket",
      "bottle",        "wine glass",   "cup",
      "fork",          "knife",        "spoon",
      "bowl",          "banana",       "apple",
      "sandwich",      "orange",       "broccoli",
      "carrot",        "hot dog",      "pizza",
      "donut",         "cake",         "chair",
      "couch",         "potted plant", "bed",
      "dining table",  "toilet",       "tv",
      "laptop",        "mouse",        "remote",
      "keyboard",      "cell phone",   "microwave",
      "oven",          "toaster",      "sink",
      "refrigerator",  "book",         "clock",
      "vase",          "scissors",     "teddy bear",
      "hair drier",    "toothbrush"};

  std::array<int64_t, 2> original_size = {width, height};
  std::array<int64_t, 2> input_size = {640, 640};
  float confidence_threshold = 0.45;

  std::vector<BoundingBox> all_boxes;
  for (int i = 0; i < 3; ++i) {
    std::vector<BoundingBox> boxes =
        extract_bounding_box(outputs[i], output_shape[i], original_size,
                             input_size, confidence_threshold, strides[i]);
    std::cout << "found bounding boxes: " << boxes.size() << std::endl;
    all_boxes.insert(all_boxes.end(), boxes.begin(), boxes.end());
  }

  std::cout << "detected boxes: " << all_boxes.size() << std::endl;

  float nms_threshold = 0.45;
  std::vector<BoundingBox> nms_result =
      non_max_suppress(all_boxes, nms_threshold);
  for (BoundingBox& b : nms_result) {
    std::string class_name = COCO_CLASSES[b.label_idx];
    std::array<float, 4>& bbox = b.bbox;
    std::cout << "detected " << class_name << " at (" << bbox[0] << ","
              << bbox[1] << "," << bbox[2] << "," << bbox[3] << ")"
              << std::endl;
  }
  return 0;
}
