project(ZenOfGitHub)
cmake_minimum_required(VERSION 3.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(zenofgithub zenofgithub.c)
target_link_libraries(zenofgithub ${CONAN_LIBS})

TARGET_LINK_LIBRARIES(zenofgithub ${CONAN_LIBS})
