#include "cord.h"

void Cord::setLatitude(QString m1)
{
    if(m1==_Latitude) return;
    _Latitude=m1;
    emit LatitudeChanged();
}

void Cord::setLongitude(QString m2)
{
    if(m2==_Longitude) return;
    _Longitude=m2;
    emit LongitudeChanged();

}

Cord::Cord(QObject *parent) : QObject(parent)
{
    _Latitude=1;
    _Longitude=1;
}

Cord::Cord(QString m1, QString m2, QObject *parent) : QObject(parent)
{
    _Latitude=m1;
    _Longitude=m2;
}
