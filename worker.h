#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <cord.h>
#include <QtSql>

class worker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> model READ model NOTIFY modelChanged)
    QSqlDatabase db;
    QList<QObject*>_model;
    //void timerEvent(QTimerEvent *e);
    int licnik;
public:
    explicit worker(QObject *parent = nullptr);
    QList<QObject*>model(){return _model;}

signals:
    void modelChanged();

public slots:
};

#endif // WORKER_H
