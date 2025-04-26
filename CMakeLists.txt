cmake_minimum_required(VERSION 3.28)
project(LibraryProject CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 添加子目录  （顺序很重要：库先于应用（在Makefile中同时存在这种情况））
add_subdirectory(lib)
add_subdirectory(app)

#library_project/
#├── CMakeLists.txt
#├── lib/
#│   ├── CMakeLists.txt       # 子目录管理
#│   ├── include/
#│   │   └── calculator.h
#│   │   └── add.h
#│   └── src/
#│       └── calculator.cpp
#│       └── add.cpp
#└── app/
    #├── CMakeLists.txt
    #└── main.cpp