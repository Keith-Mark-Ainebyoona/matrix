cmake_minimum_required(VERSION 3.0)

project(matrices)

add_executable(matrices matrix.c main.c)

##########################################
# For Linux systems(with "gcc"), pass the math shared library to the linker due to this:
# https://stackoverflow.com/a/12824148/16357751
IF(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(matrices -lm) 
ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
##########################################
