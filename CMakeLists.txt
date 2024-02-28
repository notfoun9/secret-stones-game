cmake_minimum_required(VERSION 3.20)

project(games)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO bin.relwithdbg)

add_subdirectory(libraries)
add_subdirectory(executables)
add_subdirectory(src)
add_subdirectory(assets)

set_target_properties(
  main PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)