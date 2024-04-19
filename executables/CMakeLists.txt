
set (CMAKE_PREFIX_PATH "../src/lib")

add_executable(main main.cpp)

target_link_libraries(main game)

find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED COMPONENTS SDL2_image)

target_link_libraries(main SDL2::SDL2)
target_link_libraries(main SDL2_image::SDL2_image)

link_directories(lib)
