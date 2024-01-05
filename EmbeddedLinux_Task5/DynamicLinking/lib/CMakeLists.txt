cmake_minimum_required(VERSION 3.1...3.22)

project(MyCalculator VERSION 1.0
                  DESCRIPTION "Calculator with five operations: Addition, Subtraction, Multiplication, Division, and Modulus"
                  LANGUAGES C)
SET(SRC_FILES
    ../../SourceFiles/addition.c
    ../../SourceFiles/subtraction.c
    ../../SourceFiles/multiplication.c
    ../../SourceFiles/division.c
    ../../SourceFiles/modulus.c)
    
 SET(HDR_FILES
    ../../HeaderFiles/addition.h
    ../../HeaderFiles/subtraction.h
    ../../HeaderFiles/multiplication.h
    ../../HeaderFiles/division.h
    ../../HeaderFiles/modulus.h)
    
add_library(operation SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(operation PUBLIC ../../HeaderFiles/)
