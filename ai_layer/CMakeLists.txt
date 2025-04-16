cmake_minimum_required(VERSION 3.5)

project(ai_layer LANGUAGES CXX)

add_library(ai_layer
    t_defines.hpp                                   t_defines.cpp
    # gob/
    gob/t_gob_transition.hpp                        gob/t_gob_transition.cpp
    gob/t_gob_node.hpp                              gob/t_gob_node.cpp
    # gob/interfaces/
    gob/interfaces/t_goal_interface.hpp             gob/interfaces/t_goal_interface.cpp
    gob/interfaces/t_behavior_interface.hpp         gob/interfaces/t_behavior_interface.cpp
    # gob/goals/
    gob/goals/t_goal_is_arrived.hpp                 gob/goals/t_goal_is_arrived.cpp
    gob/goals/t_goal_selector_or.hpp                gob/goals/t_goal_selector_or.cpp
    gob/goals/t_goal_selector_and.hpp               gob/goals/t_goal_selector_and.cpp
    # gob/behaviors/
    gob/behaviors/t_1d_linear_moving_behavior.hpp   gob/behaviors/t_1d_linear_moving_behavior.cpp
    gob/behaviors/t_idle_behavior.hpp               gob/behaviors/t_idle_behavior.cpp
    #
    gob/t_gob_runner.hpp                            gob/t_gob_runner.cpp
)

target_link_libraries( ai_layer PRIVATE ecs_layer )
target_include_directories ( ai_layer PUBLIC ${CMAKE_SOURCE_DIR}/ecs_layer )

include(GNUInstallDirs)
install(TARGETS ai_layer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

message("ai_layer library: ${CMAKE_INSTALL_LIBDIR}")
message("ai_layer runtime: ${CMAKE_INSTALL_LIBDIR}")
