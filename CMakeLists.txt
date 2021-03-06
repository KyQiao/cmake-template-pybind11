# default Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES
    src/*.cpp
    src/*.h
)

file(GLOB DEV
    src/dev/*.cpp
    src/dev/*.h
)

if (UNIX)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 ")
endif(UNIX)

if (MSVC)
    # seems openmp won't work for this case
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /openmp")
endif (MSVC)

set(HOME_INC_DIR "./src") 
include_directories(/src)
cmake_minimum_required(VERSION 2.8.12)
# name of the folder
project(example_package)

add_subdirectory(pybind11)
# name of pyd file
pybind11_add_module(_ctest ${SOURCES})
target_link_libraries(_ctest PRIVATE ${Openmp_CXX_FLAGS})
pybind11_add_module(_testprint ${DEV})

