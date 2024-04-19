add_library(conditions conditions.cpp conditions.hpp)

set_property(TARGET conditions PROPERTY CXX_STANDARD 20)
target_link_libraries(conditions pull card game party interface_objects)

target_include_directories(conditions PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS conditions)