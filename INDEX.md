# Master Knowledge Index

> Comprehensive catalog and topic index for engineering notes, algorithms, library recipes, and machine learning experiments.

## Overview & Statistics

| Metric | Count |
| :--- | :--- |
| **Knowledge Categories** | 8 |
| **C++ Showcase Libraries** | 80 |
| **Algorithms & Data Structures** | 56 |
| **LeetCode Categories & Problems** | 24 topic categories, 17 problem folders |
| **Jupyter Notebooks** | 348 |
| **Markdown Documents** | 6415 |

## Table of Contents

- [🧠 Artificial Intelligence, Machine Learning & NLP](#ai-ml)
- [⚡ Algorithms & Competitive Programming](#competitive-programming)
- [💻 C++ Ecosystem & Systems Libraries](#cpp-systems)
- [📱 Mobile, Embedded & IoT](#mobile-embedded-iot)
- [🛠️ Systems, Infrastructure & DevOps](#systems-devops)
- [🔒 Security, Cryptography & PKI](#security-crypto)
- [🎨 Web, Graphics & Multimedia](#web-graphics-multimedia)
- [🧬 Healthcare & Bioinformatics](#healthcare-bioinformatics)
- [🔄 Auto-Update Script](#auto-update-script)

---

## <a id="ai-ml"></a>🧠 Artificial Intelligence, Machine Learning & NLP

Large Language Models, deep learning frameworks (JAX/Flax), reinforcement learning, speech, vision, and AI tooling.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Large Language Models (LLM)](LLM/)** | `LLM` | Local LLM inference, RAG (PyMuPDF & Llama 3.2), fine-tuning, DPO, Vector DBs (Milvus, Chroma), Ollama tool calling, and OpenRouter integration. |
| **[JAX & Flax Deep Learning](jax/)** | `jax` | Functional ML with JAX: automatic differentiation, JIT compilation, VMAP vectorization, Pytrees, VAE, Flax CNNs (MNIST, CIFAR-10), and Seq2Seq. |
| **[Reinforcement Learning](RL/)** | `RL` | PyTorch implementations of Deep Q-Networks (DQN), Deep Deterministic Policy Gradient (DDPG), and Actor-Critic (A2C) architectures. |
| **[Real-ESRGAN (Super-Resolution)](Real-ESRGAN/)** | `Real-ESRGAN` | Portable ncnn-Vulkan AI upscaling for images and videos with FFmpeg frame extraction and video reassembly. |
| **[Text-to-Speech (TTS)](tts/)** | `tts` | State-of-the-art TTS model experiments and scripts: Chatterbox, Fish Audio, Kokoro, and Zonos. |
| **[Whisper Speech Recognition](whisper/)** | `whisper` | OpenAI Whisper automatic speech recognition (ASR) setup, audio transcription, and CLI usage. |
| **[Optical Character Recognition (OCR)](ocr/)** | `ocr` | Document parsing and text detection scripts with sample image test suites. |
| **[Byte-Pair Encoding (BPE)](bpe/)** | `bpe` | C++ re-implementation of Hugging Face's Byte-Pair Encoding tokenizer. |
| **[Agent Development Kit (ADK)](adk/)** | `adk` | Gemini Flash tool-calling and multi-tool autonomous agent example. |
| **[Hugging Face Spaces](huggingface-space/)** | `huggingface-space` | Recipes and configurations for deploying AI services (such as llama-server) to Hugging Face Spaces. |
| **[Research Papers Notes](papers/)** | `papers` | Summaries of landmark papers including 'Deep Double Descent: Where Bigger Models and More Data Hurt'. |
| **[Information Retrieval & SQLglot](IR/)** | `IR` | SQL AST parsing, optimization, and cross-dialect transpilation with SQLGlot. |

---

## <a id="competitive-programming"></a>⚡ Algorithms & Competitive Programming

50+ classic algorithms & data structures, problem sets from LeetCode, Codeforces, AtCoder, CSES, and Advent of Code.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Classical Algorithms & Data Structures](algorithm/)** | `algorithm` | 58 reference implementations in C++ & Rust covering Graph theory, Trees, DP, String processing, Geometry, and Number Theory. |
| **[LeetCode Solutions](leetcode/)** | `leetcode` | Solutions categorized by 24 algorithmic patterns (DP, BFS/DFS, Binary Search, Trees, Graphs, Trie, etc.) and numbered problem directories. |
| **[Codeforces Problem Sets](codeforces/)** | `codeforces` | Competitive programming problem solutions indexed across 24 difficulty ranges (1~99 to 2200~2299). |
| **[AtCoder Solutions](atcoder/)** | `atcoder` | Solutions for AtCoder Beginner Contests (ABC 424, 468, 469, 470, 471, 472). |
| **[CSES Problem Set](cses/)** | `cses` | Solutions to the Finnish CSES problem set: Introductory, DP, Graph Algorithms, Range Queries, Tree Algorithms, and Mathematics. |
| **[Advent of Code](advent-of-code/)** | `advent-of-code` | Advent of Code puzzles and solutions (2024). |

<details>
<summary><b>View Full List of 56 Classical Algorithm Implementations</b></summary>

| Algorithm File | Path |
| :--- | :--- |
| **[Aho Corasick](algorithm/aho_corasick.cc)** | `algorithm/aho_corasick.cc` |
| **[Articulation Point](algorithm/articulation_point.cc)** | `algorithm/articulation_point.cc` |
| **[Bellman Ford](algorithm/bellman_ford.cc)** | `algorithm/bellman_ford.cc` |
| **[Binary Lifting](algorithm/binary_lifting.cc)** | `algorithm/binary_lifting.cc` |
| **[Bridge](algorithm/bridge.cc)** | `algorithm/bridge.cc` |
| **[Chinese Remainder Theorem](algorithm/chinese_remainder_theorem.cc)** | `algorithm/chinese_remainder_theorem.cc` |
| **[Closest Pair Of Points](algorithm/closest_pair_of_points.cc)** | `algorithm/closest_pair_of_points.cc` |
| **[Conv 2D](algorithm/conv_2d.cc)** | `algorithm/conv_2d.cc` |
| **[De Bruijn](algorithm/de_bruijn.cc)** | `algorithm/de_bruijn.cc` |
| **[Dijkstra](algorithm/dijkstra.cc)** | `algorithm/dijkstra.cc` |
| **[Dinic](algorithm/dinic.cc)** | `algorithm/dinic.cc` |
| **[Disjoint Set](algorithm/disjoint_set.cc)** | `algorithm/disjoint_set.cc` |
| **[Disjoint Set](algorithm/disjoint_set.rs)** | `algorithm/disjoint_set.rs` |
| **[Edmond Karp](algorithm/edmond_karp.cc)** | `algorithm/edmond_karp.cc` |
| **[Euler Path](algorithm/euler_path.cc)** | `algorithm/euler_path.cc` |
| **[Extended Euclidean](algorithm/extended_euclidean.cc)** | `algorithm/extended_euclidean.cc` |
| **[Fenwick Tree](algorithm/fenwick_tree.cc)** | `algorithm/fenwick_tree.cc` |
| **[Fft](algorithm/fft.cc)** | `algorithm/fft.cc` |
| **[Fft Inplace](algorithm/fft_inplace.cc)** | `algorithm/fft_inplace.cc` |
| **[Fft Modulus](algorithm/fft_modulus.cc)** | `algorithm/fft_modulus.cc` |
| **[First Bit](algorithm/first_bit.cc)** | `algorithm/first_bit.cc` |
| **[Floyd Warshall](algorithm/floyd_warshall.cc)** | `algorithm/floyd_warshall.cc` |
| **[Gcd](algorithm/gcd.cc)** | `algorithm/gcd.cc` |
| **[Gift Wrapping](algorithm/gift_wrapping.cc)** | `algorithm/gift_wrapping.cc` |
| **[Gray](algorithm/gray.cc)** | `algorithm/gray.cc` |
| **[Grundy](algorithm/grundy.cc)** | `algorithm/grundy.cc` |
| **[Heavy Light Decomposition](algorithm/heavy_light_decomposition.cc)** | `algorithm/heavy_light_decomposition.cc` |
| **[Interger Factorization](algorithm/interger_factorization.cc)** | `algorithm/interger_factorization.cc` |
| **[Inverse Factorial](algorithm/inverse_factorial.cc)** | `algorithm/inverse_factorial.cc` |
| **[Kadane](algorithm/kadane.cc)** | `algorithm/kadane.cc` |
| **[Kmp](algorithm/kmp.cc)** | `algorithm/kmp.cc` |
| **[Kosaraju](algorithm/kosaraju.cc)** | `algorithm/kosaraju.cc` |
| **[Lca](algorithm/lca.cc)** | `algorithm/lca.cc` |
| **[Lexigraphic Rank Of String](algorithm/lexigraphic_rank_of_string.cc)** | `algorithm/lexigraphic_rank_of_string.cc` |
| **[Lucus Theorem](algorithm/lucus_theorem.cc)** | `algorithm/lucus_theorem.cc` |
| **[Manacher](algorithm/manacher.cc)** | `algorithm/manacher.cc` |
| **[Modular Division](algorithm/modular_division.cc)** | `algorithm/modular_division.cc` |
| **[Pratt Parsing](algorithm/pratt_parsing.cc)** | `algorithm/pratt_parsing.cc` |
| **[Prim](algorithm/prim.cc)** | `algorithm/prim.cc` |
| **[Quick Select](algorithm/quick_select.cc)** | `algorithm/quick_select.cc` |
| **[Robinhood Hash](algorithm/robinhood_hash.cc)** | `algorithm/robinhood_hash.cc` |
| **[Segment Tree Array Impl](algorithm/segment_tree_array_impl.cc)** | `algorithm/segment_tree_array_impl.cc` |
| **[Segment Tree Lazy](algorithm/segment_tree_lazy.cc)** | `algorithm/segment_tree_lazy.cc` |
| **[Segment Tree Tree Impl](algorithm/segment_tree_tree_impl.cc)** | `algorithm/segment_tree_tree_impl.cc` |
| **[Shunting Yard](algorithm/shunting_yard.cc)** | `algorithm/shunting_yard.cc` |
| **[Sieves Of Eratothenes](algorithm/sieves_of_eratothenes.cc)** | `algorithm/sieves_of_eratothenes.cc` |
| **[Sparse Table](algorithm/sparse_table.cc)** | `algorithm/sparse_table.cc` |
| **[Suffix Array](algorithm/suffix_array.cc)** | `algorithm/suffix_array.cc` |
| **[Suffix Array Naive](algorithm/suffix_array_naive.cc)** | `algorithm/suffix_array_naive.cc` |
| **[Svm](algorithm/svm.cc)** | `algorithm/svm.cc` |
| **[Tarjan](algorithm/tarjan.cc)** | `algorithm/tarjan.cc` |
| **[Topological Sort](algorithm/topological_sort.cc)** | `algorithm/topological_sort.cc` |
| **[Trie](algorithm/trie.cc)** | `algorithm/trie.cc` |
| **[Welsh Powell](algorithm/welsh_powell.cc)** | `algorithm/welsh_powell.cc` |
| **[Z Function](algorithm/z_function.cc)** | `algorithm/z_function.cc` |
| **[Zobrist Hashing](algorithm/zobrist_hashing.cc)** | `algorithm/zobrist_hashing.cc` |

</details>

---

## <a id="cpp-systems"></a>💻 C++ Ecosystem & Systems Libraries

80+ C++ libraries and frameworks with ready-to-run examples, CMake recipes, and build configurations.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[C++ Libraries Showcase (80+ Libraries)](cpp/)** | `cpp` | Curated working examples spanning AI runtimes, Graphics, Networking, Databases, Serialization, and Utilities. |

<details>
<summary><b>View Breakdown of all 80 C++ Libraries by Domain</b></summary>

#### AI, Machine Learning & Vision

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[llama.cpp](cpp/llama.cpp/)** | `cpp/llama.cpp` | LLM inference runtime in pure C/C++ |
| **[whisper.cpp](cpp/whisper.cpp/)** | `cpp/whisper.cpp` | High-performance inference of OpenAI Whisper model |
| **[onnx](cpp/onnx/)** | `cpp/onnx` | Open Neural Network Exchange runtime and model parsing |
| **[executorch](cpp/executorch/)** | `cpp/executorch` | PyTorch on-device AI runtime for edge devices |
| **[faiss](cpp/faiss/)** | `cpp/faiss` | Library for efficient similarity search and dense vector clustering |
| **[pytorch](cpp/pytorch/)** | `cpp/pytorch` | LibTorch C++ API for PyTorch model execution |
| **[tesseract](cpp/tesseract/)** | `cpp/tesseract` | Tesseract OCR engine integration |
| **[opencv](cpp/opencv/)** | `cpp/opencv` | Computer vision, image processing, and video analysis |
| **[sentencepiece](cpp/sentencepiece/)** | `cpp/sentencepiece` | Unsupervised text tokenizer and detokenizer |
| **[cuda](cpp/cuda/)** | `cpp/cuda` | NVIDIA CUDA GPU parallel computing and acceleration |

#### Computer Graphics, GUI & Multimedia

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[SDL3](cpp/SDL3/)** | `cpp/SDL3` | Simple DirectMedia Layer 3 for audio, keyboard, mouse, and display |
| **[raylib](cpp/raylib/)** | `cpp/raylib` | Simple and easy-to-use library to enjoy videogames programming |
| **[SFML](cpp/SFML/)** | `cpp/SFML` | Simple and Fast Multimedia Library for 2D graphics and audio |
| **[glfw](cpp/glfw/)** | `cpp/glfw` | Multi-platform library for OpenGL, OpenGL ES, Vulkan development |
| **[qt](cpp/qt/)** | `cpp/qt` | Cross-platform C++ GUI application framework and widgets |
| **[imgui](cpp/imgui/)** | `cpp/imgui` | Dear ImGui: bloat-free immediate mode graphical user interface |
| **[imtui](cpp/imtui/)** | `cpp/imtui` | Immediate Mode Terminal User Interface based on ncurses |
| **[ncurses](cpp/ncurses/)** | `cpp/ncurses` | Terminal handling library for text-based user interfaces |
| **[freetype](cpp/freetype/)** | `cpp/freetype` | Font engine capable of rendering true-type font glyphs |
| **[ImageMagick](cpp/ImageMagick/)** | `cpp/ImageMagick` | Image reading, writing, and manipulation library |
| **[stb](cpp/stb/)** | `cpp/stb` | Single-file public domain libraries for images, fonts, audio |
| **[g2o](cpp/g2o/)** | `cpp/g2o` | General Framework for Graph Optimization in SLAM and robotics |

#### Networking, RPC & Web

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[grpc](cpp/grpc/)** | `cpp/grpc` | High performance, open-source universal RPC framework |
| **[cpr](cpp/cpr/)** | `cpp/cpr` | C++ Requests: modern C++ HTTP library inspired by Python Requests |
| **[curl](cpp/curl/)** | `cpp/curl` | Multiprotocol file transfer library (libcurl) |
| **[libuv](cpp/libuv/)** | `cpp/libuv` | Multi-platform asynchronous I/O library (Node.js event loop) |
| **[libevent](cpp/libevent/)** | `cpp/libevent` | Asynchronous event notification library |
| **[workflow](cpp/workflow/)** | `cpp/workflow` | C++ parallel computing and asynchronous networking engine |
| **[tcp](cpp/tcp/)** | `cpp/tcp` | Raw TCP socket communication implementation |

#### Databases, Key-Value & Storage Engines

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[redis](cpp/redis/)** | `cpp/redis` | Redis client integration in C++ |
| **[rocksdb](cpp/rocksdb/)** | `cpp/rocksdb` | Persistent high-performance key-value store for fast storage |
| **[leveldb](cpp/leveldb/)** | `cpp/leveldb` | Fast key-value storage library written at Google |
| **[sqlite3](cpp/sqlite3/)** | `cpp/sqlite3` | Self-contained, serverless, zero-configuration SQL database |
| **[lmdb](cpp/lmdb/)** | `cpp/lmdb` | Lightning Memory-Mapped Database |
| **[mongodb](cpp/mongodb/)** | `cpp/mongodb` | MongoDB C++ driver connection and query examples |
| **[db2](cpp/db2/)** | `cpp/db2` | IBM DB2 database connectivity |

#### Serialization, Formats & Document Processing

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[protobuf](cpp/protobuf/)** | `cpp/protobuf` | Google Protocol Buffers for structured data serialization |
| **[json](cpp/json/)** | `cpp/json` | Nlohmann JSON: JSON for Modern C++ |
| **[jsoncpp](cpp/jsoncpp/)** | `cpp/jsoncpp` | C++ library that allows manipulating JSON values |
| **[json-c](cpp/json-c/)** | `cpp/json-c` | JSON implementation in C |
| **[yaml-cpp](cpp/yaml-cpp/)** | `cpp/yaml-cpp` | YAML parser and emitter for C++ |
| **[pugixml](cpp/pugixml/)** | `cpp/pugixml` | Light-weight, simple and fast XML parser with XPath support |
| **[libexpat](cpp/libexpat/)** | `cpp/libexpat` | Fast streaming XML parser library |
| **[cereal](cpp/cereal/)** | `cpp/cereal` | Header-only C++11 serialization library |
| **[OpenXLSX](cpp/OpenXLSX/)** | `cpp/OpenXLSX` | C++ library for reading and writing Microsoft Excel (.xlsx) files |
| **[PDF-Writer](cpp/PDF-Writer/)** | `cpp/PDF-Writer` | Fast C++ library for creating, modifying, and parsing PDF files |
| **[poppler](cpp/poppler/)** | `cpp/poppler` | PDF rendering library based on xpdf codebase |
| **[dcmtk](cpp/dcmtk/)** | `cpp/dcmtk` | DICOM medical image communication and file parsing |

#### Compression, Cryptography & Security

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[zlib](cpp/zlib/)** | `cpp/zlib` | Massively spiffy yet delicately unobtrusive compression library |
| **[zstd](cpp/zstd/)** | `cpp/zstd` | Zstandard - Fast real-time compression algorithm |
| **[LZMA](cpp/LZMA/)** | `cpp/LZMA` | Lempel-Ziv-Markov chain compression algorithm |
| **[libzip](cpp/libzip/)** | `cpp/libzip` | C library for reading, creating, and modifying zip archives |
| **[libarchive](cpp/libarchive/)** | `cpp/libarchive` | Multi-format archive and compression library |
| **[openssl](cpp/openssl/)** | `cpp/openssl` | TLS/SSL and general purpose cryptography library |
| **[libsodium](cpp/libsodium/)** | `cpp/libsodium` | Modern, easy-to-use crypto library for encryption/decryption |
| **[clamav](cpp/clamav/)** | `cpp/clamav` | Antivirus engine toolkit integration |

#### Core Utilities, Algorithms & Benchmarking

| Library | Path | Focus / Description |
| :--- | :--- | :--- |
| **[abseil-cpp](cpp/abseil-cpp/)** | `cpp/abseil-cpp` | Google Abseil common libraries (strings, containers, flags) |
| **[boost](cpp/boost/)** | `cpp/boost` | Boost C++ libraries collection |
| **[eigen](cpp/eigen/)** | `cpp/eigen` | Template library for linear algebra, matrices, and vectors |
| **[fmt](cpp/fmt/)** | `cpp/fmt` | Modern formatting library formatted with Python-like syntax |
| **[spdlog](cpp/spdlog/)** | `cpp/spdlog` | Fast C++ logging library |
| **[gflags](cpp/gflags/)** | `cpp/gflags` | Commandline flags processing library |
| **[gtest](cpp/gtest/)** | `cpp/gtest` | Google Test C++ testing framework |
| **[benchmark](cpp/benchmark/)** | `cpp/benchmark` | Google Benchmark microbenchmark support library |
| **[CLI11](cpp/CLI11/)** | `cpp/CLI11` | Command line parser for C++11 and beyond |
| **[pybind11](cpp/pybind11/)** | `cpp/pybind11` | Seamless operability between C++11 and Python |
| **[jemalloc](cpp/jemalloc/)** | `cpp/jemalloc` | General purpose malloc implementation emphasizing fragmentation avoidance |
| **[llvm](cpp/llvm/)** | `cpp/llvm` | LLVM compiler infrastructure and intermediate representation |
| **[or-tools](cpp/or-tools/)** | `cpp/or-tools` | Google Operations Research Tools for combinatorial optimization |
| **[robin-map](cpp/robin-map/)** | `cpp/robin-map` | Fast hash map implementation using Robin Hood hashing |
| **[rttr](cpp/rttr/)** | `cpp/rttr` | Run Time Type Reflection library for C++ |
| **[cel-cpp](cpp/cel-cpp/)** | `cpp/cel-cpp` | Common Expression Language (CEL) C++ implementation |
| **[icu](cpp/icu/)** | `cpp/icu` | International Components for Unicode |
| **[utfproc](cpp/utfproc/)** | `cpp/utfproc` | Unicode normalization and UTF-8 processing |
| **[hidapi](cpp/hidapi/)** | `cpp/hidapi` | Multi-platform library for USB/Bluetooth HID communication |
| **[libuvc](cpp/libuvc/)** | `cpp/libuvc` | Cross-platform video capture library for USB video devices |
| **[libgit2](cpp/libgit2/)** | `cpp/libgit2` | Portable, pure C implementation of the Git core methods |
| **[libpng](cpp/libpng/)** | `cpp/libpng` | Official PNG reference library |
| **[zbar](cpp/zbar/)** | `cpp/zbar` | Bar code and QR code reading library |
| **[jni](cpp/jni/)** | `cpp/jni` | Java Native Interface C++ bridge |

</details>

---

## <a id="mobile-embedded-iot"></a>📱 Mobile, Embedded & IoT

Android native & on-device ML, ESP32 Wi-Fi sensing, ESPHome smart devices, Raspberry Pi Pico, and robotics mathematics.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Android Native & On-Device ML](android/)** | `android` | CameraX, Jetpack Compose, OpenGL ES 3.0, Vulkan, Mobile Image Classification, Object Detection, YOLO, and OCR. |
| **[ESP32 & Wi-Fi Sensing](esp/)** | `esp` | ESP32 Channel State Information (CSI) Wi-Fi sensing and firmware project templates. |
| **[Linux on ESP32-S3](esp32_linux.md)** | `esp32_linux.md` | Notes, toolchains, and references for running Linux on Xtensa ESP32-S3 microcontrollers. |
| **[ESPHome Smart Home](esphome/)** | `esphome` | ESPHome declarative device YAML configurations and firmware flashing scripts. |
| **[Raspberry Pi Pico (RP2040)](pico/)** | `pico` | Pico C/C++ SDK setup, GPIO blink, and LCD display driver implementation. |
| **[Robotics & Transformations](robotics/)** | `robotics` | Homogeneous coordinates, 2D/3D projective transformations, and translation/rotation matrices. |

---

## <a id="systems-devops"></a>🛠️ Systems, Infrastructure & DevOps

Operating system internals, Linux kernel, container orchestration, tunnels, reverse proxies, and observability.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Linux Kernel & Custom Distro](linux/)** | `linux` | Building custom Linux kernels and assembling minimal self-contained Linux systems. |
| **[Operating Systems & Assembly](os/)** | `os` | x86 16-bit boot sector written in assembly (NASM) and OS architectural notes. |
| **[Kubernetes & Containers](kubernetes/)** | `kubernetes` | Minikube local cluster provisioning, kubectl workflows, and Kubernetes manifests. |
| **[Elasticsearch](elasticsearch/)** | `elasticsearch` | Elasticsearch single-node Docker setup and Python search/indexing verification script. |
| **[Prometheus Monitoring](prometheus/)** | `prometheus` | Prometheus metric scraping configuration and monitoring service setup. |
| **[Cloudflare Tunnels](cloudflared/)** | `cloudflared` | Zero Trust network tunneling with cloudflared daemon. |
| **[ngrok Tunneling](ngrok/)** | `ngrok` | Secure public ingress tunneling for local development services. |
| **[Nginx Configurations](nginx/)** | `nginx` | Production-grade Nginx reverse proxy and web server example configuration files. |
| **[Nginx Docker Guide](nginx.md)** | `nginx.md` | Quick commands for launching containerized Nginx instances with mounted configs. |
| **[Jitsi Meet Video Conferencing](jitsi/)** | `jitsi` | Self-hosted Jitsi Meet deployment using Docker and Docker Compose. |

---

## <a id="security-crypto"></a>🔒 Security, Cryptography & PKI

Static application security testing (SAST), IaC auditing, SSL/TLS certificate management, and public-key cryptography.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Security Auditing & SAST](security/)** | `security` | Static code analysis with Semgrep, IaC scanning with KICS, and OWASP Dependency-Check. |
| **[Cryptography (RSA)](crypto/)** | `crypto` | Foundational notes on RSA public key cryptography and mathematical foundations. |
| **[OpenSSL & Certificates](ssl.md)** | `ssl.md` | OpenSSL commands for generating private keys, CSRs, and self-signed X.509 certificates. |

---

## <a id="web-graphics-multimedia"></a>🎨 Web, Graphics & Multimedia

Audio/video processing with FFmpeg, Flutter UI & shaders, OpenGL simulations, document manipulation, and CSS.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[FFmpeg Multimedia Guide](ffmpeg.md)** | `ffmpeg.md` | Cheatsheet for HLS (.m3u8) stream downloading, video-to-frames extraction, and audio-video multiplexing. |
| **[Flutter Custom Shaders & UI](flutter/)** | `flutter` | Flutter fragment shader experiments and next-generation interactive mobile UI designs. |
| **[OpenGL 3D Graphics](opengl/)** | `opengl` | N-body gravitational simulation rendered with hardware-accelerated OpenGL. |
| **[PDF Utilities (Stirling-PDF)](pdf/)** | `pdf` | Self-hosted Stirling-PDF Docker container setup for splitting, merging, and converting PDF documents. |
| **[CSS Tricks & Patterns](css_tricks.md)** | `css_tricks.md` | Pure CSS striped background patterns and styling snippets. |
| **[HTML Templates](html/)** | `html` | Custom standalone error pages (e.g. 50x server error). |

---

## <a id="healthcare-bioinformatics"></a>🧬 Healthcare & Bioinformatics

Computational biology, sequence alignment, HL7 FHIR clinical data exchange, and LOINC medical coding.

| Topic / Resource | Path | Description |
| :--- | :--- | :--- |
| **[Bioinformatics & Sequence Analysis](bioinformatics/)** | `bioinformatics` | Lecture notes, sequence alignment algorithms, and hands-on Jupyter notebook assignments. |
| **[HL7 FHIR Health Informatics](fhir/)** | `fhir` | HAPI FHIR JPA Starter Server configuration and RESTful clinical resource guidelines. |
| **[LOINC Medical Coding](loinc/)** | `loinc` | LOINC (Logical Observation Identifiers Names and Codes) API query client. |

---

## <a id="auto-update-script"></a>🔄 Auto-Update Script

This index is automatically maintained by [`scripts/update_index.py`](scripts/update_index.py).

Whenever you add new notes, code examples, or topic folders, regenerate `INDEX.md` by running:

```bash
# From the repository root:
python scripts/update_index.py

# Or run check mode (useful for CI/pre-commit):
python scripts/update_index.py --check
```

---

*Generated automatically by `scripts/update_index.py`.*
