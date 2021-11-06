cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PEA1 VERSION 0.1.0)

add_library(src STATIC 
    src/BruteForce.cpp
    src/BruteForceStl.cpp
    src/DynamicPrograming.cpp
    src/Graph.cpp
    src/BranchAndBound.cpp
)

# add_library(files STATIC 
#     test_files/tsp_6_1.txt
#     test_files/tsp_6_2.txt
#     test_files/tsp_10.txt
#     test_files/tsp_12.txt
#     test_files/tsp_13.txt
#     test_files/tsp_15.txt
#     test_files/tsp_17.txt)

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
# target_include_directories(files PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test_files)

include(CTest)
enable_testing()

add_executable(PEA1 main.cpp)
target_link_libraries(PEA1 PUBLIC src)
# target_link_libraries(PEA1 PUBLIC files)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
