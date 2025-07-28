#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

#include <QPaintEvent>
#include <QPainter>

#include "../../ecs_layer/t_game_scene.hpp"


constexpr QSize t_shell_size { 2, 2 };

constexpr size_t t_gun_line_length { 20 };

constexpr QSize t_turret_size { 20, 50 };

constexpr QSize t_chassis_size { 20, 50 };


struct t_hud_component
{
    bool is_flamed {};      // машина горит

    bool is_shocked {};     // экипаж контужен

    bool is_illuminated {}; // машина засвечена
};


void draw_shell(const t_game_scene& scene, QPainter& painter)
{
}

void draw_gun(const t_game_scene& scene, QPainter& painter)
{
}

void draw_turret(const t_game_scene& scene, QPainter& painter)
{
    QPen pen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap);

    painter.setPen(pen);
    painter.drawEllipse(0, 0, t_gun_line_length, t_gun_line_length);
}

void draw_chassis(const t_game_scene& scene, QPainter& painter)
{
    QPen pen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap);

    const int x = {};
    const int y = {};

    const int w = {};
    const int h = {};

    painter.setPen(pen);
    painter.drawRect(x, y, t_gun_line_length * 2, t_gun_line_length);
}

void draw_hud(const t_game_scene& scene, QPainter& painter)
{
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    t_game_scene scene {};

    draw_chassis(scene, painter);

    draw_turret(scene, painter);

    draw_gun(scene, painter);
}
