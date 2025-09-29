#!/bin/bash
# Shell script to install SDL2 on Linux/macOS

echo "Installing SDL2..."

# Detect OS
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    if command -v apt-get &> /dev/null; then
        echo "Using apt to install SDL2..."
        sudo apt-get update
        sudo apt-get install -y libsdl2-dev
    elif command -v yum &> /dev/null; then
        echo "Using yum to install SDL2..."
        sudo yum install -y SDL2-devel
    elif command -v dnf &> /dev/null; then
        echo "Using dnf to install SDL2..."
        sudo dnf install -y SDL2-devel
    elif command -v pacman &> /dev/null; then
        echo "Using pacman to install SDL2..."
        sudo pacman -S sdl2
    else
        echo "No supported package manager found. Please install SDL2 manually."
        exit 1
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    if command -v brew &> /dev/null; then
        echo "Using Homebrew to install SDL2..."
        brew install sdl2
    else
        echo "Homebrew not found. Please install Homebrew first or install SDL2 manually."
        exit 1
    fi
else
    echo "Unsupported OS: $OSTYPE"
    exit 1
fi

echo "SDL2 installation completed!"

