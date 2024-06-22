cmake_minimum_required(VERSION 3.8)

project ("ChomoCuLib" LANGUAGES CXX)

set(CMAKE_CUDA_ARCHITECTURES 75)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# include
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CUDA_INCLUDE_DIRS})

# for cuda common tools
if(WIN32)
    set(CUDA_COMMON_TOOLS_DIR "D:/cuda12sample/cuda-samples-12.0/cuda-samples-12.0/Common")
else()
    set(CUDA_COMMON_TOOLS_DIR "/root/dependency/cuda12/cuda-samples-master/Common")
endif()
include_directories(${CUDA_COMMON_TOOLS_DIR})
message("CUDA_COMMON_TOOLS_DIR = ${CUDA_COMMON_TOOLS_DIR}")

# create library
add_library(ChomoCuLib STATIC
    src/cudaCal.cpp
)

if (CUDA_FOUND)
    target_sources(ChomoCuLib PRIVATE src/cudaKernel.cu)
    # link cuda
    target_link_libraries(ChomoCuLib ${CUDA_LIBRARIES})
endif()