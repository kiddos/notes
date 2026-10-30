# Engineering Notes & Knowledge Base

A curated personal repository of engineering notes, reference implementations, library recipes, competitive programming solutions, and machine learning experiments.

> 📖 **Browse the complete categorized directory in [INDEX.md](INDEX.md)**

---

## 🧭 Topic Categories

The repository is organized across 8 primary domains:

| Category | Description | Key Topics / Highlights |
| :--- | :--- | :--- |
| [🧠 Artificial Intelligence & ML](INDEX.md#ai-ml) | LLMs, deep learning, RL, speech & vision | [`LLM/`](LLM/) (RAG, fine-tuning, Ollama), [`jax/`](jax/) (Flax, JIT, VAE), [`RL/`](RL/) (DQN, DDPG), [`Real-ESRGAN/`](Real-ESRGAN/), [`tts/`](tts/), [`whisper/`](whisper/), [`ocr/`](ocr/), [`bpe/`](bpe/) |
| [⚡ Algorithms & CP](INDEX.md#competitive-programming) | Algorithms & competitive programming problem sets | [`algorithm/`](algorithm/) (50+ C++/Rust implementations), [`leetcode/`](leetcode/) (24 patterns & numbered problems), [`codeforces/`](codeforces/), [`atcoder/`](atcoder/), [`cses/`](cses/), [`advent-of-code/`](advent-of-code/) |
| [💻 C++ Ecosystem](INDEX.md#cpp-systems) | 80+ C++ libraries with working CMake recipes | [`cpp/`](cpp/) spanning AI runtimes (`llama.cpp`, `whisper.cpp`, `onnx`, `faiss`, `pytorch`), graphics (`SDL3`, `raylib`, `imgui`), networking (`grpc`, `curl`, `libuv`), storage (`redis`, `rocksdb`, `sqlite3`), formats & compression |
| [📱 Mobile, Embedded & IoT](INDEX.md#mobile-embedded-iot) | Android native & embedded microcontrollers | [`android/`](android/) (CameraX, Compose, Vulkan, on-device ML), [`esp/`](esp/) (ESP32 CSI Wi-Fi sensing), [`esp32_linux.md`](esp32_linux.md), [`esphome/`](esphome/), [`pico/`](pico/) (RP2040), [`robotics/`](robotics/) |
| [🛠️ Systems & DevOps](INDEX.md#systems-devops) | OS, kernel, networking & deployment | [`linux/`](linux/) (custom kernel & minimal distro), [`os/`](os/) (x86 bootloader asm), [`kubernetes/`](kubernetes/), [`elasticsearch/`](elasticsearch/), [`prometheus/`](prometheus/), [`cloudflared/`](cloudflared/), [`ngrok/`](ngrok/), [`nginx/`](nginx/) |
| [🔒 Security & Cryptography](INDEX.md#security-crypto) | Code auditing, IaC security & PKI | [`security/`](security/) (Semgrep, KICS, Dependency-Check), [`crypto/`](crypto/) (RSA), [`ssl.md`](ssl.md) (OpenSSL certificates) |
| [🎨 Web & Multimedia](INDEX.md#web-graphics-multimedia) | Audio/video processing, graphics & UI | [`ffmpeg.md`](ffmpeg.md), [`flutter/`](flutter/) (custom shaders), [`opengl/`](opengl/) (N-body simulation), [`pdf/`](pdf/) (Stirling-PDF), [`css_tricks.md`](css_tricks.md), [`html/`](html/) |
| [🧬 Healthcare & Bioinformatics](INDEX.md#healthcare-bioinformatics) | Medical standards & computational biology | [`bioinformatics/`](bioinformatics/) (sequence analysis), [`fhir/`](fhir/) (HL7 FHIR JPA server), [`loinc/`](loinc/) (terminology API) |

---

## 🗂️ Navigating the Notes

- **Topic Index**: Open [INDEX.md](INDEX.md) for a categorized table of contents with descriptions, file counts, and direct links to sub-topics and library recipes.
- **C++ Showcase**: Explore [`cpp/`](cpp/) to view working build recipes and sample code for 80+ modern C++ libraries.
- **Algorithms**: Browse [`algorithm/`](algorithm/) for self-contained algorithms in C++ and Rust (graphs, segment trees, FFT, strings, geometry, math).
- **Machine Learning**: Check [`LLM/`](LLM/) and [`jax/`](jax/) for Jupyter notebooks covering RAG, local chatbot deployment, fine-tuning, and functional deep learning.

---

## 🔄 Maintaining & Updating `INDEX.md`

An automated script is provided to scan the repository, calculate statistics, and keep [INDEX.md](INDEX.md) synchronized with new notes and directories.

### Running the Script

```bash
# Update INDEX.md from repository root
python scripts/update_index.py
# or via the root shortcut:
python update_index.py
```

### Checking for Consistency (CI / Pre-Commit)

```bash
python scripts/update_index.py --check
```

The `--check` flag verifies whether `INDEX.md` is strictly up to date and exits with code `0` on success or code `1` if regeneration is required.

### Options

```
usage: update_index.py [-h] [--repo-dir REPO_DIR] [--output OUTPUT] [--check] [--dry-run] [--quiet]

options:
  -h, --help            Show this help message and exit
  --repo-dir REPO_DIR   Root directory of the repository (default: auto-detected)
  --output OUTPUT, -o   Path to output file (default: INDEX.md at repo root)
  --check               Check if INDEX.md is up to date without modifying
  --dry-run             Print generated markdown to stdout without writing
  --quiet, -q           Suppress non-error output
```

---

## 🛠️ Environment & Tooling

- Python: `>= 3.12` (managed via `uv` or standard `python3`)
- Dependencies: configured in `pyproject.toml`
