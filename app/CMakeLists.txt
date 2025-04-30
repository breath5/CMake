# 可执行文件
add_executable(ComplexApp main.cpp)

# 依赖链接
target_link_libraries(ComplexApp
        PRIVATE
        Algorithm
        Network
)

# 安装规则
install(TARGETS ComplexApp
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}  # macOS
)

# 跨平台资源安装
install(DIRECTORY $<IF:$<PLATFORM_ID:Windows>,resources/,Resources/>
        DESTINATION $<IF:$<PLATFORM_ID:Windows>,${CMAKE_INSTALL_BINDIR},${CMAKE_INSTALL_DATADIR}>
        USE_SOURCE_PERMISSIONS
)