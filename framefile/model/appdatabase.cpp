#include "appdatabase.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QDebug>

QString AppDataBase::m_s_dbPath = "./database";
QString AppDataBase::m_s_dbFile = "database.db";
int     AppDataBase::m_s_dbPort = 3306;
QString AppDataBase::m_s_dbName = "localhost";
QString AppDataBase::m_s_dbUser = "root";
QString AppDataBase::m_s_dbPasswd = "1234";

AppDataBase ::AppDataBase (QObject *parent)
    : QObject{parent},m_dataBase(QSqlDatabase::addDatabase("QMYSQL")),m_query(QSqlQuery(m_dataBase))
{
    appSettingsInstance = new QSettings("Config.ini",QSettings::IniFormat,this);
//    m_s_dbPath =   appSettingsInstance->value().toString();
//    m_s_dbFile =   appSettingsInstance->value().toString();
//    m_s_dbPort =   appSettingsInstance->value().toInt();
//    m_s_dbName =   appSettingsInstance->value().toString();
//    m_s_dbUser =   appSettingsInstance->value().toString();
//    m_s_dbPasswd = appSettingsInstance->value().toString();
}
AppDataBase* AppDataBase::m_AppDataBase = nullptr;
AppDataBase  *AppDataBase ::getAppDataBase()
{
    if(nullptr == m_AppDataBase){
        m_AppDataBase = new AppDataBase;}
    return m_AppDataBase;
}



bool AppDataBase::openDatabase(const QString dbFileName)
{
    m_dataBase.setHostName("localhost");
    m_dataBase.setPort(3306);
    m_dataBase.setUserName("root");
    m_dataBase.setPassword("123456");

}



AppDataBase ::~AppDataBase ()
{
    this->m_dataBase.close();
    QString connectiom = m_dataBase.connectionName();
    this->m_dataBase = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectiom);
}


