#!/usr/bin/env bash
set -euo pipefail
ROOT=$(cd "$(dirname "$0")" && pwd)
for d in "$ROOT"/problems/*; do
  if [[ -f "$d/CMakeLists.txt" ]]; then
    echo "== $(basename "$d") (C++) =="
    cmake -S "$d" -B "$d/.build" >/dev/null
    cmake --build "$d/.build" -j2 >/dev/null
    (cd "$d" && "$d/.build/tests")
  elif compgen -G "$d/test_*.py" >/dev/null; then
    echo "== $(basename "$d") (Python) =="
    (cd "$d" && python3 -m unittest -q)
  fi
done
