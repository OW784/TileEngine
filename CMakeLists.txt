cmake_minimum_required(VERSION 3.20)

project(tileEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory("lib/SFML")

add_library(tile_level STATIC tile_level_loader/level_system.cpp)
target_include_directories(tile_level INTERFACE tile_level_loader)
target_link_libraries(tile_level sfml-graphics)


add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/res"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res"
)

add_executable(tileEngine
    main.cpp
    game_system.cpp
    entity.cpp
    scenes.cpp
    player.cpp
)

target_link_libraries(tileEngine PRIVATE tile_level sfml-graphics)

set_target_properties(tileEngine PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

add_dependencies(tileEngine copy_resources)