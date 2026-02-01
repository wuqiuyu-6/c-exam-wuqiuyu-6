#!/bin/bash

# Build script for Linux/Mac

set -e

echo "=== C Assignment Template Build ==="

cmake -B build
cmake --build build --config Release

echo ""
echo "=== Build Complete ==="
echo "Executable: $BUILD_DIR/main"
