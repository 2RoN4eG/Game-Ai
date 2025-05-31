#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <cmath>

#include "t_component_contexts_and_systems.hpp"


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
    QPoint startPoint; // Фиксированная начальная точка

    const t_axis_value line_length { 50.0 }; // Длина линии

    t_rotation_context _rotation_context { 0.0, 0.0, 20.0 }; // Инициализация структуры

    QTimer timer;

    QSize _random_area_size {};

    t_enemy_context _enemy {};

    t_weapon_context _weapon {};

    t_axis_value _delta_time { 1. / 60. };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void resizeEvent(QResizeEvent*) override;

private slots:
    void updateRotation();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
