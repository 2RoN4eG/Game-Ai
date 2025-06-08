#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../../ecs_layer/t_game_scene.hpp"


#include "t_shooting_game_scene.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _game_scene_creator { _game_scene }   // creates
    , _projectile_collision_system { _game_scene }
    , _drawable_weapon_locating_system { _game_scene }
    , _spawn_system { _game_scene }
    , _brain_system { _game_scene }
    , _rotation { t_shooting_game_scene_get_mutable_context<t_rotation_context>(_game_scene) }
    , _drawable_weapon { t_shooting_game_scene_get_mutable_context<t_drawable_weapon_context>(_game_scene) }
{
    ui->setupUi(this);

    const t_random_area_size width            = MainWindow::width();
    const t_random_area_size half_of_width    = MainWindow::width() / 2;

    const t_random_area_size height           = MainWindow::height();
    const t_random_area_size half_of_height   = MainWindow::height() / 2;

    _spawn_system.on_game_scene_size_changed(width, half_of_height);

    _drawable_weapon_locating_system.on_game_scene_size_changed(half_of_width, height);

    connect(&timer, &QTimer::timeout, this, &MainWindow::update_systems);

    qDebug() << "run timer on " << (1000 / 60);

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

    painter.setBrush(Qt::yellow);
    painter.drawRect(0, 0, _spawn_system.width(), _spawn_system.height());

    painter.setPen(QPen(Qt::black, 7));

    t_enemy_context& _enemy = t_shooting_game_scene_get_mutable_context<t_enemy_context>(_game_scene);

    painter.drawPoint(_enemy.position.x(), _enemy.position.y());
    painter.setPen(QPen(Qt::black, 3));

    // Вычисление конечной точки на основе heading

    const t_position_context& since = _drawable_weapon.position;

    const t_position_context till = get_rotated_length_point(_drawable_weapon, _rotation);

    painter.drawLine(since.x(), since.y(), till.x(), till.y());
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    qDebug() << "MainWindow new size is " << event->size();

    const t_axis_value width            = MainWindow::width();
    const t_axis_value half_of_width    = MainWindow::width() / 2;

    const t_axis_value height           = MainWindow::height();
    const t_axis_value half_of_height   = MainWindow::height() / 2;

    _spawn_system.on_game_scene_size_changed(width, half_of_height);

    _drawable_weapon_locating_system.on_game_scene_size_changed(half_of_width, height);
}

void MainWindow::update_systems()
{
    // Передаем ~16 мс (0.016 секунд) как deltaTime

    _projectile_collision_system.update(_delta_time);

    _spawn_system.update(_delta_time);

    t_moving_system_updater(g_moving_context_holder, _delta_time);

    t_rotation_system_updater(_rotation, _delta_time);

    _brain_system.update(_delta_time);

    update();

    const t_enemy_context& enemy = t_shooting_game_scene_get_context<t_enemy_context>(_game_scene);
    if (t_is_alive(enemy))
    {
        return;
    }

    // g_ui_events.emplace_back("enemy is created on possition " + std::to_string(_enemy.x) + ", " + std::to_string(_enemy.y));
}
