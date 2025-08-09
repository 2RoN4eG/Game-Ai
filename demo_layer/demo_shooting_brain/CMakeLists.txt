cmake_minimum_required(VERSION 3.5)

project(demo_shooting_brain VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


# TODO: rename to t_{ * }ing_{ component name }_system

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp MainWindow.h
        MainWindow.ui

        t_component_contexts_and_systems.hpp    t_component_contexts_and_systems.cpp

        t_shooting_game_scene.hpp               t_shooting_game_scene.cpp
        t_shooting_game_scene_creator.hpp       t_shooting_game_scene_creator.cpp

        t_remove_projectile_event.hpp           t_remove_projectile_event.cpp

        t_shooting_ai_brain_system.hpp          t_shooting_ai_brain_system.cpp

        t_enemy_spawn_system.hpp                t_enemy_spawn_system.cpp
        t_drawable_weapon_locating_system.hpp   t_drawable_weapon_locating_system.cpp
        t_colliding_projectile_system.hpp       t_colliding_projectile_system.cpp
        t_projectile_moving_system.hpp          t_projectile_moving_system.cpp
        t_removing_projectile_system.hpp        t_removing_projectile_system.cpp
        t_weapon_cooldown_system.hpp            t_weapon_cooldown_system.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(demo_shooting_brain
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET demo_shooting_brain APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(demo_shooting_brain SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(demo_shooting_brain
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(demo_shooting_brain PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(demo_shooting_brain PRIVATE ecs_layer ai_layer)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.demo_shooting_brain)
endif()

set_target_properties(demo_shooting_brain PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS demo_shooting_brain
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(demo_shooting_brain)
endif()
