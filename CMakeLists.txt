cmake_minimum_required(VERSION 3.5)
project(Corkus)

set(CMAKE_CXX_STANDARD 23)

add_executable(Corkus src/main.cpp
		src/config.cpp
		headers/config.h
		src/quickmenu.cpp
		headers/quickmenu.h
		headers/main.h)

target_compile_options(Corkus PRIVATE -Wall -Werror)
