add_executable(FileEncryptor
        src/Main.cpp
)

include_directories(include)

target_link_libraries(FileEncryptor
        PRIVATE CryptographyTools
)