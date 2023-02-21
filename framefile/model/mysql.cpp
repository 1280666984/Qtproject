#include "mysql.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>

MySql * MySql::mysql= new MySql;
MySql::MySql(QObject *parent):QObject(parent),db(QSqlDatabase::addDatabase("QMYSQL")),query(QSqlQuery(db))
{
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
}


MySql * MySql::getMysql()
{
    return mysql;
}

bool MySql::open()
{
    db.setDatabaseName("text");
    return db.open();
}

void MySql::close()
{
    db.close();
}

bool MySql::operate(QString cmd)
{
    bool res = query.exec(cmd);
    return res;    
}
bool MySql::getNext()
{
    if(query.next()){
    return true;   }
    else{
    return false;
    }
}
QVariant MySql::getValue(QString column)
{
    return query.value(column);
}

QVariant MySql::getValue(int column)
{
  return query.value(column);
}
