add_library(interface_objects interface_objects.cpp interface_objects.hpp)

set_property(TARGET interface_objects PROPERTY CXX_STANDARD 20)
target_link_libraries(interface_objects card game texture_manager)

target_include_directories(interface_objects PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS interface_objects)