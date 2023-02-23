#ifndef AppDataBase_H
#define AppDataBase_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QObject>
#include <QSettings>
#include "databasessql.h"
class AppDataBase  : public QObject
{
    Q_OBJECT

public:
   static AppDataBase * getAppDataBase ();
   ~AppDataBase ();                                                                 //<get数据库的接口
public slots:
   bool insertData(const QString sqlStr,bool &b);                                           //<数据库的增
   bool deleteData(const QString sqlStr,bool &b);                                           //<数据库的删
   bool updateData(const QString sqlStr,bool &b);                                            //<数据库的改
   bool selectData(const QString sqlStr, QList<QMap<QString,QVariant>> &valuesList ,bool& b);//<数据库的查
   bool openDatabase(const QString dbFileName);                                             //<打开数据库
   bool initDatabase();                                                             //< 初始化数据库

private:
    explicit AppDataBase (QObject * parent =nullptr) ;                               //< 读取配置文件
    AppDataBase (const AppDataBase & AppDataBase ) = delete;                         //< 单例删除拷贝
    AppDataBase & operator = (const AppDataBase &) = delete;                         //< 单例删除operator=

signals:

private:
    static AppDataBase * m_AppDataBase;


    static QString m_s_dbPath;
    static QString m_s_dbFile;
    static int     m_s_dbPort;
    static QString m_s_dbName;
    static QString m_s_dbUser;
    static QString m_s_dbPasswd;

    QString       m_qstrFilename;
    QSettings*    appSettingsInstance;
    QSqlDatabase  m_dataBase;

};

#endif // AppDataBase _H
