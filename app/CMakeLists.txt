#创建可执行文件
add_executable(MainApp main.cpp)


#链接库
target_link_libraries(MainApp PRIVATE
        CalculatorLib)