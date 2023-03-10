#ifndef LoginModule_H
#define LoginModule_H
#include <QObject>
#include <QMap>
#include <QVariant>
#include "appdatabase.h"


class LoginModule : public QObject
{
    Q_OBJECT
public:   
    explicit LoginModule(QObject *parent = nullptr);
//    LoginModule( const LoginModule & LoginModule );
//    LoginModule& operator =(LoginModule&);
    ~LoginModule();


private:


public slots:   
    void slot_ControlInsertQueryUser(const QString m_b_QueryUser);
    void slot_ControlInsertUser(const QString username,const QString password);
    void slot_ControlInsertIogin(const QString loginname,const QString password);

    void slot_ControlInsertQueryUserFilshes();
    void slot_ControlInsertUserFilshes();
    void slot_ControlInsertIoginFilshes();


signals:
    void signal_DataBaseInserQueryUser(const QString sqlstr,QList<QMap<QString,QVariant>> &valuesList,bool& m_b_QueryUser);
    void signal_DataBaseInsertUser(const QString sqlstr , bool& m_b_signup);  //<< 数据库信号
    void signal_DataBaseInsertLogin(const QString sqlstr,QList<QMap<QString,QVariant>> &valuesList ,bool& m_b_login);

    void signal_DataBAseInseerQueryUserFilshes(const bool m_b_QueryUser);
    void signal_DataBaseInsertUSerFilshes(const bool m_b_signup);
    void signal_DataBaseInsertLoginFilshes(const bool m_b_login);


private:
    bool m_b_QueryUser;
    bool m_b_login;
    bool m_b_signup;
    QList<QMap<QString,QVariant>> valuseList;
};

#endif // LoginModule_H
