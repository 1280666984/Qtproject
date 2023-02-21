#include "mysql.h"
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>

MySql * MySql::m_mysql= new MySql;
MySql::MySql(QObject *parent):QObject(parent),m_db(QSqlDatabase::addDatabase("QMYSQL")),m_query(QSqlQuery(m_db))
{
    m_db.setHostName("localhost");
    m_db.setPort(3306);
    m_db.setUserName("root");
    m_db.setPassword("123456");
    QSettings * appSettingsInstance = new QSettings("Config.ini",QSettings::IniFormat,this);
}

MySql::~MySql()
{
   this->m_db.close();
   QString connectiom = m_db.connectionName();
   this->m_db = QSqlDatabase();
   QSqlDatabase::removeDatabase(connectiom);
}


MySql * MySql::getMysql()
{
    return m_mysql;
}

bool MySql::open()
{
    m_db.setDatabaseName("text");
    return m_db.open();
}

void MySql::close()
{
    m_db.close();
}

bool MySql::operate(const QString cmd)
{
    bool res = m_query.exec(cmd);
    return res;    
}
bool MySql::getNext()
{
    if(m_query.next()){
    return true;   }
    else{
    return false;
    }
}
QVariant MySql::getValue(const QString column)
{
    return m_query.value(column);
}

QVariant MySql::getValue(const int column)
{
  return m_query.value(column);
}
