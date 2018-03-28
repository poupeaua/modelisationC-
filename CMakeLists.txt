# -------------------- VERSION USED OF CMAKE ---------------------

# recent cmake version used
cmake_minimum_required(VERSION 2.8.11)

# our project is called modelisation c++
project(modelisationC++)

# enable make test
enable_testing()

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

# add all the subdirectories needed to make the whole thing work
add_subdirectory(src)
add_subdirectory(test)
# add_subdirectory(doc)
