# 静态库配置
file(GLOB_RECURSE ALGO_SOURCES src/*.cpp include/*.h)
add_library(Algorithm STATIC ${ALGO_SOURCES})

# 可见性控制
target_compile_options(Algorithm PRIVATE -fvisibility=hidden)

# 安装规则
install(TARGETS Algorithm
        EXPORT ComplexProjectTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/algorithm
)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/algorithm
        FILES_MATCHING PATTERN "*.h"
)