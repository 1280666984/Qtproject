#ifndef SAVELOG_H
#define SAVELOG_H

#include <QObject>

class savelog : public QObject
{
    Q_OBJECT
public:
    explicit savelog(QObject *parent = nullptr);

signals:

};

#endif // SAVELOG_H
