# ------------------------ CMAKE SRC : Source ------------------------

cmake_minimum_required(VERSION 2.8.11)

# Executables
add_library(Dvector SHARED Dvector.cpp)
add_library(Height SHARED Height.cpp Dvector.cpp)
