add_library(game game.cpp game.hpp)

set_property(TARGET game PROPERTY CXX_STANDARD 20)

target_include_directories(game PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game)