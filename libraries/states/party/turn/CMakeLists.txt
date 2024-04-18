add_library(turn turn.cpp turn.hpp)

set_property(TARGET turn PROPERTY CXX_STANDARD 20)
target_link_libraries(turn party texture_manager game game_objects)

target_include_directories(turn PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS turn)

