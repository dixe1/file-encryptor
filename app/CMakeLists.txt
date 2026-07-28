add_executable(App_1
    src/main.cpp
    src/ClearTerminal.cpp
    src/EncryptFile.cpp
    src/DecryptFile.cpp
)

include_directories(include)

target_link_libraries(App_1
        PRIVATE CryptographyTools
)