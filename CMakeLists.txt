cmake_minimum_required(VERSION 3.28)
project(Start CXX)

#设置C++标准
set(CMAKE_C_STANDARD 17)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)
# 收集源文件
file(GLOB SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)
# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

#multi_files/
#├── CMakeLists.txt
#├── include/
#│   └── utils.h
#├── src/
#│   ├── utils.cpp
#│   └── main.cpp