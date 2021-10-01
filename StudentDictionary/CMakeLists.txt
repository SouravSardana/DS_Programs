cmake_minimum_required(VERSION 3.19)
project(StudentDictionary)

set(CMAKE_CXX_STANDARD 14)

add_executable(StudentDictionary main.cpp Student.cpp Student.h HashFunctions.h LinkedList.h Chaining.cpp Chaining.h HashFunctions.cpp LinearProbing.cpp LinearProbing.h DoubleHashing.cpp DoubleHashing.h Dictionary.cpp Dictionary.h Universal_Hashing.cpp Universal_Hashing.h)