#include <stb_image.h>
#include <stb_image_resize2.h>
#include <torch/script.h>
#include <torch/torch.h>

#include <iostream>
#include <vector>

torch::Tensor load_image(const std::string &image_path) {
  int input_width = 0, input_height = 0, input_channels = 0;
  auto image_data = stbi_load(image_path.c_str(), &input_width, &input_height,
                              &input_channels, 0);
  if (!image_data) {
    std::string message = "Fail to load image";
    message += stbi_failure_reason();
    throw std::runtime_error(message);
  }
  assert(input_channels == 3);
  int output_width = 224;
  int output_height = 224;

  std::vector<uint8_t> output_image_data(output_width * output_height * 3);
  stbir_resize(image_data, input_width, input_height, 0,
               output_image_data.data(), output_width, output_height, 0,
               STBIR_RGB, STBIR_TYPE_UINT8, STBIR_EDGE_CLAMP,
               STBIR_FILTER_DEFAULT);
  torch::Tensor tensor_image = torch::from_blob(
      image_data, {1, output_height, output_width, 3}, torch::kUInt8);
  // torch::Tensor tensor_image = torch::from_blob(
  //     image_data, {1, input_height, input_width, 3}, torch::kUInt8);

  // resnet18 normalization
  tensor_image = tensor_image.to(torch::kFloat32).div(255);
  tensor_image = tensor_image.sub(torch::tensor({0.485, 0.456, 0.406}))
                     .div(torch::tensor({0.229, 0.224, 0.225}));
  tensor_image = tensor_image.permute({0, 3, 1, 2});

  stbi_image_free(image_data);
  return tensor_image.clone();
}

int main(void) {
  torch::jit::script::Module module;
  try {
    module = torch::jit::load("traced_resnet_model.pt");
  } catch (const c10::Error &e) {
    std::cerr << "error loading the model\n";
    return -1;
  }

  std::ifstream file("./imagenet-classes.txt");
  std::vector<std::string> labels;
  std::string line;
  while (std::getline(file, line)) {
    if (line.length()) {
      labels.push_back(line);
    }
  }
  assert(labels.size() == 1000);

  auto image_tensor = load_image("./cat.jpg");
  // auto image_tensor = load_image("./cat2.jpg");
  // std::cout << image_tensor << std::endl;
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(image_tensor);

  auto output = module.forward(inputs).toTensor();
  // std::cout << output << std::endl;
  auto result = output.argmax(1);
  int idx = result.item<int>();
  std::cout << idx << std::endl;
  std::cout << "resnet18 prediction: " << labels[idx] << std::endl;
  return 0;
}
