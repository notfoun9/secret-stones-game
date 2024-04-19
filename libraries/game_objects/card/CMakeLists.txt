add_library(card card.cpp card.hpp)

set_property(TARGET card PROPERTY CXX_STANDARD 20)
target_link_libraries(card game texture_manager pull conditions turn field interface_objects)

target_include_directories(card PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS card)