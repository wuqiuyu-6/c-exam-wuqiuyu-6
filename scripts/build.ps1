# Build script for PowerShell (Windows)

Write-Host "=== C Assignment Template Build ===" -ForegroundColor Green
Write-Host "Configuring..." -ForegroundColor Yellow

cmake -B build
cmake --build build --config Release

Write-Host ""
Write-Host "=== Build Complete ===" -ForegroundColor Green
Write-Host "Executable: build\Release\main.exe" -ForegroundColor Green
