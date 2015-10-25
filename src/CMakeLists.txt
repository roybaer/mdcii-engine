
cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
add_definitions(-std=c++11)

add_executable(inselbmp inselbmp.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp)
target_link_libraries(inselbmp boost_iostreams)

add_executable(weltbmp weltbmp.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp welt.cpp bebauung.cpp)
target_link_libraries(weltbmp boost_iostreams)

add_executable(sdltest sdltest.cpp bildspeicher.cpp bildspeicher_pal8.cpp block.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp welt.cpp kamera.cpp karte.cpp spielbildschirm.cpp bebauung.cpp)
target_link_libraries(sdltest SDL boost_iostreams boost_program_options)
add_custom_command(TARGET sdltest POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bebauung.txt ${CMAKE_CURRENT_BINARY_DIR}/bebauung.txt)

add_executable(bshdump bshdump.cpp bildspeicher.cpp bildspeicher_pal8.cpp bildspeicher_rgb24.cpp)
target_link_libraries(bshdump boost_iostreams boost_program_options)
