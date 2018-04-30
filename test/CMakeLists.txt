# ------------------------ CMAKE SRC : Test ------------------------

cmake_minimum_required(VERSION 2.8.11)

# Executables
add_executable(Dvector_test Dvector_test.cpp)
add_executable(Operator_test Operator_test.cpp)
add_executable(Height_test Height_test.cpp)
add_executable(GerstnerWave_test GerstnerWave_test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)

target_link_libraries(Dvector_test Dvector)
target_link_libraries(Operator_test Dvector)
target_link_libraries(Height_test Height Dvector)
target_link_libraries(GerstnerWave_test GerstnerWave Dvector)

#Tests
add_test(TP1 Dvector_test)
add_test(TP2 Operator_test)
add_test(TP3.1 Height_test)
add_test(TP3.2 GerstnerWave_test)
