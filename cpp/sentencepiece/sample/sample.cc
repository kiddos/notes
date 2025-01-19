#include <sentencepiece_processor.h>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

int main(void) {
  sentencepiece::SentencePieceProcessor processor;
  const auto status = processor.Load("tokenizer.model");
  if (!status.ok()) {
    std::cerr << status.ToString() << std::endl;
    return 0;
  }

  const std::string text = "The quick brown fox jumps over the lazy dog.";
  std::vector<std::string> pieces;
  std::vector<int> ids;
  processor.Encode(text, &pieces);
  processor.Encode(text, &ids);
  assert(ids.size() == pieces.size());
  int n = pieces.size();
  for (int i = 0; i < n; ++i) {
    std::cout << "token=" << pieces[i] << ",id=" << ids[i] << std::endl;
  }

  std::string output;
  processor.Decode(ids, &output);
  std::cout << "decode=" << output << std::endl;

  std::vector<std::string> sampled_pieces;
  processor.SampleEncode(text, -1, 0.2, &sampled_pieces);
  for (const std::string& p : sampled_pieces) {
    std::cout << "token=" << p << std::endl;
  }
  return 0;
}
