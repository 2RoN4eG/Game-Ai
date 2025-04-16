cmake_minimum_required(VERSION 3.5)

project(test_cases_layer LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(test_cases_layer
    test_ramping_up_vehicle_speed_subsystem.cpp
)
target_link_libraries(test_cases_layer PRIVATE Catch2::Catch2WithMain)

target_link_libraries( test_cases_layer PRIVATE ai_layer )
target_include_directories ( test_cases_layer PUBLIC ${CMAKE_SOURCE_DIR}/ai_layer )

target_link_libraries( test_cases_layer PRIVATE ecs_layer )
target_include_directories ( test_cases_layer PUBLIC ${CMAKE_SOURCE_DIR}/ecs_layer )

include(GNUInstallDirs)
install(TARGETS test_cases_layer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
