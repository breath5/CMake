cmake_minimum_required(VERSION 3.28)
project(ExternalLibDemo CXX)


# 可选：设置第三方库搜索策略
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)  # 优先使用Config模式
# [1] 尝试查找系统安装的库 -------------------------------------------------
find_package(OpenCV QUIET)
# [2] 系统库未找到时使用本地备用库 ------------------------------------------
if(NOT OpenCV_FOUND)
    message(STATUS "OpenCV not found, using local backup.")
    #设置本地库路径
    set(LOCAL_OPENCV_DIR "${CMAKE_SOURCE_DIR}/third_party/some_lib")
    # 验证头文件存在
    if(NOT EXITS "${LOCAL_OPENCV_DIR}/include/opencv2/core.hpp")
        message(FATAL_ERROR "OpenCV header not found in local backup."
            "Please check the path: ${LOCAL_OPENCV_DIR}/include/opencv2/core.hpp")
    endif()
    #验证库文件存在
    if(NOT EXITS "${LOCAL_OPENCV_DIR}/lib/libopencv_core.a" AND
        NOT EXITS "${LOCAL_OPENCV_DIR}/lib/libopencv_core.so")
        message(FATAL_ERROR "Local OpenCV libraries not found at ${LOCAL_OPENCV_DIR}/lib")
    endif()
    #创建导入目标
    add_library(OpenCV::Core STATIC IMPORTED)
    set_target_properties(OpenCV::Core PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${LOCAL_OPENCV_DIR}/include"
            IMPORTED_LOCATION "${LOCAL_OPENCV_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}opencv_core${CMAKE_STATIC_LIBRARY_SUFFIX}"
    )
    set(OpenCV_FOUND TRUE) # 标记本地库可用
endif()
# [3] 最终可用性检查 -------------------------------------------------------
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found, install system package or provide local build")
endif()

add_executable(ExternalLibDemo src/main.cpp)
if(TARGET OpenCV::Core)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenCV::Core)
else()
    target_link_libraries(${PROJCE_NAME} PRIVATE ${LOCAL_OPENCV_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}opencv_core${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()

# [6] 包含目录处理（现代CMake推荐方式）-------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE
        $<TARGET_PROPERTY:OpenCV::Core,INTERFACE_INCLUDE_DIRECTORIES>
)


#external_lib_project/
#├── CMakeLists.txt
#├── src/
#│   └── main.cpp
#└── third_party/
#    └── some_lib/            # 例如 Boost、OpenCV 的本地构建
#        ├── include/
#        └── lib/