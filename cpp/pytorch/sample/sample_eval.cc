#include <torch/script.h>
#include <torch/torch.h>

#include "net.h"

int main() {
  auto model = std::make_shared<Net>();
  try {
    torch::load(model, "net.pt"); // Use torch::load for a regular model
  } catch (const c10::Error &e) {
    std::cerr << "Error loading the model.\n";
    return -1;
  }

  auto mode = torch::data::datasets::MNIST::Mode::kTest;
  auto test_dataset = torch::data::datasets::MNIST("./data", mode)
                          .map(torch::data::transforms::Stack<>());

  int batch_size = 64;
  auto test_loader =
      torch::data::make_data_loader(std::move(test_dataset), batch_size);

  int correct = 0;
  int total = 0;

  model->eval();
  for (auto &batch : *test_loader) {
    auto images = batch.data;
    auto labels = batch.target;
    torch::Tensor output = model->forward({images});
    auto prediction = output.argmax(1);

    correct += prediction.eq(labels).sum().item<int>();
    total += labels.size(0);
  }

  double accuracy = 100.0 * correct / total;
  std::cout << "Test Accuracy: " << accuracy << "%\n";
  return 0;
}
