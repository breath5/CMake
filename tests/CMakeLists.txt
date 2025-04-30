# 启用测试
enable_testing()

# 测试可执行文件
add_executable(AlgorithmTests test_algorithm.cpp)
target_link_libraries(AlgorithmTests
        PRIVATE
        Algorithm
        GTest::gtest_main
)

# 测试发现
include(GoogleTest)
gtest_discover_tests(AlgorithmTests
        EXTRA_ARGS --gtest_output=xml:${CMAKE_BINARY_DIR}/test_results/
)

# 安装测试工具
install(TARGETS AlgorithmTests
        DESTINATION ${CMAKE_INSTALL_BINDIR}/tests
)