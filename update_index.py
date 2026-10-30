#!/usr/bin/env python3
"""
Convenience entrypoint to run scripts/update_index.py.
"""
import sys
from pathlib import Path

# Add scripts directory to module path and invoke main
scripts_dir = Path(__file__).resolve().parent / "scripts"
sys.path.insert(0, str(scripts_dir))

from update_index import main

if __name__ == "__main__":
    main()
