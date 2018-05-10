# -------------------- VERSION USED OF CMAKE ---------------------

# http://www.hannahdee.eu/cpp.html
# recent cmake version used
cmake_minimum_required(VERSION 2.8.11)

# our project is called modelisation c++
project(modelisationC++)

# enable make test
enable_testing()
include(CTest)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )
set( MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/valgrind_suppress.txt")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories($(OPENGL_INCLUDE_DIRS) $(GLUT_INCLUDE_DIRS))

# add all the subdirectories needed to make the whole thing work
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(doc)

# TO MAKE GLUT WORK
# sudo apt-get install freeglut3-dev
# sudo apt-get install libxmu-dev libxi-dev
