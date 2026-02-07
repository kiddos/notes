FROM ghcr.io/ggml-org/llama.cpp:server

WORKDIR /app

ADD https://huggingface.co/ggml-org/gemma-3-4b-it-GGUF/resolve/main/gemma-3-4b-it-Q4_K_M.gguf /app/gemma-3-4b-it-Q4_K_M.gguf
ADD https://huggingface.co/ggml-org/gemma-3-4b-it-GGUF/resolve/main/mmproj-model-f16.gguf /app/mmproj-model-f16.gguf

EXPOSE 7860

ENTRYPOINT ["/app/llama-server"]

CMD ["--host", "0.0.0.0", "--port", "7860", "-m", "/app/gemma-3-4b-it-Q4_K_M.gguf", "--mmproj", "/app/mmproj-model-f16.gguf" ]
