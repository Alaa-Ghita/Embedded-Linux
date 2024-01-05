cmake_minimum_required(VERSION 3.1...3.22)

project(MyCalculator VERSION 1.0
                  DESCRIPTION "Calculator with five operations: Addition, Subtraction, Multiplication, Division, and Modulus"
                  LANGUAGES C)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(main.out ../main.c)
target_include_directories(main.out INTERFACE ../HeaderFiles/)
target_link_libraries(main.out PUBLIC operation)



