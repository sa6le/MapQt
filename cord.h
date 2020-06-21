#ifndef CORD_H
#define CORD_H

#include <QObject>

class Cord : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString Latitude READ Latitude WRITE setLatitude NOTIFY LatitudeChanged)
    Q_PROPERTY (QString Longitude READ Longitude WRITE setLongitude NOTIFY LongitudeChanged)

    QString _Latitude;
    QString _Longitude;

public:
    QString Latitude(){return _Latitude;}
    QString Longitude(){return _Longitude;}
    void setLatitude(QString m1);
    void setLongitude(QString m2);

    explicit Cord(QObject *parent = nullptr);
    explicit Cord(QString m1, QString m2, QObject *parent = nullptr);


signals:
    void LatitudeChanged();
    void LongitudeChanged();


public slots:
};

#endif // CORD_H
