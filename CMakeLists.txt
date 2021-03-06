cmake_minimum_required(VERSION 2.8.0)
project(crowdsound)

# GRPC
include(cmake/grpc.cmake)
find_package(Protobuf REQUIRED)

# Threading
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)

# The Install Location (i.e. make install)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

# Build Location (i.e. make)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories( ${Boost_INCLUDE_DIR} )

include_directories(include)
include_directories(skrillex/include)
include_directories(decisionalgorithm/DecisionAlgorithm/src)

add_subdirectory(skrillex)
add_subdirectory(decisionalgorithm/DecisionAlgorithm/src)
add_subdirectory(src)
