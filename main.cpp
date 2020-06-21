#include "mainwindow.h"
#include <QApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QDebug>
#include "add.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qmlRegisterType<worker>("sable", 1, 0, "Worker");
    w.setWindowTitle("QML MAP");
    w.show();
    return a.exec();
}
