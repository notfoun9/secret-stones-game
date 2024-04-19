add_library(party party.cpp party.hpp)
add_subdirectory(turn)

set_property(TARGET party PROPERTY CXX_STANDARD 20)
target_link_libraries(party texture_manager game game_objects turn pull conditions)

target_include_directories(party PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS party)

