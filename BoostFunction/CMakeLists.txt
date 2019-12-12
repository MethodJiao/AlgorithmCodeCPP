cmake_minimum_required(VERSION 3.14)
project(BoostFunction)

set(CMAKE_CXX_STANDARD 17)

add_executable(BoostFunction main.cpp)

#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中
#aux_source_directory(. DIR_SRCS)
#add_executable(test1 ${DIR_SRCS})


set(BOOST_ROOT "/usr/local/include/boost")
#添加头文件搜索路径
include_directories(/usr/local/include)

#添加库文件搜索路径
link_directories(/usr/local/lib)

#在这里根据名字boost_thread去寻找libboost_thread.a文件
find_package(Boost 1.69.0 REQUIRED)
target_link_libraries(BoostFunction ${Boost_LIBRARIES})
