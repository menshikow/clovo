# 🔐 Passcheck 
<div align="center">

[![C](https://img.shields.io/badge/C-17-blue.svg?style=for-the-badge)](https://en.wikipedia.org/wiki/C17_(C_standard_revision))
[![CMake](https://img.shields.io/badge/CMake-3.15+-064F8C.svg?style=for-the-badge&logo=cmake)](https://cmake.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg?style=for-the-badge)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey.svg?style=for-the-badge)]()

• [Installation](#build) • [Usage](#usage) • [Examples](#example)

</div>

## Build
```bash
cmake -B build && cmake --build build
```

## Usage
```bash
# Check a password
./build/password_checker "mypassword123"

# Generate a password
./build/password_checker --generate 16
```

## What It Checks

- Length (at least 8 characters recommended)
- Lowercase letters
- Uppercase letters  
- Numbers
- Symbols

Scores passwords from 0-100 and rates them as:
- **VERY WEAK** (0-39)
- **WEAK** (40-59)
- **MODERATE** (60-79)
- **STRONG** (80-100)

## Example
```bash
$ ./build/password_checker "hello"

=== PASSWORD ANALYSIS ===
Length: 5 characters
Contains lowercase: ✓
Contains uppercase: ✗
Contains digits: ✗
Contains symbols: ✗

Strength Score: 15/100
Rating: VERY WEAK
```

## Running Tests
```bash
./build/test_analyzer
./build/test_generator
```

## Requirements

- C compiler (gcc or clang)
- CMake 3.15+

## License

MIT
