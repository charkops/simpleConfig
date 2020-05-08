cmake_minimum_required(VERSION 3.1)

project(simpleConfig)

include_directories(${PROJECT_SOURCE_DIR}/include)

set (SOURCE_FILES 
  src/simpleConfig.cpp
)

add_library(simpleConfig ${SOURCE_FILES})
target_link_libraries(simpleConfig stdc++fs)

add_subdirectory(tests)

IF (EXISTS ${PROJECT_SOURCE_DIR}/testing)
  add_subdirectory(testing)
ENDIF(EXISTS ${PROJECT_SOURCE_DIR}/testing)
