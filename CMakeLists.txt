# recent cmake version used
cmake_minimum_required(VERSION 2.8)

# our project is called modelisation c++
project(modelisationC++)

# create variables with the files we want to compile
set(SRCS
    src/*
    test/*
    )

# for headers we want to use
set(HEADERS
    src/*
    test/*
    )

add_executable(
    Dvector_test
    test/Dvector_test.cpp
)
