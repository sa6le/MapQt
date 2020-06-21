#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>
#include <QtSql>
#include <QSqlQuery>

namespace Ui {
class transform;
}

class transform : public QWidget
{
    Q_OBJECT

public:
    explicit transform(QWidget *parent = nullptr);
    ~transform();

private slots:
  void obr_sendID(int);

  void on_izmenitbutton_clicked();

signals:
    void refresh_table_2();

private:
    Ui::transform *ui;
};

#endif // TRANSFORM_H
