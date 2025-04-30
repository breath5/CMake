#test_project/
#├── CMakeLists.txt
#├── src/
#│   ├── math.cpp
#│   └── math.h
#└── tests/
#   ├── CMakeLists.txt
#   └── test_math.cpp        # 使用 Google Test/Catch2
cmake_minimum_required(VERSION 3.28)
project(TestDemo LANGUAGES CXX)

# 启用测试支持
enable_testing()

# 添加生产代码库
add_library(MathLib STATIC
        src/math.cpp
        src/math.h
)

# 导出头文件目录
target_include_directories(MathLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 获取Google Test依赖
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(googletest)

# 添加测试子目录
add_subdirectory(tests)