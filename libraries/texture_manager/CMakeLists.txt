add_library(texture_manager texture_manager.cpp texture_manager.hpp)

set_property(TARGET texture_manager PROPERTY CXX_STANDARD 20)

target_include_directories(texture_manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS texture_manager)