# 创建测试可执行文件
add_executable(MathTests
        test_math.cpp
)

# 链接依赖项
target_link_libraries(MathTests
        PRIVATE
        MathLib
        GTest::gtest_main
)

# 注册测试用例
add_test(
        NAME MathUnitTests
        COMMAND MathTests
)

# 启用内存检查（可选）
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(MathTests PRIVATE -fsanitize=address)
    target_link_options(MathTests PRIVATE -fsanitize=address)
endif()