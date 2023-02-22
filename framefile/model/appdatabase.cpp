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
QString AppDataBase::m_s_dbPasswd = "123456";

AppDataBase ::AppDataBase (QObject *parent)
    : QObject{parent},m_dataBase(QSqlDatabase::addDatabase("QMYSQL")),m_query(QSqlQuery(m_dataBase))
{
    m_qstrFilename = QString(QCoreApplication::applicationDirPath() + "/Config.ini");
    appSettingsInstance = new QSettings(m_qstrFilename,QSettings::IniFormat);
    qDebug()<<m_qstrFilename;

    // appSettingsInstance->beginGroup("APPDATABASE_CONGIF");
    //  int size = appSettingsInstance->beginReadArray("APPDATABASE_CONGIF");
    //    for(int i = 0 ;i < 4; i++ ){
    //        appSettingsInstance->setArrayIndex(i);
    //        m_s_dbPort =   appSettingsInstance->value("dbport").toInt();
    //        m_s_dbName =   appSettingsInstance->value("dbname").toString();
    //        m_s_dbUser =   appSettingsInstance->value("dbuser").toString();
    //        m_s_dbPasswd = appSettingsInstance->value("dbpasswd").toString();
    //   appSettingsInstance->endGroup();
    //    }
//    appSettingsInstance->endArray();

      appSettingsInstance->beginGroup("APPDATABASE_CONGIF");
      m_s_dbPort =   appSettingsInstance->value("dbport").toInt();
      m_s_dbName =   appSettingsInstance->value("dbname").toString();
      m_s_dbUser =   appSettingsInstance->value("dbuser").toString();
      m_s_dbPasswd = appSettingsInstance->value("dbpasswd").toString();
      appSettingsInstance->endGroup();
      qDebug()<<m_s_dbPasswd<<123;
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
    m_dataBase.setDatabaseName(dbFileName);
    m_dataBase.setHostName(m_s_dbName);
    m_dataBase.setPort(m_s_dbPort);
    m_dataBase.setUserName(m_s_dbUser);
    m_dataBase.setPassword(m_s_dbPasswd);
    if(!m_dataBase.open()){
        return false;}
    else{ return true;}
}



AppDataBase ::~AppDataBase ()
{
    this->m_dataBase.close();
    QString connectiom = m_dataBase.connectionName();
    this->m_dataBase = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectiom);
}


