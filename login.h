#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    QMessageBox* mes; // Объект mes

private slots:
    void on_connect_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db; //Объект для связи с БД статический

};

#endif // LOGIN_H
