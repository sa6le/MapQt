#include "mainwindow.h"
#include <QApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qml://map.qml")));

    return app.exec();

}
