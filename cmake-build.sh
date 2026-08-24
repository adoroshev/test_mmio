#!/bin/bash

release_dir=cmake-build/release
debug_dir=cmake-build/debug

# Каталоги для хранения release и debug
mkdir -p $release_dir
mkdir -p $debug_dir

# Сборка debug
cmake -B $debug_dir -DCMAKE_BUILD_TYPE=Debug
cmake --build $debug_dir

# Сборка release
cmake -B $release_dir -DCMAKE_BUILD_TYPE=Release
cmake --build $release_dir

# Установка release в систему
sudo cmake --install $release_dir
