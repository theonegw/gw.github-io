#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("2048");
    w.setFixedSize(320,480);
    w.show();

    return a.exec();
}
