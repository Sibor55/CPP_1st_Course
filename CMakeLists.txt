cmake_minimum_required(VERSION 3.0.0)
project(Cpp_1st_course VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_executable(Task_1 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 1/main.cpp")
add_executable(Task_2 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 2/main.cpp" "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 2/matrix.cpp")
add_executable(Task_3 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 3/main.cpp")
add_executable(Task_4 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 4/main.cpp")
add_executable(Task_5 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 5/main.cpp")
add_executable(Task_6 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 6/main.cpp")
add_executable(Task_7 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 7/main.cpp")
add_executable(Task_8 "${CMAKE_SOURCE_DIR}/2nd_Semestr/Task 8/main.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
