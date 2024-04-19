add_library(pull pull.cpp pull.hpp)

set_property(TARGET pull PROPERTY CXX_STANDARD 20)
target_link_libraries(pull card game conditions texture_manager interface)

target_include_directories(pull PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS pull)