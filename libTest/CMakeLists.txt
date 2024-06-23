cmake_minimum_required(VERSION 3.10)
project(TestCudaCal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CUDA)
if(CUDA_FOUND)
    message("CUDA found")
    enable_language(CUDA)
    add_definitions(-DHAVE_CUDA)
else()
    message("CUDA not found")
endif()

message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message("CUDA_INCLUDE_DIRS = ${CUDA_INCLUDE_DIRS}")
message("CUDA_LIBRARIES = ${CUDA_LIBRARIES}")

# 包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)
#include_directories(${CUDA_INCLUDE_DIRS})

# 链接目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 添加可执行文件
add_executable(TestCudaCal main.cpp)

# 链接库文件
target_link_libraries(TestCudaCal ChomoCuLib)
if(CUDA_FOUND)
    target_link_libraries(TestCudaCal ${CUDA_LIBRARIES})
endif() 