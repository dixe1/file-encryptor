# File encrypting tool

<p align="left"> <img src="https://badgen.net/badge/icon/Windows/4E4E4E?icon=windows&label=&labelColor=4E4E4E" alt="Windows"> <img src="https://badgen.net/badge/icon/Linux/4E4E4E?icon=linux&label=&labelColor=4E4E4E" alt="Linux"> <img src="https://badgen.net/badge/icon/macOS/4E4E4E?icon=apple&label=&labelColor=4E4E4E" alt="macOS"> </p>

<p> <img src="https://img.shields.io/badge/language-C++-00599C?logo=c%2B%2B" alt="C++"> <img src="https://img.shields.io/badge/build-CMake-3eae2b?logo=cmake&logoColor=white" alt="CMake"> <img src="https://img.shields.io/badge/license-MIT-green" alt="License: MIT"> </p>

File encryption tool written in C++23 using [libsodium](https://github.com/jedisct1/libsodium).

The project is split into two main parts:

* `core` — cryptographic logic and encrypted file format
* `app` — command-line application used to encrypt and decrypt files

## Limitations

Currently, it is possible to encrypt and decrypt only small files, because the program loads the entire file into RAM. **The largest file tested was 2.7 GB**.

**Work in progress:** The [`feature/chunk-file-reading`](https://github.com/dixe1/file-encryptor/tree/feature/chunk-file-reading) branch introduces chunk-based file reading and writing, which will allow the tool to handle large files without loading the entire file into memory.


## App Status

> **The `app` section is currently in an early and unfinished state.**

The current CLI is mainly a basic interface for testing the encryption and decryption functionality provided by the `core` library.

The `app` code and user interface are planned to be **redesigned** in the future.

## Usage

Run the application with the path to the file you want to encrypt or decrypt:

```text
FileEncryptor [file_path]
```

After starting the application, select an operation and provide the password:

```text
1 <password>    # Encrypt file
2 <password>    # Decrypt file
3               # Exit
```

For example:

```text
FileEncryptor example.txt

1 mypassword
```

To decrypt the encrypted file:

```text
FileEncryptor example.txt.encrypted

2 mypassword
```

To exit the application:

```text
3
```


Encrypted files are saved with the `.encrypted` extension.

> The CLI interface will be improved in future versions.

## Core Library

The `core` module contains the main cryptographic functionality of the project.

It is responsible for:

* Encryption
* Decryption
* Password-based key generation
* File format handling
* Saving encrypted files
* Loading encrypted files

The cryptographic operations are implemented using libsodium primitives.
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
