cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(game_ai LANGUAGES CXX)

add_subdirectory(ai_layer)

add_subdirectory(ecs_layer)

add_subdirectory(test_case_layer)

add_subdirectory(demo_layer/demo_shooting_brain)
