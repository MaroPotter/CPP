cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME NomProjet)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -static")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/Users/marek/CLionProjects/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS Graphics Window System)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()