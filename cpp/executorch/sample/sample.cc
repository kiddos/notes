#include <executorch/extension/module/module.h>
#include <executorch/extension/tensor/tensor.h>

#include <iostream>
#include <opencv2/opencv.hpp>

using Module = executorch::extension::Module;

float input[1 * 3 * 224 * 224] = {0};

executorch::extension::TensorPtr image_to_tensor(
    const std::string& image_path) {
  cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
  cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

  // Get image dimensions.
  int height = image.rows;
  int width = image.cols;
  int channels = image.channels();
  uint8_t* mat_data_ptr = image.data;
  for (int c = 0; c < channels; ++c) {
    for (int h = 0; h < height; ++h) {
      for (int w = 0; w < width; ++w) {
        // Calculate the index for the HWC (OpenCV) layout.
        int hwc_index = (h * width * channels) + (w * channels) + c;
        // Calculate the index for the CHW (PyTorch) layout.
        int chw_index = (c * height * width) + (h * width) + w;
        // Copy the value.
        float val = mat_data_ptr[hwc_index];
        input[chw_index] = val / 255.0;
      }
    }
  }
  // Note: this doesn't allocate new memory
  // so if the float input[] is in the stack
  // it will be invalid when doing the inference
  auto tensor = executorch::extension::from_blob(input,
                                                 {1, channels, height, width});
  return tensor;
}


int main(void) {
  std::cout << "loading module..." << std::endl;
  Module module("../mobilenet_v2.pte");
  auto tensor = image_to_tensor("../test.png");
  const auto result = module.forward(tensor);
  if (result.ok()) {
    // Retrieve the output data.
    const auto output = result->at(0).toTensor().const_data_ptr<float>();
    std::vector<float> output_vector(output, output + 1000);
    int idx = max_element(output_vector.begin(), output_vector.end()) - output_vector.begin();
    std::cout << "Success" << std::endl;
    std::cout << "prediction: " << idx << std::endl;
  }
  return 0;
}
