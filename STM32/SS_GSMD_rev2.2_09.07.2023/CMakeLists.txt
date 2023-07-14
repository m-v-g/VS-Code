cmake_minimum_required(VERSION 3.20)

project("SS_GSMD_rev2.2_09.07.2023" C CXX ASM)

include(cmake/st-project.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties(${PROJECT_NAME})