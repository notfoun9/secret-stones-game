add_library(field field.cpp field.hpp)

set_property(TARGET field PROPERTY CXX_STANDARD 20)
target_link_libraries(field game texture_manager card)

target_include_directories(field PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS field)