cmake_minimum_required(VERSION 3.6.2)
project(mlx_glut C)
set(CMAKE_C_STANDARD 90)
include_directories(.)
include_directories(glut)
add_library(mlx
		src/mlx.c
		src/mlx_image.c
		src/mlx_hook.c
		src/mlx_keys.c
		)
add_executable(mlx_test
		src/main.c
		)
target_link_libraries(mlx_test
		LINK_PRIVATE mlx
		LINK_PUBLIC ${CMAKE_SOURCE_DIR}/glut/freeglut.lib
		LINK_PUBLIC ${CMAKE_SOURCE_DIR}/glut/freeglutd.lib
		)
