#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->lineEdit->setText("localhost");
    ui->lineEdit_2->setText("postgres");
    ui->lineEdit_3->setText("postgres");
    ui->lineEdit_4->setText("362785594a");
    ui->lineEdit_5->setText("5432");
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    mes = new QMessageBox();

}

login::~login()
{
    delete ui;
    delete mes;
}

void login::on_connect_clicked() // Нажатие на кнопку коннект соединение с БД
{
    QSqlDatabase tmpbd = QSqlDatabase::database();
    if(tmpbd.isOpen())
    {
    tmpbd.close();
    }
    db = QSqlDatabase::addDatabase("QPSQL"); // Библиотека датабасе метод адд для подключения драйвера постгреса

       db.setHostName(ui->lineEdit->text());
      db.setDatabaseName(ui->lineEdit_2->text());
      db.setUserName(ui->lineEdit_3->text());
       db.setPassword(ui->lineEdit_4->text());
       db.setPort(ui->lineEdit_5->text().toInt());

       if(db.open()) // Метод опен
       {
           mes->setText("Соединилось"); //Метод сеттекст

       }
      else
       {
           mes->setText("Соединение не установлено");
       }
       qDebug() << db.lastError();
       mes->show();

}

