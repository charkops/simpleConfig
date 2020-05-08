cmake_minimum_required(VERSION 3.1)

project(simpleConfig)

include_directories(${PROJECT_SOURCE_DIR}/include)

set (SOURCE_FILES 
  src/simpleConfig.cpp
)

add_library(simpleConfig ${SOURCE_FILES})

add_subdirectory(tests)
