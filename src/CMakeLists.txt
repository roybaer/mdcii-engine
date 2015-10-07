
cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
add_definitions(-std=c++11)

add_executable(inselbmp inselbmp.cpp bildspeicher.cpp block.cpp bsh_leser.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp)
target_link_libraries(inselbmp boost_iostreams)

add_executable(weltbmp weltbmp.cpp bildspeicher.cpp block.cpp bsh_leser.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp welt.cpp)
target_link_libraries(weltbmp boost_iostreams)

add_executable(sdltest sdltest.cpp bildspeicher.cpp block.cpp bsh_leser.cpp grafikinfo.cpp insel.cpp stadtfld_bsh.cpp strukturen.cpp welt.cpp kamera.cpp)
target_link_libraries(sdltest SDL boost_iostreams boost_program_options)

add_executable(bshdump bshdump.cpp bildspeicher.cpp bsh_leser.cpp)
target_link_libraries(bshdump boost_iostreams boost_program_options)
