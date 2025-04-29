list(APPEND PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/add.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/add.h)
# 强制更新缓存
# 强制更新缓存 (修复参数顺序)
set(PROJECT_SOURCES ${PROJECT_SOURCES} CACHE INTERNAL "All project sources" FORCE)

#创建目标
add_library(Add STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/add.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/add.h)


