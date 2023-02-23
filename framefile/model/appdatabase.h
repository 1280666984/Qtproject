#ifndef AppDataBase_H
#define AppDataBase_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QObject>
#include <QSettings>

class AppDataBase  : public QObject
{
    Q_OBJECT

public:
   static AppDataBase * getAppDataBase ();

   bool insertData(const QString sqlStr);
   bool deleteData(const QString sqlStr);
   bool updateData(const QString sqlStr);
   bool selectData(const QString sqlStr, QList<QMap<QString,QVariant>> &valuesList);
   bool openDatabase(const QString dbFileName);
   bool initDatabase();


  ~AppDataBase ();

private:
    explicit AppDataBase (QObject * parent =nullptr) ;
    AppDataBase (const AppDataBase & AppDataBase ) = delete;
    AppDataBase & operator = (const AppDataBase &) = delete;

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
