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
   bool getNext();

   bool operate(const QString cmd);
   QVariant getValue(const QString column);
   QVariant getValue(const int column);

private:
    explicit MySql(QObject * parent =nullptr) ;
    ~MySql();
    MySql(const MySql& mysql) = delete;
    MySql& operator = (MySql&) = delete;

private:
    static MySql* m_mysql;
    QSqlDatabase  m_db;
    QSqlQuery     m_query;

};

#endif // MYSQL_H
