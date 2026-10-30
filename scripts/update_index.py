#!/usr/bin/env python3
"""
scripts/update_index.py

Automatically generates and updates INDEX.md for the notes repository.
Scans all note categories, directories, notebooks, and standalone documents,
grouping them into clean, logical sections with direct relative links.

Usage:
    python scripts/update_index.py
    python scripts/update_index.py --check
    python scripts/update_index.py --dry-run
"""

import argparse
import os
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

# Base directories or files to ignore during indexing
IGNORE_NAMES = {
    '.git', '.cache', '.venv', '__pycache__', '.pytest_cache',
    '.clang-format', '.gitignore', '.python-version',
    'uv.lock', 'pyproject.toml', 'requirements.txt',
    'INDEX.md', 'README.md', 'scripts', 'update_index.py'
}

# Predefined categories and their metadata
CATEGORIES = [
    {
        "id": "ai-ml",
        "title": "Artificial Intelligence, Machine Learning & NLP",
        "icon": "🧠",
        "description": "Large Language Models, deep learning frameworks (JAX/Flax), reinforcement learning, speech, vision, and AI tooling.",
        "items": [
            {
                "path": "LLM",
                "name": "Large Language Models (LLM)",
                "desc": "Local LLM inference, RAG (PyMuPDF & Llama 3.2), fine-tuning, DPO, Vector DBs (Milvus, Chroma), Ollama tool calling, and OpenRouter integration."
            },
            {
                "path": "jax",
                "name": "JAX & Flax Deep Learning",
                "desc": "Functional ML with JAX: automatic differentiation, JIT compilation, VMAP vectorization, Pytrees, VAE, Flax CNNs (MNIST, CIFAR-10), and Seq2Seq."
            },
            {
                "path": "RL",
                "name": "Reinforcement Learning",
                "desc": "PyTorch implementations of Deep Q-Networks (DQN), Deep Deterministic Policy Gradient (DDPG), and Actor-Critic (A2C) architectures."
            },
            {
                "path": "Real-ESRGAN",
                "name": "Real-ESRGAN (Super-Resolution)",
                "desc": "Portable ncnn-Vulkan AI upscaling for images and videos with FFmpeg frame extraction and video reassembly."
            },
            {
                "path": "tts",
                "name": "Text-to-Speech (TTS)",
                "desc": "State-of-the-art TTS model experiments and scripts: Chatterbox, Fish Audio, Kokoro, and Zonos."
            },
            {
                "path": "whisper",
                "name": "Whisper Speech Recognition",
                "desc": "OpenAI Whisper automatic speech recognition (ASR) setup, audio transcription, and CLI usage."
            },
            {
                "path": "ocr",
                "name": "Optical Character Recognition (OCR)",
                "desc": "Document parsing and text detection scripts with sample image test suites."
            },
            {
                "path": "bpe",
                "name": "Byte-Pair Encoding (BPE)",
                "desc": "C++ re-implementation of Hugging Face's Byte-Pair Encoding tokenizer."
            },
            {
                "path": "adk",
                "name": "Agent Development Kit (ADK)",
                "desc": "Gemini Flash tool-calling and multi-tool autonomous agent example."
            },
            {
                "path": "huggingface-space",
                "name": "Hugging Face Spaces",
                "desc": "Recipes and configurations for deploying AI services (such as llama-server) to Hugging Face Spaces."
            },
            {
                "path": "papers",
                "name": "Research Papers Notes",
                "desc": "Summaries of landmark papers including 'Deep Double Descent: Where Bigger Models and More Data Hurt'."
            },
            {
                "path": "IR",
                "name": "Information Retrieval & SQLglot",
                "desc": "SQL AST parsing, optimization, and cross-dialect transpilation with SQLGlot."
            }
        ]
    },
    {
        "id": "competitive-programming",
        "title": "Algorithms & Competitive Programming",
        "icon": "⚡",
        "description": "50+ classic algorithms & data structures, problem sets from LeetCode, Codeforces, AtCoder, CSES, and Advent of Code.",
        "items": [
            {
                "path": "algorithm",
                "name": "Classical Algorithms & Data Structures",
                "desc": "58 reference implementations in C++ & Rust covering Graph theory, Trees, DP, String processing, Geometry, and Number Theory."
            },
            {
                "path": "leetcode",
                "name": "LeetCode Solutions",
                "desc": "Solutions categorized by 24 algorithmic patterns (DP, BFS/DFS, Binary Search, Trees, Graphs, Trie, etc.) and numbered problem directories."
            },
            {
                "path": "codeforces",
                "name": "Codeforces Problem Sets",
                "desc": "Competitive programming problem solutions indexed across 24 difficulty ranges (1~99 to 2200~2299)."
            },
            {
                "path": "atcoder",
                "name": "AtCoder Solutions",
                "desc": "Solutions for AtCoder Beginner Contests (ABC 424, 468, 469, 470, 471, 472)."
            },
            {
                "path": "cses",
                "name": "CSES Problem Set",
                "desc": "Solutions to the Finnish CSES problem set: Introductory, DP, Graph Algorithms, Range Queries, Tree Algorithms, and Mathematics."
            },
            {
                "path": "advent-of-code",
                "name": "Advent of Code",
                "desc": "Advent of Code puzzles and solutions (2024)."
            }
        ]
    },
    {
        "id": "cpp-systems",
        "title": "C++ Ecosystem & Systems Libraries",
        "icon": "💻",
        "description": "80+ C++ libraries and frameworks with ready-to-run examples, CMake recipes, and build configurations.",
        "items": [
            {
                "path": "cpp",
                "name": "C++ Libraries Showcase (80+ Libraries)",
                "desc": "Curated working examples spanning AI runtimes, Graphics, Networking, Databases, Serialization, and Utilities."
            }
        ]
    },
    {
        "id": "mobile-embedded-iot",
        "title": "Mobile, Embedded & IoT",
        "icon": "📱",
        "description": "Android native & on-device ML, ESP32 Wi-Fi sensing, ESPHome smart devices, Raspberry Pi Pico, and robotics mathematics.",
        "items": [
            {
                "path": "android",
                "name": "Android Native & On-Device ML",
                "desc": "CameraX, Jetpack Compose, OpenGL ES 3.0, Vulkan, Mobile Image Classification, Object Detection, YOLO, and OCR."
            },
            {
                "path": "esp",
                "name": "ESP32 & Wi-Fi Sensing",
                "desc": "ESP32 Channel State Information (CSI) Wi-Fi sensing and firmware project templates."
            },
            {
                "path": "esp32_linux.md",
                "name": "Linux on ESP32-S3",
                "desc": "Notes, toolchains, and references for running Linux on Xtensa ESP32-S3 microcontrollers."
            },
            {
                "path": "esphome",
                "name": "ESPHome Smart Home",
                "desc": "ESPHome declarative device YAML configurations and firmware flashing scripts."
            },
            {
                "path": "pico",
                "name": "Raspberry Pi Pico (RP2040)",
                "desc": "Pico C/C++ SDK setup, GPIO blink, and LCD display driver implementation."
            },
            {
                "path": "robotics",
                "name": "Robotics & Transformations",
                "desc": "Homogeneous coordinates, 2D/3D projective transformations, and translation/rotation matrices."
            }
        ]
    },
    {
        "id": "systems-devops",
        "title": "Systems, Infrastructure & DevOps",
        "icon": "🛠️",
        "description": "Operating system internals, Linux kernel, container orchestration, tunnels, reverse proxies, and observability.",
        "items": [
            {
                "path": "linux",
                "name": "Linux Kernel & Custom Distro",
                "desc": "Building custom Linux kernels and assembling minimal self-contained Linux systems."
            },
            {
                "path": "os",
                "name": "Operating Systems & Assembly",
                "desc": "x86 16-bit boot sector written in assembly (NASM) and OS architectural notes."
            },
            {
                "path": "kubernetes",
                "name": "Kubernetes & Containers",
                "desc": "Minikube local cluster provisioning, kubectl workflows, and Kubernetes manifests."
            },
            {
                "path": "elasticsearch",
                "name": "Elasticsearch",
                "desc": "Elasticsearch single-node Docker setup and Python search/indexing verification script."
            },
            {
                "path": "prometheus",
                "name": "Prometheus Monitoring",
                "desc": "Prometheus metric scraping configuration and monitoring service setup."
            },
            {
                "path": "cloudflared",
                "name": "Cloudflare Tunnels",
                "desc": "Zero Trust network tunneling with cloudflared daemon."
            },
            {
                "path": "ngrok",
                "name": "ngrok Tunneling",
                "desc": "Secure public ingress tunneling for local development services."
            },
            {
                "path": "nginx",
                "name": "Nginx Configurations",
                "desc": "Production-grade Nginx reverse proxy and web server example configuration files."
            },
            {
                "path": "nginx.md",
                "name": "Nginx Docker Guide",
                "desc": "Quick commands for launching containerized Nginx instances with mounted configs."
            },
            {
                "path": "jitsi",
                "name": "Jitsi Meet Video Conferencing",
                "desc": "Self-hosted Jitsi Meet deployment using Docker and Docker Compose."
            }
        ]
    },
    {
        "id": "security-crypto",
        "title": "Security, Cryptography & PKI",
        "icon": "🔒",
        "description": "Static application security testing (SAST), IaC auditing, SSL/TLS certificate management, and public-key cryptography.",
        "items": [
            {
                "path": "security",
                "name": "Security Auditing & SAST",
                "desc": "Static code analysis with Semgrep, IaC scanning with KICS, and OWASP Dependency-Check."
            },
            {
                "path": "crypto",
                "name": "Cryptography (RSA)",
                "desc": "Foundational notes on RSA public key cryptography and mathematical foundations."
            },
            {
                "path": "ssl.md",
                "name": "OpenSSL & Certificates",
                "desc": "OpenSSL commands for generating private keys, CSRs, and self-signed X.509 certificates."
            }
        ]
    },
    {
        "id": "web-graphics-multimedia",
        "title": "Web, Graphics & Multimedia",
        "icon": "🎨",
        "description": "Audio/video processing with FFmpeg, Flutter UI & shaders, OpenGL simulations, document manipulation, and CSS.",
        "items": [
            {
                "path": "ffmpeg.md",
                "name": "FFmpeg Multimedia Guide",
                "desc": "Cheatsheet for HLS (.m3u8) stream downloading, video-to-frames extraction, and audio-video multiplexing."
            },
            {
                "path": "flutter",
                "name": "Flutter Custom Shaders & UI",
                "desc": "Flutter fragment shader experiments and next-generation interactive mobile UI designs."
            },
            {
                "path": "opengl",
                "name": "OpenGL 3D Graphics",
                "desc": "N-body gravitational simulation rendered with hardware-accelerated OpenGL."
            },
            {
                "path": "pdf",
                "name": "PDF Utilities (Stirling-PDF)",
                "desc": "Self-hosted Stirling-PDF Docker container setup for splitting, merging, and converting PDF documents."
            },
            {
                "path": "css_tricks.md",
                "name": "CSS Tricks & Patterns",
                "desc": "Pure CSS striped background patterns and styling snippets."
            },
            {
                "path": "html",
                "name": "HTML Templates",
                "desc": "Custom standalone error pages (e.g. 50x server error)."
            }
        ]
    },
    {
        "id": "healthcare-bioinformatics",
        "title": "Healthcare & Bioinformatics",
        "icon": "🧬",
        "description": "Computational biology, sequence alignment, HL7 FHIR clinical data exchange, and LOINC medical coding.",
        "items": [
            {
                "path": "bioinformatics",
                "name": "Bioinformatics & Sequence Analysis",
                "desc": "Lecture notes, sequence alignment algorithms, and hands-on Jupyter notebook assignments."
            },
            {
                "path": "fhir",
                "name": "HL7 FHIR Health Informatics",
                "desc": "HAPI FHIR JPA Starter Server configuration and RESTful clinical resource guidelines."
            },
            {
                "path": "loinc",
                "name": "LOINC Medical Coding",
                "desc": "LOINC (Logical Observation Identifiers Names and Codes) API query client."
            }
        ]
    }
]


