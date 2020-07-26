cmake_minimum_required(VERSION 3.5)

project(modern-cpp-algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MCA_BUILD_TESTS "Build modern-cpp-algorithm's unit tests" ON)

option(MCA_ENABLE_WARNINGS "Enable compile warings" ON)
set(WARNING_FALGS "")
if(MCA_ENABLE_WARNINGS)
  list(APPEND WARNING_FALGS "-Wall" "-Wextra" "-Werror")
endif()

set(SOURCES
    sort/bubble.h
    sort/counting.h
    sort/heap.h
    sort/insertion.h
    sort/merge.h
    sort/quick.h
    sort/radix.h
    sort/selection.h
    sort/shell.h
)

add_library(mca INTERFACE)
target_include_directories(mca INTERFACE ${CMAKE_SOURCE_DIR})
target_compile_options(mca INTERFACE ${WARNING_FALGS})

add_library(gsl INTERFACE)
target_include_directories(gsl INTERFACE external/GSL/include)
target_link_libraries(mca INTERFACE gsl)

set(TEST_FILE
    tests/sort_test.cc
)

if(MCA_BUILD_TESTS)
  include(CTest)
  enable_testing()

  add_library(doctest INTERFACE)
  target_include_directories(doctest INTERFACE external/doctest)
  #add_definitions(-DENABLE_DOCTEST_IN_LIBRARY)

  function(mca_add_test test_file)
    get_filename_component(test_target_name ${test_file} NAME_WE)
    add_executable(${test_target_name} ${test_file})
    target_link_libraries(${test_target_name} PRIVATE mca doctest)
    add_test(NAME ${test_target_name} COMMAND ${test_target_name})
  endfunction()

  foreach(test_file ${TEST_FILE})
    mca_add_test(${test_file})
  endforeach()
endif()
