#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../../ecs_layer/t_game_scene.hpp"

#include "t_shooting_game_scene.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , startPoint { width() / 2, height() }
    , _enemy {}
{
    ui->setupUi(this);

    setMouseTracking(true);
    connect(&timer, &QTimer::timeout, this, &MainWindow::updateRotation);

    qDebug() << "run timer on " << (1000 / 60);

    timer.start(1000 / 60); // Примерно 60 FPS (каждые ~16 мс)

    qDebug() << "main window size is " << size() << ", start position is " << startPoint;
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
        startPoint.x() + line_length * std::cos(_rotation_context.heading * M_PI / 180),
        startPoint.y() + line_length * std::sin(_rotation_context.heading * M_PI / 180)
    );

    painter.drawLine(startPoint, endPoint);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    // Вычисление целевого угла (course) к курсору

    qDebug() << "mouse move event on possiotion " << event->pos();

    const QPointF targetVector = event->pos() - startPoint;

    _rotation_context.course = std::atan2(targetVector.y(), targetVector.x()) * 180.0 / M_PI;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    // qDebug() << "resize event contains size " << event->size();

    startPoint = { width() / 2, height() };

    _random_area_size = { width(), height() / 2 };

    // qDebug() << "main window size is " << size() << ", start position is " << startPoint;
}

void MainWindow::updateRotation()
{
    // Передаем ~16 мс (0.016 секунд) как deltaTime

    t_moving_system_updater(g_moving_context_holder, _delta_time);

    t_rotation_system_updater(_rotation_context, _delta_time);

    update();

    t_ai_system_updater(_delta_time);

    if (t_is_course_reached(_rotation_context) == false)
    {
        return;
    }

    if (t_is_alive(_enemy))
    {
        t_shooting_game_scene game_scene {};

        t_shooting_system_updater(game_scene, _weapon, _delta_time);

        const float damage { 100.f / 5.f * _delta_time };

        // qDebug() << "damage is " << damage << ", frames require " << (_enemy.health_points / damage);

        _enemy.health_points -= damage;

        return;
    }

    _enemy = t_get_random_enemy(0, _random_area_size.width(), 0, _random_area_size.height());

    // g_ui_events.emplace_back("enemy is created on possition " + std::to_string(_enemy.x) + ", " + std::to_string(_enemy.y));

    const QPointF targetVector = QPointF(_enemy.position.x(), _enemy.position.y()) - startPoint;

    _rotation_context.course = std::atan2(targetVector.y(), targetVector.x()) * 180.0 / M_PI;


}
