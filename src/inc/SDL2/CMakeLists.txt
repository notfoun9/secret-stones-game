add_library(SDL SDL.h)

set_property(TARGET SDL PROPERTY CXX_STANDARD 17)

target_include_directories(SDL PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS SDL)