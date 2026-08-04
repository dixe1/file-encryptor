add_executable(FileEncryptor
    src/main.cpp
    src/ClearTerminal.cpp
    src/EncryptFile.cpp
    src/DecryptFile.cpp
)

include_directories(include)

target_link_libraries(FileEncryptor
        PRIVATE CryptographyTools
)