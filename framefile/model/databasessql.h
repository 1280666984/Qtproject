#ifndef DATABASESSQL_H
#define DATABASESSQL_H

//@
// login sql语句
//@
#define SQL_CREATE_LOGININFO QString("create table if not exists admin(username varchar(20) , password varchar(20),loginTime data")
#define SQL_INSERT_LOGININFO QString("insert into admin values(\"%1\",\"%2\",%3)")
#define SQL_UPDATE_LOGININFO QString("update admin set password=\"%1\",loginTime=%2 where username = \"%3\"")
#define SQL_SELECT_BY_LOGININFO QString("select * from admin where username = \"%1""")
#define SQL_SELECT_ALL_LOGININFO QString("select * from admin")
#define SQL_DELECT_LOGININFO QString("delete from admin where username = \"%1\"")

#endif // DATABASESSQL_H
