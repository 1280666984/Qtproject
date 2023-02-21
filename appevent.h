#ifndef APPEVENT_H
#define APPEVENT_H

#include <QObject>

class appevent : public QObject
{
    Q_OBJECT
public:
    explicit appevent(QObject *parent = nullptr);

signals:

};

#endif // APPEVENT_H
