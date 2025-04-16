cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ai LANGUAGES CXX)

add_subdirectory(ai_layer)

add_subdirectory(ecs_layer)

add_subdirectory(test_cases_layer)
