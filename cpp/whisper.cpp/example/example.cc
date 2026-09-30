#include <iostream>
#include <vector>

#include "common-whisper.h"
#include "whisper.h"

int main(void) {
  struct whisper_context_params cparams = whisper_context_default_params();
  struct whisper_context* ctx =
      whisper_init_from_file_with_params("./ggml-tiny.bin", cparams);

  if (!ctx) {
    std::cerr << "Failed to initialize whisper context!" << std::endl;
    return 1;
  }

  const std::string filename = "./sample.wav";
  std::vector<float> pcm32f;
  std::vector<std::vector<float>> pcm32f_stereo;

  // Load audio from file
  if (!read_audio_data(filename.c_str(), pcm32f, pcm32f_stereo, false)) {
    std::cerr << "Failed to read WAV file or sample rate is not 16kHz!"
              << std::endl;
    return 1;
  }

  struct whisper_full_params params =
      whisper_full_default_params(WHISPER_SAMPLING_GREEDY);

  params.print_progress = false;
  params.print_special = false;
  params.print_realtime = false;
  params.print_timestamps = true;
  params.language = "en";  // Options: "auto", "en", "es", etc.
  params.n_threads = 4;    // Number of CPU threads to use

  if (whisper_full(ctx, params, pcm32f.data(), pcm32f.size()) == 0) {
    int n_segments = whisper_full_n_segments(ctx);
    for (int i = 0; i < n_segments; ++i) {
      std::cout << whisper_full_get_segment_text(ctx, i) << std::endl;
    }
  }

  whisper_free(ctx);
  return 0;
}
