# ------------------------ CMAKE SRC : Source ------------------------

cmake_minimum_required(VERSION 2.8.11)

# Executables
add_library(Dvector SHARED Dvector.cpp)
add_library(Height SHARED Height.cpp)
add_library(GerstnerWave SHARED GerstnerWave.cpp)
add_library(WaveModel SHARED WaveModel.cpp)
add_library(GerstnerWaveModel SHARED GerstnerWaveModel.cpp)
