#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <cmath>

#include "t_component_contexts_and_systems.hpp"
#include "t_shooting_ai_brain_system.hpp"
#include "t_shooting_game_scene.hpp"
#include "t_enemy_spawn_system.hpp"
#include "t_shooting_game_scene_creator.hpp"
#include "t_drawable_weapon_locating_system.hpp"
#include "t_projectile_collision_system.hpp"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    const t_axis_value line_length { 50.0 }; // Длина линии

    QTimer timer;

    t_axis_value _delta_time { 1. / 60. };

    t_shooting_game_scene _game_scene;

    t_shooting_game_scene_creator _game_scene_creator;

    t_projectile_collision_system _projectile_collision_system;

    t_drawable_weapon_locating_system _drawable_weapon_locating_system;

    t_rotation_context& _rotation;

    t_drawable_weapon_context& _drawable_weapon;

    t_enemy_spawn_system _spawn_system;

    t_shooting_ai_brain_system _brain_system;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*) override;

    void resizeEvent(QResizeEvent*) override;

private slots:
    void update_systems();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
