cmake_minimum_required(VERSION 3.27.0)

project(Snake)
cmake_policy(SET CMP0072 NEW)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

find_package(Curses REQUIRED)

set(PROJECT_INCLUDES
    ${CURSES_INCLUDE_DIR}
    ${PROJECT_INCLUDE_DIR}/board.hpp
    ${PROJECT_INCLUDE_DIR}/game.hpp
    ${PROJECT_INCLUDE_DIR}/symbol.hpp
    ${PROJECT_INCLUDE_DIR}/snake.hpp
    ${PROJECT_INCLUDE_DIR}/scoreboard.hpp)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/board.cpp
    ${PROJECT_SOURCE_DIR}/game.cpp
    ${PROJECT_SOURCE_DIR}/symbol.cpp
    ${PROJECT_SOURCE_DIR}/snake.cpp
    ${PROJECT_SOURCE_DIR}/scoreboard.cpp)

add_executable(main 
    main.cpp
    ${PROJECT_INCLUDES}
    ${PROJECT_SOURCES})

target_include_directories(main PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(main ${CURSES_LIBRARIES})