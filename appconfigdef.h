#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QString>

#include <QCoreApplication>

#define CONFIG_FILE_NAME QString("./config/database.ini")


#define DATABASE_PATH QString("APPDATABASE_CONGIF/path")  //数据库存放路径，./为运行程序所在目录
#define DATABASE_FILE QString()  //SQLITE数据库文件


#define DATABASE_PORT QString("APPDATABASE_CONGIF/dbuser")   //数据库端口
#define DATABASE_NAME QString("APPDATABASE_CONGIF/dbname")  //数据库名
#define DATABASE_USER QString("APPDATABASE_CONGIF/dbuser")  //用户名
#define DATABASE_PASSWD QString("APPDATABASE_CONGIF/dbpasswd")  //密码
QString q();

//    m_qstrFilename = QString(QCoreApplication::applicationDirPath() + "/Config.ini");
#endif // APPCONFIG_H
