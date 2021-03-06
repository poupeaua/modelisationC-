# ------------------------ CMAKE SRC : Source ------------------------

cmake_minimum_required(VERSION 2.8.11)

# Executables
add_library(Dvector SHARED Dvector.cpp)
add_library(Height SHARED Height.cpp)
add_library(GerstnerWave SHARED GerstnerWave.cpp)
add_library(WaveModel SHARED WaveModel.cpp)
add_library(GerstnerWaveModel SHARED GerstnerWaveModel.cpp)
add_library(PhilipsWaveModel SHARED PhilipsWaveModel.cpp)
add_library(Ocean SHARED Ocean.cpp)
add_library(Camera SHARED camera.cxx)
add_library(Window SHARED window.cxx)

add_executable(Main_Visualization main.cxx)

target_link_libraries(Main_Visualization
                      Ocean Window Camera
                      GerstnerWaveModel PhilipsWaveModel WaveModel GerstnerWave
                      Height Dvector ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}
                    )
