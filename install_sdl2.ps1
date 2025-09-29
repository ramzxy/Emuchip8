# PowerShell script to install SDL2 on Windows
Write-Host "Installing SDL2 for Windows..." -ForegroundColor Green

# Check if vcpkg is available
if (Get-Command vcpkg -ErrorAction SilentlyContinue) {
    Write-Host "Using vcpkg to install SDL2..." -ForegroundColor Yellow
    vcpkg install sdl2:x64-windows
    vcpkg integrate install
    Write-Host "SDL2 installed via vcpkg and integrated with CMake!" -ForegroundColor Green
}

# Try to find existing vcpkg installation
else {
    Write-Host "Looking for existing vcpkg installation..." -ForegroundColor Yellow
    
    # Common vcpkg locations
    $vcpkgPaths = @(
        "$env:VCPKG_ROOT",
        "$env:ProgramFiles\vcpkg",
        "$env:ProgramFiles(x86)\vcpkg",
        "C:\vcpkg",
        "C:\tools\vcpkg",
        "C:\dev\vcpkg"
    )
    
    $vcpkgFound = $false
    foreach ($path in $vcpkgPaths) {
        if ($path -and (Test-Path "$path\vcpkg.exe")) {
            Write-Host "Found vcpkg at: $path" -ForegroundColor Green
            & "$path\vcpkg.exe" install sdl2:x64-windows
            & "$path\vcpkg.exe" integrate install
            $vcpkgFound = $true
            break
        }
    }
    
    if (-not $vcpkgFound) {
        Write-Host "vcpkg not found. Please either:" -ForegroundColor Red
        Write-Host "1. Set VCPKG_ROOT environment variable to your vcpkg installation" -ForegroundColor White
        Write-Host "2. Add vcpkg to your PATH" -ForegroundColor White
        Write-Host "3. Or manually install SDL2 from: https://www.libsdl.org/download-2.0.php" -ForegroundColor White
    }
}
