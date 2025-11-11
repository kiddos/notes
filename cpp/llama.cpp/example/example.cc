#include <llama.h>

#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Model {
 public:
  Model(const std::string& model_path, int n_predict)
      : model_(nullptr), n_predict_(n_predict) {
    llama_model_params model_params = llama_model_default_params();
    model_params.n_gpu_layers = 0;

    model_ = llama_model_load_from_file(model_path.c_str(), model_params);
    vocab_ = llama_model_get_vocab(model_);

    llama_context_params ctx_params = llama_context_default_params();
    // n_ctx is the context size
    ctx_params.n_ctx = 2048;
    // n_batch is the maximum number of tokens that can be processed in a single
    // call to llama_decode
    ctx_params.n_batch = n_predict;
    // enable performance counters
    ctx_params.no_perf = false;

    ctx_ = llama_init_from_model(model_, ctx_params);

    auto sparams = llama_sampler_chain_default_params();
    sparams.no_perf = false;

    smpl_ = llama_sampler_chain_init(sparams);
    llama_sampler_chain_add(smpl_, llama_sampler_init_top_k(100));
    llama_sampler_chain_add(smpl_, llama_sampler_init_top_p(0.1, 1));
    llama_sampler_chain_add(smpl_, llama_sampler_init_temp(0.0));
    // llama_sampler_chain_add(smpl_, llama_sampler_init_greedy());
    llama_sampler_chain_add(smpl_, llama_sampler_init_dist(666666));
  }

  ~Model() {
    if (smpl_) {
      llama_sampler_free(smpl_);
    }
    if (ctx_) {
      llama_free(ctx_);
    }
    if (model_) {
      llama_model_free(model_);
    }
  }

  int Generate(const std::string& prompt,
               std::function<void(std::string)> callback) {
    int n_prompt = -llama_tokenize(vocab_, prompt.c_str(), prompt.size(), NULL,
                                   0, true, true);
    std::vector<llama_token> prompt_tokens(n_prompt);
    if (llama_tokenize(vocab_, prompt.c_str(), prompt.size(),
                       prompt_tokens.data(), prompt_tokens.size(), true,
                       true) < 0) {
      std::cerr << __func__ << " error: fail to tokenize the prompt"
                << std::endl;
      return 0;
    }

    llama_batch batch =
        llama_batch_get_one(prompt_tokens.data(), prompt_tokens.size());
    int n_decode = 0;

    for (int n_pos = 0; n_pos + batch.n_tokens < n_prompt + n_predict_;) {
      // evaluate the current batch with the transformer model
      if (llama_decode(ctx_, batch)) {
        std::cerr << __func__ << " fail to decode batch" << std::endl;
        return n_decode;
      }

      n_pos += batch.n_tokens;
      llama_token new_token_id = llama_sampler_sample(smpl_, ctx_, -1);

      // is it an end of generation?
      if (llama_vocab_is_eog(vocab_, new_token_id)) {
        break;
      }

      char buf[128];
      int n =
          llama_token_to_piece(vocab_, new_token_id, buf, sizeof(buf), 0, true);
      if (n < 0) {
        std::cerr << __func__ << ": fail to convert token to piece"
                  << std::endl;
        return n_decode;
      }
      callback(std::string(buf, n));

      // prepare the next batch with the sampled token
      batch = llama_batch_get_one(&new_token_id, 1);

      n_decode += 1;
    }
    return n_decode;
  }

 private:
  llama_model* model_;
  const llama_vocab* vocab_;
  llama_context* ctx_;
  llama_sampler* smpl_;
  int n_predict_;
};

int main(void) {
  std::string model_path = "Llama-3.2-1B-Instruct-Q4_K_M.gguf";

  ggml_backend_load_all();
  Model model(model_path, 512);

  std::string prompt =
      "<|begin_of_text|><|start_header_id|>system<|end_header_id|>\n\n"
      "Cutting Knowledge Date: December 2023\n"
      "Today Date: 20 Jan 2025\n\n"
      "You are a helpful AI assistant<|eot_id|>"
      "<|start_header_id|>user<|end_header_id|>\n\n"
      "Tell me a story.<|eot_id|>"
      "<|start_header_id|>assistant<|end_header_id|>";

  const auto t_main_start = ggml_time_us();
  const int n_decode = model.Generate(
      prompt, [&](std::string piece) { std::cout << piece << std::flush; });
  const auto t_main_end = ggml_time_us();
  std::cout << std::endl;

  std::cout << __func__ << ": decoded " << n_decode << " tokens in "
            << (t_main_end - t_main_start) / 1000000.0f << " speed: "
            << n_decode / ((t_main_end - t_main_start) / 1000000.0f) << " t/s"
            << std::endl;
  return 0;
}
