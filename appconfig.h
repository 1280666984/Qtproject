#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>

// loginInfo
#define SQL_CREATE_LOGININFO QString("create table if not exists loginInfo(user text primary key unique,password text,loginTime date)")
#define SQL_INSERT_LOGININFO QString("insert into loginInfo values(\"%1\",\"%2\",%3)")
#define SQL_UPDATE_LOGININFO QString("update loginInfo set password=\"%1\",loginTime=%2 where user=\"%3\"")
#define SQL_SELECT_LOGININFO_BY_USER QString("select * from loginInfo where user=\"%1\"")
#define SQL_SELECT_LOGININFO_ALL QString("select * from loginInfo")
#define SQL_DELETE_LOGININFO_BY_USER QString("delete from loginInfo where user=\"%1\"")

// userInfo
#define SQL_CREATE_USERINFO QString("create table if not exists userInfo(workerno text primary key unique,workername text,password text,serverlevel text)")
#define SQL_INSERT_USERINFO QString("insert into userInfo values(\"%1\",\"%2\",\"%3\",\"%4\")")
#define SQL_UPDATE_USERINFO QString("update userInfo set workername=\"%1\",password=\"%2\",serverlevel=\"%3\" where workerno=\"%4\"")
#define SQL_SELECT_USERINFO_BY_USER QString("select * from userInfo where workerno=\"%1\"")
#define SQL_SELECT_USERINFO_ALL QString("select * from userInfo")
#define SQL_DELETE_USERINFO_BY_USER QString("delete from userInfo where workerno=\"%1\"")
#define SQL_DELETE_USERINFO_ALL QString("delete from userInfo")


class appconfig : public QObject
{
    Q_OBJECT
public:
    explicit appconfig(QObject *parent = nullptr);

signals:

};

#endif // APPCONFIG_H
