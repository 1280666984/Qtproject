#ifndef DATABASESSQL_H
#define DATABASESSQL_H

//@
// login sql语句
//@
#define SQL_CREATE_LOGININFO QString("create table if not exists loginadmin(username text  , password text ,loginTime data")
#define SQL_INSERT_LOGININFO QString("insert into loginadmin values('%1','%2','%3'")
#define SQL_UPDATE_LOGININFO QString("update loginadmin set password= '%1,loginTime='%2' where username = '%3'")
#define SQL_SELECT_BY_LOGININFO QString("select * from loginadmin where username = '%1'")
#define SQL_SELECT_ALL_LOGININFO QString("select * from loginadmin")
#define SQL_DELECT_LOGININFO QString("delete from loginadmin where username = '%1'")

// user sql语句
#define SQL_CREATE_USERINFO QString("create table if not exists useradmin(username text primary key, password text,workername text , serverlevel text")
#define SQL_INSERT_USERINFO QString("insert into useradmin values('%1','%2','%3','%4'")
#define SQL_UPDATE_USERINFO QString("update useradmin set username= '%1,password = '%2', workername= '%3',serverlevel = '%4' where username = '%5'amd password = '%6' ")
#define SQL_SELECT_USERINFO_USER QString("select * from useradmin where username = '%1'")
#define SQL_SELECT_USERINFO_USER_PASS QString("select *from useradmin where username = '%1'and password = '%2")
#define SQL_SELECT_ALL_USERINFO QString("select * from useradmin")
#define SQL_DELECT_USERINFO QString("delete from useradmin where username = '%1'")
#define SQL_DELECT_USERINFO_ALL QString("delete from useradmin ")
#endif // DATABASESSQL_H
