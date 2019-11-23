cmake_minimum_required(VERSION 3.6.2)
#set(CMAKE_C_COMPILER /cygdrive/s/program_files/cygwin/bin/gcc.exe CACHE PATH "" FORCE)
#set(CMAKE_CXX_COMPILER /cygdrive/s/program_files/cygwin/bin/g++.exe CACHE PATH "" FORCE)
project(libft_run C)
set(CMAKE_C_STANDARD 90)
include_directories(.)
include_directories(libft)
include_directories(headers)

#--------------LIB LINK EXAMPLE---------------------
#add_executable(<exe_name> sorce1 source2)
#find_library(FT ft libft)
#target_link_libraries(<exe_name> LINK_PUBLIC ${FT})
#---------------------------------------------------

include_directories(headers)
include_directories(glut)
include_directories(libft)
add_library(mlx
		src/mlx.c
		src/mlx_image.c
		src/mlx_hook.c
		src/mlx_keys.c
		)
add_executable(mlx_test
		src/main.c
		)
target_link_libraries(mlx_test LINK_PRIVATE
		mlx
		LINK_PUBLIC ${CMAKE_SOURCE_DIR}/glut/freeglut.lib
		LINK_PUBLIC ${CMAKE_SOURCE_DIR}/glut/freeglutd.lib
		LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/cmake-build-debug/libft.lib)
