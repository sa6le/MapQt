#include "add.h"
#include "ui_add.h"
#include <QDebug>
#include <QSqlError>


add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;

}

void add::on_addbutton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
        query->prepare("INSERT INTO \"Users\" (\"Name\",\"Surname\",\"Number\",\"Mail\",\"Latitude\",\"Longitude\") VALUES(:Name,:Surname,:Number,:Mail,:Latitude,:Longitude)");
        query->bindValue(":Name",ui->lineEdit->text());
        query->bindValue(":Surname",ui->lineEdit_2->text());
        query->bindValue(":Number",ui->lineEdit_3->text());
        query->bindValue(":Mail",ui->lineEdit_4->text());
        query->bindValue(":Latitude",ui->lineEdit_5->text());
        query->bindValue(":Longitude",ui->lineEdit_6->text());
        query->exec();
        emit refresh_table();
        qDebug() << query->lastError();
        delete query;

}