def find_repo_root() -> Path:
    """Find repository root by looking for .git or pyproject.toml."""
    current = Path(__file__).resolve().parent
    while current != current.parent:
        if (current / '.git').exists() or (current / 'pyproject.toml').exists():
            return current
        current = current.parent
    return Path.cwd()


def get_repo_stats(repo_root: Path) -> Dict[str, int]:
    """Calculate key repository statistics."""
    stats = {
        "categories": len(CATEGORIES),
        "cpp_libs": 0,
        "algorithms": 0,
        "leetcode_topics": 0,
        "leetcode_problems": 0,
        "notebooks": 0,
        "markdown_files": 0
    }

    # C++ libraries
    cpp_dir = repo_root / "cpp"
    if cpp_dir.is_dir():
        stats["cpp_libs"] = len([d for d in cpp_dir.iterdir() if d.is_dir() and not d.name.startswith('.')])

    # Algorithms
    algo_dir = repo_root / "algorithm"
    if algo_dir.is_dir():
        stats["algorithms"] = len([f for f in algo_dir.iterdir() if f.is_file() and not f.name.startswith('.') and f.suffix in ('.cc', '.cpp', '.rs')])

    # Leetcode
    lc_dir = repo_root / "leetcode"
    if lc_dir.is_dir():
        for item in lc_dir.iterdir():
            if item.is_dir() and not item.name.startswith('.'):
                if item.name.isdigit():
                    stats["leetcode_problems"] += 1
                else:
                    stats["leetcode_topics"] += 1

    # Notebooks & Markdown
    for root, dirs, files in os.walk(repo_root):
        dirs[:] = [d for d in dirs if not d.startswith('.') and d not in ('.venv', '.cache', '__pycache__')]
        for f in files:
            if f.endswith('.ipynb'):
                stats["notebooks"] += 1
            elif f.endswith('.md'):
                stats["markdown_files"] += 1

    return stats


