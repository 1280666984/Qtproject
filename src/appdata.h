#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>

class appdata : public QObject
{
    Q_OBJECT
public:
    explicit appdata(QObject *parent = nullptr);

signals:

};

#endif // APPDATA_H
