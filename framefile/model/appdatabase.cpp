#include "appdatabase.h"
#include "appsettings.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "appsettings.h"

AppDataBase* AppDataBase::m_AppDataBase = nullptr;
QString AppDataBase::m_s_dbPath = "./database";
QString AppDataBase::m_s_dbFile = "database.db";
int     AppDataBase::m_s_dbPort = 3306;
QString AppDataBase::m_s_dbName = "localhost";         //<sql默认信息
QString AppDataBase::m_s_dbUser = "root";
QString AppDataBase::m_s_dbPasswd = "123456";


AppDataBase ::AppDataBase (QObject *parent)
    : QObject{parent},m_dataBase(QSqlDatabase::addDatabase("QMYSQL"))
{
    m_s_dbPort =   AppSettings::getSettings(DATABASE_PORT).toInt();
    m_s_dbName =   AppSettings::getSettings(DATABASE_NAME).toString();
    m_s_dbUser =   AppSettings::getSettings(DATABASE_USER).toString();          //< 读取配置文件
    m_s_dbPasswd = AppSettings::getSettings(DATABASE_PASSWD).toString();
   // qDebug()<<m_s_dbPasswd<<123;
}

AppDataBase  *AppDataBase ::getAppDataBase()
{
    if(nullptr == m_AppDataBase){
        m_AppDataBase = new AppDataBase;}
    return m_AppDataBase;
}

bool AppDataBase::insertData(const QString sqlStr)
{

}

bool AppDataBase::deleteData(const QString sqlStr)
{

}

bool AppDataBase::updateData(const QString sqlStr)
{

}

bool AppDataBase::selectData(const QString sqlStr, QList<QMap<QString, QVariant> > &valuesList)
{

}



bool AppDataBase::openDatabase(const QString dbFileName)
{  
    m_dataBase.setHostName(m_s_dbName);
    m_dataBase.setPort(m_s_dbPort);
    m_dataBase.setUserName(m_s_dbUser);
    m_dataBase.setPassword(m_s_dbPasswd);
    m_dataBase.setDatabaseName(dbFileName);
    if(!m_dataBase.open()){
        qDebug() << m_dataBase.lastError();
        return false;}
    else{
        qDebug()<<"打开成功123";
        return true;}
}



AppDataBase ::~AppDataBase ()
{
    this->m_dataBase.close();
    QString connectiom = m_dataBase.connectionName();
    this->m_dataBase = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectiom);
}


