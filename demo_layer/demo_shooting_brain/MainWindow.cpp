#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../../ecs_layer/t_game_scene.hpp"


#include "t_shooting_game_scene.hpp"
#include "t_removing_projectile_system.hpp"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _game_scene_creator { _game_scene }               // creates
    , _projectile_moving_system { _game_scene }         //
    , _projectile_collision_system { _game_scene }      //
    , _drawable_weapon_locating_system { _game_scene }  //
    , _enemy_spawn_system { _game_scene }               //
    , _shooting_ai_brain_system { _game_scene }         //
    , _removing_projectile_system { _game_scene }       //
    , _weapon_cooldown_system { _game_scene }
    , _rotation { get_shooting_brain_game_scene_mutable_context<t_rotation_context>(_game_scene) }
    , _drawable_weapon { get_shooting_brain_game_scene_mutable_context<t_drawable_weapon_context>(_game_scene) }
{
    ui->setupUi(this);

    const t_random_area_size width            = MainWindow::width();
    const t_random_area_size half_of_width    = MainWindow::width() / 2;

    const t_random_area_size height           = MainWindow::height();
    const t_random_area_size half_of_height   = MainWindow::height() / 2;

    _enemy_spawn_system.on_game_scene_size_changed(width, half_of_height);

    _drawable_weapon_locating_system.on_game_scene_size_changed(half_of_width, height);

    connect(&timer, &QTimer::timeout, this, &MainWindow::update_systems);

    timer.start(1000 / 60); // Примерно 60 FPS (каждые ~16 мс)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    //

    painter.setBrush(Qt::yellow);
    painter.drawRect(0, 0, _enemy_spawn_system.width(), _enemy_spawn_system.height());

    //

    t_enemy_context& _enemy = get_shooting_brain_game_scene_mutable_context<t_enemy_context>(_game_scene);

    painter.setPen(QPen(Qt::black, 7));
    painter.drawPoint(_enemy.position.x(), _enemy.position.y());
    
    // Вычисление конечной точки на основе heading

    const t_position_context& since = _drawable_weapon.position;
    const t_position_context till = get_rotated_length_point(_drawable_weapon, _rotation);

    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(since.x(), since.y(), till.x(), till.y());

    //

    try
    {
        const t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_entry_holder<t_projectile_context>();

        painter.setPen(QPen(Qt::blue, 7));

        for (const t_projectile_context& projectile : projectile_holder)
        {
            painter.drawPoint(projectile._position.x(), projectile._position.y());
        }
    }
    catch (...)
    {
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    qDebug() << "MainWindow new size is " << event->size();

    const t_axis_value width            = MainWindow::width();
    const t_axis_value half_of_width    = MainWindow::width() / 2;

    const t_axis_value height           = MainWindow::height();
    const t_axis_value half_of_height   = MainWindow::height() / 2;

    _enemy_spawn_system.on_game_scene_size_changed(width, half_of_height);

    _drawable_weapon_locating_system.on_game_scene_size_changed(half_of_width, height);

    // TODO: Вычислить новую линию (орудие), новую точку врага, новую зону появления врага
}

void MainWindow::update_systems()
{
    // Передаем ~16 мс (0.016 секунд) как deltaTime

    _projectile_moving_system.update(_delta_time);

    _projectile_collision_system.update(_delta_time);

    _removing_projectile_system.update(_delta_time);

    _enemy_spawn_system.update(_delta_time);

    // t_game_scene_deleting_system system {};

    t_moving_system_updater(g_moving_context_holder, _delta_time);

    t_rotation_system_updater(_rotation, _delta_time);

    _shooting_ai_brain_system.update(_delta_time);

    _weapon_cooldown_system.update(_delta_time);

    update();
}
