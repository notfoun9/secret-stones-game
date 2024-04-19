add_library(conditions conditions.cpp conditions.hpp)

set_property(TARGET conditions PROPERTY CXX_STANDARD 20)
target_link_libraries(conditions pull game_objects game party)

target_include_directories(conditions PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS conditions)