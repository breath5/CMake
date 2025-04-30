# 动态库配置
file(GLOB_RECURSE NET_SOURCES src/*.cpp include/*.h)
add_library(Network SHARED ${NET_SOURCES})

# 版本控制
set_target_properties(Network PROPERTIES
        VERSION "${PROJECT_VERSION}"
        SOVERSION 1
        DEFINE_SYMBOL "NETWORK_EXPORTS"
)

# 安装规则
install(TARGETS Network
        EXPORT ComplexProjectTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # Windows DLL
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/network
)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/network
        FILES_MATCHING PATTERN "*.h"
)