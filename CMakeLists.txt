project (dpx)

cmake_minimum_required(VERSION 2.6)

if (${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message (FATAL_ERROR "Not allowed to run in-source build!")
endif ()

#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/share/cmake")

add_subdirectory (src)


#add_executable(test dpx.cpp test.cpp)
