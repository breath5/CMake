cmake_minimum_required(VERSION 3.28)
project(LibraryProject CXX)

#全局编译选项（传递到子模块）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 全局源文件集合（CACHE INTERNAL保证全局可见）
set(PROJECT_SOURCES "" CACHE INTERNAL "All project sources")

# 添加子目录  （顺序很重要：库先于应用（在Makefile中同时存在这种情况））
add_subdirectory(add)
add_subdirectory(sub)


# 添加主程序并链接库
add_executable(${PROJECT_NAME} main.cpp ${PROJECT_SOURCES}) # 使用全局收集的源文件
target_link_libraries(${PROJECT_NAME} PRIVATE Add Sub) # 链接库



#modular_project/
#├── CMakeLists.txt           # 根配置
#├── core/
#│   ├── CMakeLists.txt
#│   ├── core.h
#│   └── core.cpp
#├── gui/
#│   ├── CMakeLists.txt
#│   ├── window.h
#│   └── window.cpp
#└── main.cpp

