#include <torch/torch.h>
#include <torch/script.h>
#include "net.h"

#include <iostream>

int main() {
  auto net = std::make_shared<Net>();

  auto train_dataset = torch::data::datasets::MNIST("./data").map(
      torch::data::transforms::Stack<>());
  auto mode = torch::data::datasets::MNIST::Mode::kTest;
  auto test_dataset = torch::data::datasets::MNIST("./data", mode)
    .map(torch::data::transforms::Stack<>());

  int batch_size = 256;
  auto train_dl = torch::data::make_data_loader(train_dataset, batch_size);
  auto test_dl = torch::data::make_data_loader(test_dataset, batch_size);


  double lr = 1e-3;
  torch::optim::Adam optimizer(net->parameters(), torch::optim::AdamOptions(lr));

  for (size_t epoch = 1; epoch <= 30; ++epoch) {
    size_t batch_index = 0;
    for (auto &batch : *train_dl) {
      optimizer.zero_grad();
      torch::Tensor prediction = net->forward(batch.data);
      torch::Tensor loss = torch::nll_loss(prediction, batch.target);
      loss.backward();
      optimizer.step();
      if (++batch_index % 100 == 0) {
        std::cout << "Epoch: " << epoch << " | Batch: " << batch_index
                  << " | Loss: " << loss.item<float>() << std::endl;
        torch::save(net, "net.pt");
      }
    }
  }

  int correct = 0;
  int total = 0;

  net->eval();
  for (auto& batch : *test_dl) {
    auto images = batch.data;
    auto labels = batch.target;
    torch::Tensor output = net->forward({images});
    auto prediction = output.argmax(1);

    correct += prediction.eq(labels).sum().item<int>();
    total += labels.size(0);
  }
  double accuracy = 100.0 * correct / total;
  std::cout << "Test Accuracy: " << accuracy << "%\n";

  return 0;
}
