add_library(rules rules.cpp rules.hpp)

set_property(TARGET rules PROPERTY CXX_STANDARD 20)
target_link_libraries(rules texture_manager interface game card)

target_include_directories(rules PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS rules)