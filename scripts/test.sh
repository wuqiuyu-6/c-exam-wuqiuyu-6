#!/bin/bash

# Test script for C Assignment Template

set -e

echo "=== C Assignment Template Tests ==="
echo ""

# Run CMake tests
ctest --test-dir build --output-on-failure

echo ""
echo "=== All Tests Passed ==="
