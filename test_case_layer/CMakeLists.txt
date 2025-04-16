cmake_minimum_required(VERSION 3.5)

project(test_case_layer LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Fetch dependencies
include(FetchContent)

# Catch2 v3
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Trompeloeil mocking framework
FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
  GIT_TAG main
)
FetchContent_MakeAvailable(trompeloeil)

# Define test executable
add_executable(test_case_layer
    t_helper.hpp
    t_helper.cpp

    test_ramping_up_vehicle_speed_subsystem.cpp
    test_ramping_down_vehicle_speed_subsystem.cpp
    test_range_from_minus_360_to_plus_360.cpp
    test_vehicle_speed.cpp
    test_shell_shock_effect.cpp
    test_game_database.cpp
    test_vehicle_entity.cpp
    test_braking_control_system.cpp
    test_self_detecting_enemy_system.cpp
    test_double_buffering_team_player_lookup_subsystem.cpp

    mocks/mock_sound_player.hpp
)

# Link libraries
target_link_libraries(test_case_layer PRIVATE
    Catch2::Catch2WithMain
    trompeloeil::trompeloeil
    ai_layer
    ecs_layer
)

# Include directories
target_include_directories(test_case_layer PUBLIC
    ${CMAKE_SOURCE_DIR}/ai_layer
    ${CMAKE_SOURCE_DIR}/ecs_layer
)

# Register Catch2 tests with CTest
include(Catch)
catch_discover_tests(test_case_layer)

# Install rules
include(GNUInstallDirs)
install(TARGETS test_case_layer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
