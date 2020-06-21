#include "worker.h"

//void worker::timerEvent(QTimerEvent *e)
//{
//    if(db.isOpen())
//    {
//        int lic = 1;
//        QSqlQuery query("SELECT * FROM \"Users\"");
//        while(query.next() && lic<licnik)
//        {
//            Cord* wsk=qobject_cast<Cord*>(_model[lic]);
//            wsk->setLatitude(query.value(5).toString());
//            wsk->setLongitude(query.value(6).toString());
//            lic++;
//        }
//    }

//}

worker::worker(QObject *parent) : QObject(parent)
{
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("362785594a");
    db.setPort(5432);

    if(db.open())
    {
        QSqlQuery query("SELECT * FROM \"Users\"");
        while (query.next())
        {
            _model.append(new Cord(query.value(5).toString(),query.value(6).toString()));
        }
        licnik = query.size();
        //this->startTimer(1000);

    }

}
