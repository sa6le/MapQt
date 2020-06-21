#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "ui_add.h"
#include "transform.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "ui_widget.h"
#include "worker.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete logwin;
    delete izm;
    delete izmzap;
    delete dobzap;
    delete model;
    delete m_quickWidget;
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
globid = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt();
}


void MainWindow::on_action_triggered() // Меню-> Окно соединения
{
    logwin = new login(); // С помощью конструктора new физически создаем объект logwin от класса login
    logwin ->show();
}

void MainWindow::on_people_clicked() // вывод данных из таблицы БД
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM \"Users\"");
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_add_clicked() // жмем на + чтобы открыть окно добавить
{
    dobzap = new add();
    connect(dobzap,SIGNAL(refresh_table()),this,SLOT(obr_ref_tab()));
    dobzap->show();
}
void MainWindow::obr_ref_tab()
{
  on_people_clicked();
}

void MainWindow::on_transform_clicked()
{
    izm = new transform();
    connect(this, SIGNAL(sendID(int)), izm, SLOT(obr_sendID(int)));
    emit sendID(globid);
    connect(izm,SIGNAL(refresh_table_2()),this,SLOT(obr_ref_tab()));
    izm->show();

    disconnect(this, SIGNAL(sendID(int)), izm, SLOT(obr_sendID(int)));
}


void MainWindow::on_Delete_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("DELETE FROM \"Users\" WHERE id=?");
    query->bindValue(0,globid);

    if(query->exec())
    {
        on_people_clicked();
    }
    delete query;
}

void MainWindow::on_pushButton_clicked()
{
    m_quickWidget = new QQuickWidget();
    qmlRegisterType<worker>("sable", 1, 0, "Worker");
    m_quickWidget->setSource(QUrl("qrc:/main.qml"));
    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    m_quickWidget->show();
}

