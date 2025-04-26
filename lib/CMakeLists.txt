
# 自动收集所有源文件
file(GLOB SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
# 创建静态库
add_library(CalculatorLib STATIC
        ${SOURCES})

# 设置公共头文件目录
target_include_directories(CalculatorLib PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include")

