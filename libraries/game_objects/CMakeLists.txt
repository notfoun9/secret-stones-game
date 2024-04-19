add_library(game_objects game_object.cpp game_objects.hpp)

set_property(TARGET game_objects PROPERTY CXX_STANDARD 20)

target_include_directories(game_objects PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game_objects)