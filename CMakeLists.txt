cmake_minimum_required(VERSION 3.24)
project(Hospital_Admin_Console_App)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hospital_Admin_Console_App main.cpp Logger.h HospitalCommandGuide.cpp HospitalCommandGuide.h HospitalSystem.cpp HospitalSystem.h Patient.cpp Patient.h)
