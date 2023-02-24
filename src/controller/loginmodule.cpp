#include "loginmodule.h"
#include <QDebug>
#include <QString>
#include <QRandomGenerator>


LoginModule::LoginModule(QObject *parent)
    : QObject{parent}
{
    this->m_b_QueryUser = false;
    this->m_b_login = false;
    this->m_b_signup = false;
}

//LoginModule::~LoginModule(){}


void LoginModule::slot_ControlInsertQueryUser(const QString username)
{
    QString sqlstr = QString(SQL_SELECT_BY_LOGININFO).arg(username);
    qDebug()<<sqlstr;
    emit signal_DataBaseInserQueryUser(sqlstr,valuseList,m_b_QueryUser);
}

void LoginModule::slot_ControlInsertUser(const QString username, const QString password)
{
    QString randstr = QString::number(QRandomGenerator::global()->bounded(10000));
    QString randadmin = QString::number((QRandomGenerator::global()->bounded(10000) % 2));
    QString sqlstr = QString(SQL_INSERT_USERINFO).arg(randstr,username,password,randadmin);
    qDebug()<<sqlstr<<123;
    emit signal_DataBaseInsertUser(sqlstr,m_b_signup);
}

void LoginModule::slot_ControlInsertIogin(const QString loginname, const QString password)
{
    QString sqlstr = QString(SQL_SELECT_USERINFO_USER_PASS).arg(loginname,password);
    qDebug()<<sqlstr<<123;
    emit signal_DataBaseInsertLogin(sqlstr,valuseList,m_b_login);

}

void LoginModule::slot_ControlInsertQueryUserFilshes()
{
 if(!m_b_QueryUser){
     qDebug("[login] %s",qPrintable("注册失败账号重复"));
 }

 emit signal_DataBAseInseerQueryUserFilshes(this->m_b_QueryUser);
}

void LoginModule::slot_ControlInsertUserFilshes()
{
    if(!m_b_signup){
        qDebug("[login] %s",qPrintable("注册失败"));
    }

    emit signal_DataBaseInsertLoginFilshes(this->m_b_signup);
}

void LoginModule::slot_ControlInsertIoginFilshes()
{
    if(!m_b_login){
        qDebug("[login] %s",qPrintable("登录失败"));
    }

    emit signal_DataBaseInsertUSerFilshes(this->m_b_login);
}

