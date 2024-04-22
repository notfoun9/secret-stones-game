add_library(text text.cpp text.hpp)

set_property(TARGET text PROPERTY CXX_STANDARD 20)
target_link_libraries(text game) 

target_include_directories(text PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS text)