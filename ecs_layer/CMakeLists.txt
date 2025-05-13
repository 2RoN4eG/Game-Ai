cmake_minimum_required(VERSION 3.5)

project(ecs_layer LANGUAGES CXX)

add_library(ecs_layer
    tools/t_2d_vector.hpp                                           tools/t_2d_vector.cpp

    t_component_defines.hpp                                         t_component_defines.cpp
    t_component_holder.hpp                                          t_component_holder.cpp
    t_game_database.hpp                                             t_game_database.cpp
    t_system_manager.hpp                                            t_system_manager.cpp

    interfaces/t_effect_interface.hpp                               interfaces/t_effect_interface.cpp
    interfaces/t_updatable_interface.hpp                            interfaces/t_updatable_interface.cpp
    interfaces/t_input_device_updatable_interface.hpp               interfaces/t_input_device_updatable_interface.cpp
    interfaces/t_sound_player_interface.hpp                         interfaces/t_sound_player_interface.cpp

    components/t_ai_demo_movable_component.hpp                      components/t_ai_demo_movable_component.cpp
    components/t_engine_component.hpp                               components/t_engine_component.cpp
    components/t_chassis_component.hpp                              components/t_chassis_component.cpp
    components/t_turret_component.hpp                               components/t_turret_component.cpp
    components/t_vehicle_component.hpp                              components/t_vehicle_component.cpp
    components/t_gun_component.hpp                                  components/t_gun_component.cpp
    components/t_visibility_component.hpp                           components/t_visibility_component.cpp
    components/t_shell_component.hpp                                components/t_shell_component.cpp
    components/t_radio_component.hpp                                components/t_radio_component.cpp

    components/t_vehicle_entity.hpp                                 components/t_vehicle_entity.cpp

    systems/subsystems/t_ramping_up_vehicle_speed_subsystem.hpp     systems/subsystems/t_ramping_up_vehicle_speed_subsystem.cpp
    systems/subsystems/t_ramping_down_vehicle_speed_subsystem.hpp   systems/subsystems/t_ramping_down_vehicle_speed_subsystem.cpp
    systems/subsystems/t_rotating_vehicle_subsystem.hpp             systems/subsystems/t_rotating_vehicle_subsystem.cpp

    systems/t_ai_demo_linear_moving_system.hpp                      systems/t_ai_demo_linear_moving_system.cpp    
    systems/t_ramping_vehicle_speed_system.hpp                      systems/t_ramping_vehicle_speed_system.cpp
    systems/t_rotating_vehicle_system.hpp                           systems/t_rotating_vehicle_system.cpp
    systems/t_rotating_vehicle_to_course_system.hpp                 systems/t_rotating_vehicle_to_course_system.cpp
    systems/t_rotating_to_course_system.hpp                         systems/t_rotating_to_course_system.cpp

    caches/t_rotating_heading_to_course_cache.hpp                   caches/t_rotating_heading_to_course_cache.cpp

    effects/t_shell_shock_effect.hpp                                effects/t_shell_shock_effect.cpp
    effects/t_damaged_ammunition_stowage.hpp                        effects/t_damaged_ammunition_stowage.cpp
)

include(GNUInstallDirs)
install(TARGETS ecs_layer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
