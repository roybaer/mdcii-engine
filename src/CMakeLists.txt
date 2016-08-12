cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
add_definitions(-std=c++11)
find_package(Boost REQUIRED COMPONENTS iostreams program_options)
find_package(SDL REQUIRED)

add_executable(mdcii-inselbmp inselbmp.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp insel.cpp strukturen.cpp bebauung.cpp grafiken.cpp)
target_link_libraries(mdcii-inselbmp boost_iostreams)

add_executable(mdcii-weltbmp weltbmp.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp insel.cpp strukturen.cpp welt.cpp bebauung.cpp grafiken.cpp)
target_link_libraries(mdcii-weltbmp boost_iostreams)

add_executable(mdcii-sdltest sdltest.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp insel.cpp strukturen.cpp welt.cpp kamera.cpp karte.cpp spielbildschirm.cpp bebauung.cpp grafiken.cpp)
target_link_libraries(mdcii-sdltest SDL boost_iostreams boost_program_options)
add_custom_command(TARGET mdcii-sdltest POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bebauung.txt ${CMAKE_CURRENT_BINARY_DIR}/bebauung.txt)
add_custom_command(TARGET mdcii-sdltest POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/grafiken.txt ${CMAKE_CURRENT_BINARY_DIR}/grafiken.txt)

add_executable(mdcii-bshdump bshdump.cpp bildspeicher.cpp bildspeicher_pal8.cpp bildspeicher_rgb24.cpp)
target_link_libraries(mdcii-bshdump boost_iostreams boost_program_options)
