set(CRYPTOGRAPHY_TOOLS_SOURCES
        src/Test.cpp
)

set(CRYPTOGRAPHY_TOOLS_HEADERS
        include/Test.h
)

add_library(CryptographyTools STATIC
        ${CRYPTOGRAPHY_TOOLS_SOURCES}
        ${CRYPTOGRAPHY_TOOLS_HEADERS}
)

target_include_directories(CryptographyTools
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)