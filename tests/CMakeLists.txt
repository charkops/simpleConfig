
set (TEST_SOURCE_FILES
  main.cpp
  simpleConfig_test.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include/catch)

add_executable(tests ${TEST_SOURCE_FILES})
target_link_libraries(tests simpleConfig)