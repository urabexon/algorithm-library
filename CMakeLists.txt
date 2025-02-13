cmake_minimum_required(VERSION 3.10)
project(AtCoderLibrary)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(main src/main.cpp)

# テストプログラム用ビルド設定
add_executable(test_main tests/test_main.cpp)
enable_testing()
add_test(NAME runTests COMMAND test_main)
