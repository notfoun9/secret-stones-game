add_executable(main main.cpp)

target_link_libraries(main game)

set_target_properties(main PROPERTIES LINK_FLAGS "-F/Library/Frameworks -framework SDL2_image -framework SDL2")

link_directories(/Library/Frameworks)
target_link_libraries(main ${SDL2})
target_link_libraries(main ${SDL2_image})
