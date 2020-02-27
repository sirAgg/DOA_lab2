cmake_minimum_required( VERSION 3.0 )

project( lab2 )

if( UNIX AND NOT APPLE )
    set( CMAKE_CXX_FLAGS "-g" )
endif()

add_executable( lab2
  main.cpp
)
