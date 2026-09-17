include(FetchContent)

FetchContent_Declare(
        libsodium
        GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
        GIT_TAG master
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(libsodium)

set(CRYPTOGRAPHY_TOOLS_SOURCES
        src/Encrypt.cpp
)

set(CRYPTOGRAPHY_TOOLS_HEADERS
        include/Encrypt.h
)

add_library(CryptographyTools STATIC
        ${CRYPTOGRAPHY_TOOLS_SOURCES}
        ${CRYPTOGRAPHY_TOOLS_HEADERS}
)

target_include_directories(CryptographyTools
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(CryptographyTools PRIVATE sodium)