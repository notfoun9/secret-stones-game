add_library(states INTERFACE)
add_subdirectory(menu)
add_subdirectory(party)
add_subdirectory(rules)
add_subdirectory(gameOver)

target_include_directories(states INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
