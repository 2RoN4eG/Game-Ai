#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainWindow window;

    // window.resize(400, 400);
    window.show();

    return application.exec();
}
