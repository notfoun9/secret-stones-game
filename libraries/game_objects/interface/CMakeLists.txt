add_library(interface interface.cpp interface.hpp)

set_property(TARGET interface PROPERTY CXX_STANDARD 20)
target_link_libraries(interface card game texture_manager)

target_include_directories(interface PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS interface)