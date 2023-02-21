#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QVariant>
#include <QObject>
class MySql:public QObject
{
public:
   static MySql* getMysql();
   bool open();
   void close();
   bool operate(QString cmd);
   bool getNext();
   QVariant getValue(QString column);
   QVariant getValue(int  column);

private:
    explicit MySql(QObject * parent =nullptr) ;
    MySql(const MySql& mysql) = delete;
    MySql& operator = (MySql&) = delete;

private:
    static MySql* mysql;
    QSqlDatabase  db;
    QSqlQuery   query;

};

#endif // MYSQL_H
