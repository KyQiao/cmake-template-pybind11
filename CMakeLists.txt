# default Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES
    src/*.cpp
    src/*.h
)

if (UNIX)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fopenmp")
endif(UNIX)

if (MSVC)
    # set(CMAKE_CXX_FLAGS_RELEASE "/O2 /openmp /I './src'")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /openmp")
endif (MSVC)

set(HOME_INC_DIR "./src") 
include_directories(/src)
cmake_minimum_required(VERSION 2.8.12)
# name of the folder
project(ctest)

add_subdirectory(pybind11)
# name of pyd file
pybind11_add_module(ctest ${SOURCES})
pybind11_add_module(testprint ${SOURCES})

