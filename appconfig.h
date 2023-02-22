#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>




class appconfig : public QObject
{
    Q_OBJECT
public:
    explicit appconfig(QObject *parent = nullptr);

signals:

};

#endif // APPCONFIG_H