def get_cpp_libraries_grouped(repo_root: Path) -> Dict[str, List[Tuple[str, str]]]:
    """Group C++ libraries by category for detailed index view."""
    cpp_dir = repo_root / "cpp"
    if not cpp_dir.is_dir():
        return {}

    subdirs = sorted([d.name for d in cpp_dir.iterdir() if d.is_dir() and not d.name.startswith('.')])

    categories = {
        "AI, Machine Learning & Vision": [
            ("llama.cpp", "LLM inference runtime in pure C/C++"),
            ("whisper.cpp", "High-performance inference of OpenAI Whisper model"),
            ("onnx", "Open Neural Network Exchange runtime and model parsing"),
            ("executorch", "PyTorch on-device AI runtime for edge devices"),
            ("faiss", "Library for efficient similarity search and dense vector clustering"),
            ("pytorch", "LibTorch C++ API for PyTorch model execution"),
            ("tesseract", "Tesseract OCR engine integration"),
            ("opencv", "Computer vision, image processing, and video analysis"),
            ("sentencepiece", "Unsupervised text tokenizer and detokenizer"),
            ("cuda", "NVIDIA CUDA GPU parallel computing and acceleration")
        ],
        "Computer Graphics, GUI & Multimedia": [
            ("SDL3", "Simple DirectMedia Layer 3 for audio, keyboard, mouse, and display"),
            ("raylib", "Simple and easy-to-use library to enjoy videogames programming"),
            ("SFML", "Simple and Fast Multimedia Library for 2D graphics and audio"),
            ("glfw", "Multi-platform library for OpenGL, OpenGL ES, Vulkan development"),
            ("qt", "Cross-platform C++ GUI application framework and widgets"),
            ("imgui", "Dear ImGui: bloat-free immediate mode graphical user interface"),
            ("imtui", "Immediate Mode Terminal User Interface based on ncurses"),
            ("ncurses", "Terminal handling library for text-based user interfaces"),
            ("freetype", "Font engine capable of rendering true-type font glyphs"),
            ("ImageMagick", "Image reading, writing, and manipulation library"),
            ("stb", "Single-file public domain libraries for images, fonts, audio"),
            ("g2o", "General Framework for Graph Optimization in SLAM and robotics")
        ],
        "Networking, RPC & Web": [
            ("grpc", "High performance, open-source universal RPC framework"),
            ("cpr", "C++ Requests: modern C++ HTTP library inspired by Python Requests"),
            ("curl", "Multiprotocol file transfer library (libcurl)"),
            ("libuv", "Multi-platform asynchronous I/O library (Node.js event loop)"),
            ("libevent", "Asynchronous event notification library"),
            ("workflow", "C++ parallel computing and asynchronous networking engine"),
            ("tcp", "Raw TCP socket communication implementation")
        ],
        "Databases, Key-Value & Storage Engines": [
            ("redis", "Redis client integration in C++"),
            ("rocksdb", "Persistent high-performance key-value store for fast storage"),
            ("leveldb", "Fast key-value storage library written at Google"),
            ("sqlite3", "Self-contained, serverless, zero-configuration SQL database"),
            ("lmdb", "Lightning Memory-Mapped Database"),
            ("mongodb", "MongoDB C++ driver connection and query examples"),
            ("db2", "IBM DB2 database connectivity")
        ],
        "Serialization, Formats & Document Processing": [
            ("protobuf", "Google Protocol Buffers for structured data serialization"),
            ("json", "Nlohmann JSON: JSON for Modern C++"),
            ("jsoncpp", "C++ library that allows manipulating JSON values"),
            ("json-c", "JSON implementation in C"),
            ("yaml-cpp", "YAML parser and emitter for C++"),
            ("pugixml", "Light-weight, simple and fast XML parser with XPath support"),
            ("libexpat", "Fast streaming XML parser library"),
            ("cereal", "Header-only C++11 serialization library"),
            ("OpenXLSX", "C++ library for reading and writing Microsoft Excel (.xlsx) files"),
            ("PDF-Writer", "Fast C++ library for creating, modifying, and parsing PDF files"),
            ("poppler", "PDF rendering library based on xpdf codebase"),
            ("dcmtk", "DICOM medical image communication and file parsing")
        ],
        "Compression, Cryptography & Security": [
            ("zlib", "Massively spiffy yet delicately unobtrusive compression library"),
            ("zstd", "Zstandard - Fast real-time compression algorithm"),
            ("LZMA", "Lempel-Ziv-Markov chain compression algorithm"),
            ("libzip", "C library for reading, creating, and modifying zip archives"),
            ("libarchive", "Multi-format archive and compression library"),
            ("openssl", "TLS/SSL and general purpose cryptography library"),
            ("libsodium", "Modern, easy-to-use crypto library for encryption/decryption"),
            ("clamav", "Antivirus engine toolkit integration")
        ],
        "Core Utilities, Algorithms & Benchmarking": [
            ("abseil-cpp", "Google Abseil common libraries (strings, containers, flags)"),
            ("boost", "Boost C++ libraries collection"),
            ("eigen", "Template library for linear algebra, matrices, and vectors"),
            ("fmt", "Modern formatting library formatted with Python-like syntax"),
            ("spdlog", "Fast C++ logging library"),
            ("gflags", "Commandline flags processing library"),
            ("gtest", "Google Test C++ testing framework"),
            ("benchmark", "Google Benchmark microbenchmark support library"),
            ("CLI11", "Command line parser for C++11 and beyond"),
            ("pybind11", "Seamless operability between C++11 and Python"),
            ("jemalloc", "General purpose malloc implementation emphasizing fragmentation avoidance"),
            ("llvm", "LLVM compiler infrastructure and intermediate representation"),
            ("or-tools", "Google Operations Research Tools for combinatorial optimization"),
            ("robin-map", "Fast hash map implementation using Robin Hood hashing"),
            ("rttr", "Run Time Type Reflection library for C++"),
            ("cel-cpp", "Common Expression Language (CEL) C++ implementation"),
            ("icu", "International Components for Unicode"),
            ("utfproc", "Unicode normalization and UTF-8 processing"),
            ("hidapi", "Multi-platform library for USB/Bluetooth HID communication"),
            ("libuvc", "Cross-platform video capture library for USB video devices"),
            ("libgit2", "Portable, pure C implementation of the Git core methods"),
            ("libpng", "Official PNG reference library"),
            ("zbar", "Bar code and QR code reading library"),
            ("jni", "Java Native Interface C++ bridge")
        ]
    }

    known_libs = set()
    for libs in categories.values():
        for name, _ in libs:
            known_libs.add(name)

    remaining = [d for d in subdirs if d not in known_libs]
    if remaining:
        categories["Additional C++ Libraries"] = [
            (d, f"C++ library and example in cpp/{d}") for d in remaining
        ]

    return categories


