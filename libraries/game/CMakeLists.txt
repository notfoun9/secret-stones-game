add_library(game game.cpp game.hpp)

set_property(TARGET game PROPERTY CXX_STANDARD 20)
target_link_libraries(game texture_manager menu rules party card interface gameOver)

target_include_directories(game PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game)