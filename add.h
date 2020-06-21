#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();



private slots:

    void on_addbutton_clicked();

signals:
    void refresh_table(); //сигнал для обновления таблицы (Вызов из окна "add ui" а приходит сигнал в mainwindow

private:
    Ui::add *ui;
};

#endif // ADD_H