def find_unindexed_items(repo_root: Path) -> List[Tuple[str, str]]:
    """Detect top-level directories or files not yet indexed in CATEGORIES."""
    indexed_paths: Set[str] = set()
    for cat in CATEGORIES:
        for item in cat["items"]:
            indexed_paths.add(item["path"])

    unindexed = []
    for entry in repo_root.iterdir():
        if entry.name.startswith('.') or entry.name in IGNORE_NAMES:
            continue
        rel = entry.name
        if rel not in indexed_paths:
            kind = "Directory" if entry.is_dir() else "File"
            unindexed.append((rel, kind))

    return sorted(unindexed)


def generate_index_markdown(repo_root: Path) -> str:
    """Generate the full INDEX.md markdown text."""
    stats = get_repo_stats(repo_root)
    cpp_groups = get_cpp_libraries_grouped(repo_root)
    unindexed = find_unindexed_items(repo_root)

    lines: List[str] = []

    # Title & Header
    lines.append("# Master Knowledge Index")
    lines.append("")
    lines.append("> Comprehensive catalog and topic index for engineering notes, algorithms, library recipes, and machine learning experiments.")
    lines.append("")

    # Stats Overview
    lines.append("## Overview & Statistics")
    lines.append("")
    lines.append("| Metric | Count |")
    lines.append("| :--- | :--- |")
    lines.append(f"| **Knowledge Categories** | {stats['categories']} |")
    lines.append(f"| **C++ Showcase Libraries** | {stats['cpp_libs']} |")
    lines.append(f"| **Algorithms & Data Structures** | {stats['algorithms']} |")
    lines.append(f"| **LeetCode Categories & Problems** | {stats['leetcode_topics']} topic categories, {stats['leetcode_problems']} problem folders |")
    lines.append(f"| **Jupyter Notebooks** | {stats['notebooks']} |")
    lines.append(f"| **Markdown Documents** | {stats['markdown_files']} |")
    lines.append("")

    # Table of Contents
    lines.append("## Table of Contents")
    lines.append("")
    for cat in CATEGORIES:
        lines.append(f"- [{cat['icon']} {cat['title']}](#{cat['id']})")
    if unindexed:
        lines.append("- [📂 Other Topics & Notes](#other-topics)")
    lines.append("- [🔄 Auto-Update Script](#auto-update-script)")
    lines.append("")
    lines.append("---")
    lines.append("")

    # Categories
    for cat in CATEGORIES:
        lines.append(f"## <a id=\"{cat['id']}\"></a>{cat['icon']} {cat['title']}")
        lines.append("")
        lines.append(cat["description"])
        lines.append("")
        lines.append("| Topic / Resource | Path | Description |")
        lines.append("| :--- | :--- | :--- |")

        for item in cat["items"]:
            path_str = item["path"]
            target_path = repo_root / path_str
            link_target = path_str
            # Add trailing slash if directory for clean markdown links
            if target_path.is_dir() and not link_target.endswith('/'):
                link_target += "/"

            lines.append(f"| **[{item['name']}]({link_target})** | `{path_str}` | {item['desc']} |")

        lines.append("")

        # Special deep dive for C++ libraries
        if cat["id"] == "cpp-systems" and cpp_groups:
            lines.append("<details>")
            lines.append(f"<summary><b>View Breakdown of all {stats['cpp_libs']} C++ Libraries by Domain</b></summary>")
            lines.append("")
            for domain, libs in cpp_groups.items():
                lines.append(f"#### {domain}")
                lines.append("")
                lines.append("| Library | Path | Focus / Description |")
                lines.append("| :--- | :--- | :--- |")
                for lib_name, lib_desc in libs:
                    lib_path = f"cpp/{lib_name}/"
                    lines.append(f"| **[{lib_name}]({lib_path})** | `cpp/{lib_name}` | {lib_desc} |")
                lines.append("")
            lines.append("</details>")
            lines.append("")

        # Special deep dive for Algorithms
        if cat["id"] == "competitive-programming":
            algo_dir = repo_root / "algorithm"
            if algo_dir.is_dir():
                algo_files = sorted([f.name for f in algo_dir.iterdir() if f.is_file() and not f.name.startswith('.') and f.suffix in ('.cc', '.cpp', '.rs')])
                lines.append("<details>")
                lines.append(f"<summary><b>View Full List of {len(algo_files)} Classical Algorithm Implementations</b></summary>")
                lines.append("")
                lines.append("| Algorithm File | Path |")
                lines.append("| :--- | :--- |")
                for f in algo_files:
                    title = f.replace('.cc', '').replace('.cpp', '').replace('.rs', '').replace('_', ' ').title()
                    lines.append(f"| **[{title}](algorithm/{f})** | `algorithm/{f}` |")
                lines.append("")
                lines.append("</details>")
                lines.append("")

        lines.append("---")
        lines.append("")

    # If any new, unindexed files or directories were discovered
    if unindexed:
        lines.append("## <a id=\"other-topics\"></a>📂 Other Topics & Notes")
        lines.append("")
        lines.append("Newly discovered notes and directories pending explicit categorization:")
        lines.append("")
        lines.append("| Name | Type | Link |")
        lines.append("| :--- | :--- | :--- |")
        for name, kind in unindexed:
            link = f"{name}/" if kind == "Directory" else name
            lines.append(f"| **{name}** | {kind} | [{name}]({link}) |")
        lines.append("")
        lines.append("---")
        lines.append("")

    # Script Maintenance section
    lines.append("## <a id=\"auto-update-script\"></a>🔄 Auto-Update Script")
    lines.append("")
    lines.append("This index is automatically maintained by [`scripts/update_index.py`](scripts/update_index.py).")
    lines.append("")
    lines.append("Whenever you add new notes, code examples, or topic folders, regenerate `INDEX.md` by running:")
    lines.append("")
    lines.append("```bash")
    lines.append("# From the repository root:")
    lines.append("python scripts/update_index.py")
    lines.append("")
    lines.append("# Or run check mode (useful for CI/pre-commit):")
    lines.append("python scripts/update_index.py --check")
    lines.append("```")
    lines.append("")
    lines.append("---")
    lines.append("")
    lines.append("*Generated automatically by `scripts/update_index.py`.*")
    lines.append("")

    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Generate and update repository INDEX.md")
    parser.add_argument("--repo-dir", type=str, default=None, help="Root directory of the repository")
    parser.add_argument("--output", "-o", type=str, default=None, help="Path to output INDEX.md")
    parser.add_argument("--check", action="store_true", help="Check if INDEX.md is up to date without modifying")
    parser.add_argument("--dry-run", action="store_true", help="Print generated markdown to stdout")
    parser.add_argument("--quiet", "-q", action="store_true", help="Quiet mode, suppress normal log messages")
    args = parser.parse_args()

    repo_root = Path(args.repo_dir).resolve() if args.repo_dir else find_repo_root()
    output_path = Path(args.output).resolve() if args.output else repo_root / "INDEX.md"

    if not repo_root.exists() or not repo_root.is_dir():
        print(f"Error: Repository root '{repo_root}' does not exist.", file=sys.stderr)
        sys.exit(1)

    generated_md = generate_index_markdown(repo_root)

    if args.dry_run:
        print(generated_md)
        return

    if args.check:
        if not output_path.exists():
            print(f"[CHECK FAILED] {output_path} does not exist. Run 'python scripts/update_index.py' to generate.", file=sys.stderr)
            sys.exit(1)
        existing_md = output_path.read_text(encoding="utf-8")
        if existing_md != generated_md:
            print(f"[CHECK FAILED] {output_path} is out of date. Run 'python scripts/update_index.py' to update.", file=sys.stderr)
            sys.exit(1)
        if not args.quiet:
            print(f"[CHECK PASSED] {output_path} is completely up to date.")
        return

    output_path.write_text(generated_md, encoding="utf-8")
    if not args.quiet:
        print(f"[SUCCESS] Successfully updated {output_path.relative_to(repo_root)}")


if __name__ == "__main__":
    main()
