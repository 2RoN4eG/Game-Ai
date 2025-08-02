cmake_minimum_required(VERSION 3.5)

project(test_cases_layer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include( FetchContent )

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable( Catch2 )

FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
  GIT_TAG main
)

FetchContent_MakeAvailable( trompeloeil )

add_executable( test_cases_layer
    t_helper.hpp t_helper.cpp

    test_ramping_up_vehicle_speed_subsystem.cpp
    test_ramping_down_vehicle_speed_subsystem.cpp
    test_range_from_minus_360_to_plus_360.cpp
    test_vehicle_speed.cpp
    test_shell_shock_effect.cpp
    test_game_database.cpp
    test_vehicle_entity.cpp
    test_braking_control_system.cpp
    test_detecting_enemy_system.cpp
    test_double_buffering_team_player_lookup_subsystem.cpp

    mocks/mock_sound_player.hpp
)
target_link_libraries( test_cases_layer PRIVATE Catch2::Catch2WithMain trompeloeil::trompeloeil )

target_link_libraries( test_cases_layer PRIVATE ai_layer )
target_include_directories ( test_cases_layer PUBLIC ${CMAKE_SOURCE_DIR}/ai_layer )

target_link_libraries( test_cases_layer PRIVATE ecs_layer )
target_include_directories ( test_cases_layer PUBLIC ${CMAKE_SOURCE_DIR}/ecs_layer )

include(GNUInstallDirs)
install(TARGETS test_cases_layer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
