#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <login.h>
#include <ui_login.h>
#include <QSqlQueryModel>
#include "add.h"
#include "ui_add.h"
#include "transform.h"
#include "ui_transform.h"
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QQuickWidget>
#include <cord.h>
#include <worker.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    login* logwin; // Класс* объект - отвечает за класс окна соединения
    add* dobzap; // переменная добзап для открытия окна "добавить" при нажатии на "+" от класса add
    transform* izm;
    int globid;
    transform* izmzap; // Для сигнал/слот обновления таблицы после изименения
    QQuickWidget* m_quickWidget;

private slots:
    void on_action_triggered();


    void on_people_clicked();

    void on_add_clicked();

    void obr_ref_tab(); //Слот для принятия сигнала refresh_table

    void on_transform_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Delete_clicked();

    void on_pushButton_clicked();

signals:
    void sendID(int);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* model;// объект от класса QSqlquerymodel
};

#endif // MAINWINDOW_H
