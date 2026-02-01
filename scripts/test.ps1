# Test script for C Assignment Template (PowerShell)

Write-Host "=== C Assignment Template Tests ===" -ForegroundColor Green
Write-Host ""

# Run CMake tests
cmake --build build --target test

Write-Host ""
Write-Host "=== All Tests Passed ===" -ForegroundColor Green
