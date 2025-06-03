#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../../ecs_layer/t_game_scene.hpp"

#include "t_shooting_game_scene.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , startPoint { width() / 2, height() }
    , _random_area_size { width(), height() / 2 }
    , _game_scene_creator { _game_scene }
    , _spawn_system { _game_scene, _random_area_size.width(), _random_area_size.height() }
    , _brain_system { _game_scene }
    , _player { t_shooting_game_scene_get_mutable_context<t_player_context>(_game_scene) }
    , _enemy { t_shooting_game_scene_get_mutable_context<t_enemy_context>(_game_scene) }
    , _weapon { t_shooting_game_scene_get_mutable_context<t_weapon_context>(_game_scene) }
    , _drawable_weapon { t_shooting_game_scene_get_mutable_context<t_drawable_weapon_context>(_game_scene) }
    , _rotation { t_shooting_game_scene_get_mutable_context<t_rotation_context>(_game_scene) }
{
    ui->setupUi(this);

    connect(&timer, &QTimer::timeout, this, &MainWindow::updateRotation);

    qDebug() << "run timer on " << (1000 / 60);

    timer.start(1000 / 60); // Примерно 60 FPS (каждые ~16 мс)

    qDebug() << "main window size is " << size() << ", start position is " << startPoint;

    _spawn_system.set_ramdom_area_size(width(), height() / 2);
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
    painter.drawRect(QRect { 0, 0, _random_area_size.width(), _random_area_size.height() });

    painter.setPen(QPen(Qt::black, 7));

    painter.drawPoint(QPointF { _enemy.position.x(), _enemy.position.y() });

    painter.setPen(QPen(Qt::black, 3));

    // Вычисление конечной точки на основе heading

    QPointF endPoint
    (
        startPoint.x() + line_length * std::cos(_rotation._heading * M_PI / 180.),
        startPoint.y() + line_length * std::sin(_rotation._heading * M_PI / 180.)
    );

    painter.drawLine(startPoint, endPoint);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    // qDebug() << "resize event contains size " << event->size();

    startPoint = { width() / 2, height() };

    _random_area_size = { width(), height() / 2 };

    _spawn_system.set_ramdom_area_size(width(), height() / 2);

    // qDebug() << "main window size is " << size() << ", start position is " << startPoint;
}

void MainWindow::updateRotation()
{
    // Передаем ~16 мс (0.016 секунд) как deltaTime

    _spawn_system.update(_delta_time);

    t_moving_system_updater(g_moving_context_holder, _delta_time);

    t_rotation_system_updater(_rotation, _delta_time);

    _brain_system.update(_delta_time);

    update();

    if (t_is_alive(_enemy))
    {
        return;
    }

    // g_ui_events.emplace_back("enemy is created on possition " + std::to_string(_enemy.x) + ", " + std::to_string(_enemy.y));

    const QPointF targetVector = QPointF(_enemy.position.x(), _enemy.position.y()) - startPoint;

    _rotation._course = std::atan2(targetVector.y(), targetVector.x()) * 180.0 / M_PI;
}
