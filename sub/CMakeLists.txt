list(APPEND PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/sub.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sub.h)

# 强制更新缓存 (修复参数顺序)
set(PROJECT_SOURCES ${PROJECT_SOURCES} CACHE INTERNAL "All project sources" FORCE)


add_library(Sub STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sub.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sub.h)