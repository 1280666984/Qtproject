#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>

class appinit : public QObject
{
    Q_OBJECT
public:
    explicit appinit(QObject *parent = nullptr);

signals:

};

#endif // APPINIT_H
