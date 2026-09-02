# File encrypting tool

<p align="left"> <img src="https://badgen.net/badge/icon/Windows/4E4E4E?icon=windows&label=&labelColor=4E4E4E" alt="Windows"> <img src="https://badgen.net/badge/icon/Linux/4E4E4E?icon=linux&label=&labelColor=4E4E4E" alt="Linux"> <img src="https://badgen.net/badge/icon/macOS/4E4E4E?icon=apple&label=&labelColor=4E4E4E" alt="macOS"> </p>

<p> <img src="https://img.shields.io/badge/language-C++-00599C?logo=c%2B%2B" alt="C++"> <img src="https://img.shields.io/badge/build-CMake-3eae2b?logo=cmake&logoColor=white" alt="CMake"> <img src="https://img.shields.io/badge/license-MIT-green" alt="License: MIT"> </p>

File encryption tool written in C++23 using [libsodium](https://github.com/jedisct1/libsodium).

## INFO 
This branch implements a stream‑based (chunked) file encryption/decryption approach.
Instead of loading the entire file into RAM, the program reads and processes the file in fixed‑size segments (chunks). This makes it suitable for handling large files that would otherwise exceed available memory.

## Status

> **Not yet functional**  
> The encryption logic is still under development and does not currently produce correct output.

## Requirements

* C++23 compatible compiler
* CMake 3.5 or higher
* libsodium
* Git (optional, for cloning)

## Build

### 1. Clone the repository

```bash
git clone https://github.com/dixe1/file-encryptor
cd file-encryptor
```

### 2. Install Dependencies

Make sure `libsodium` and `pkg-config` are installed and available on your system.

### 3. Build the Project

```bash
cmake -B build
cmake --build build
```

The project uses CMake to build both the `core` library and the `app` executable.


## License

This project is licensed under the MIT License.
