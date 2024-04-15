add_library(menu menu.cpp menu.hpp)

set_property(TARGET menu PROPERTY CXX_STANDARD 20)
target_link_libraries(menu texture_manager game game_objects)

target_include_directories(menu PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS menu)