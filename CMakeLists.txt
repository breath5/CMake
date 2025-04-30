#complex_project/
#├── CMakeLists.txt
#├── libs/
#│   ├── algorithm/           # 静态库
#│   │   ├── CMakeLists.txt
#│   │   ├── include/
#│   │   └── src/
#│   └── network/             # 动态库
#│       ├── CMakeLists.txt
#│       ├── include/
#│       └── src/
#├── app/
#│   ├── CMakeLists.txt
#│   └── main.cpp
#└── tests/
#   ├── CMakeLists.txt
#   └── test_algorithm.cpp
 cmake_minimum_required(VERSION 3.28)
project(ComplexProject LANGUAGES CXX)

#设置全局变量
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "_d")  #Debug库后缀

# 输出目录配置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMKAE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加子目录
add_subdirectory(libs/algorithm)
add_subdirectory(libs/network)
add_subdirectory(app)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
#加载 CMake 内置的 GNUInstallDirs 模块
include(GNUInstallDirs)
set(CMAKE_INSTREFIX ${CMAKE_BINARY_DIR}/dist CACHE PATH "install path" "Installation directory")
install(EXPORT ComplexProjectTargets
         FILE ComplexProjectTargets.cmake
         NAMESPACE ComplexProject::
         DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ComplexProject)
#dist/
#├── lib/
#│   ├── libalgorithm.a            # 静态库
#│   ├── cmake/ComplexProject/     # 配置目录
#│       └── ComplexProjectConfig.cmake
#└── include/                      # 头文件目录
