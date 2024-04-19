add_library(gameOver gameOver.cpp gameOver.hpp)

set_property(TARGET gameOver PROPERTY CXX_STANDARD 20)
target_link_libraries(gameOver texture_manager game card interface_objects) 

target_include_directories(gameOver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS gameOver)