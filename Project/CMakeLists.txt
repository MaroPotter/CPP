cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp)
set(SFML_ROOT C:/Users/marek/CLionProjects/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED Audio Graphics Network Window System)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Project ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()