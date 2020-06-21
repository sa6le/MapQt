#include "transform.h"
#include "ui_transform.h"
#include <QSqlQuery>
#include <QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"

transform::transform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transform)
{
    ui->setupUi(this);
}

transform::~transform()
{
    delete ui;
}

void transform::obr_sendID(int aa)
{
  QSqlQuery* query = new QSqlQuery();
  query->prepare("SELECT \"Name\",\"Surname\",\"Number\",\"Mail\",\"Latitude\",\"Longitude\" FROM \"Users\" WHERE id=?");
  query->bindValue(0,aa);


  if(query->exec())
  {
     query->next();
     ui->lineEdit->setText(QString::number(aa));
     ui->lineEdit_2->setText(query->value(0).toString());
     ui->lineEdit_3->setText(query->value(1).toString());
     ui->lineEdit_4->setText(query->value(2).toString());
     ui->lineEdit_5->setText(query->value(3).toString());
     ui->lineEdit_6->setText(query->value(4).toString());
     ui->lineEdit_7->setText(query->value(5).toString());
  }
delete query;
}

void transform::on_izmenitbutton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("UPDATE \"Users\" SET \"Name\"=?, \"Surname\"=?, \"Number\"=?, \"Mail\"=?, \"Latitude\"=?, \"Longitude\"=? WHERE id=?");
    query->bindValue(0,ui->lineEdit_2->text());
    query->bindValue(1,ui->lineEdit_3->text());
    query->bindValue(2,ui->lineEdit_4->text());
    query->bindValue(3,ui->lineEdit_5->text());
    query->bindValue(4,ui->lineEdit_6->text());
    query->bindValue(5,ui->lineEdit_7->text());
    query->bindValue(6,ui->lineEdit->text().toInt());
    qDebug() << query->lastError();
    if(query->exec())
    {
     emit refresh_table_2();
    }
    delete query;
}
