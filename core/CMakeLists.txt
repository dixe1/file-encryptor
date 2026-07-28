set(CRYPTOGRAPHY_TOOLS_SOURCES
        src/GenerateKey.cpp
)

set(CRYPTOGRAPHY_TOOLS_HEADERS
        include/GenerateKey.h
        src/FileFormat.cpp
        include/FileFormat.h
        src/Encryption.cpp
        include/Encryption.h
        src/Decryption.cpp
        include/Decryption.h
)

add_library(CryptographyTools STATIC
        ${CRYPTOGRAPHY_TOOLS_SOURCES}
        ${CRYPTOGRAPHY_TOOLS_HEADERS}
)

target_include_directories(CryptographyTools
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)

target_link_libraries(CryptographyTools PRIVATE
        ${SODIUM_LIBRARIES}
)