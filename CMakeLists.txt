cmake_minimum_required(VERSION 3.10)
project(compilers_project)

set(CMAKE_CXX_STANDARD 14)

set(MAIN "src/main.cpp")
set(INSTRUCTIONS "src/instructions/impl/*.cpp")
set(INSTRUCTIONS_UTILS "src/instructions/utill/impl/*.cpp")


add_library(process_lib src/process.cpp src/instructions/impl/Instruction.cpp src/instructions/impl/LDInstruction.cpp src/instructions/impl/LDAInstruction.cpp src/instructions/impl/LDCInstruction.cpp src/instructions/impl/STInstruction.cpp src/instructions/impl/MOVInstruction.cpp src/instructions/impl/ADDInstruction.cpp src/instructions/impl/SUBInstruction.cpp src/instructions/impl/ASRInstruction.cpp src/instructions/impl/ASLInstruction.cpp src/instructions/impl/ORInstruction.cpp src/instructions/impl/ANDInstruction.cpp src/instructions/impl/XORInstruction.cpp src/instructions/impl/LSLInstruction.cpp src/instructions/impl/LSRInstruction.cpp src/instructions/impl/CNDInstruction.cpp src/instructions/impl/CBRInstruction.cpp src/instructions/impl/NOPInstruction.cpp src/instructions/impl/STOPInstruction.cpp src/instructions/impl/DefaultInstruction.cpp src/instructions/utill/impl/Operator.cpp src/instructions/impl/DataInstruction.cpp)

add_subdirectory(test)

add_executable(compilers_project src/main.cpp)

target_link_libraries(compilers_project process_lib)





