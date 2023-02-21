#include "loginmodule.h"
#include <QDebug>
#include <QString>
#include "mysql.h"
LoginModule::LoginModule(QObject *parent)
    : QObject{parent}
{}

QSharedPointer<LoginModule> LoginModule::m_LoginModule_ptr;
QMutex LoginModule::m_mutex;

QSharedPointer<LoginModule> LoginModule::getInstance()
{
    if(nullptr == m_LoginModule_ptr){
        m_mutex.lock();
        if(nullptr == m_LoginModule_ptr){
            m_LoginModule_ptr = QSharedPointer<LoginModule>(new LoginModule,&QObject::deleteLater);}
        m_mutex.unlock();
    }
    return m_LoginModule_ptr;
}


bool LoginModule::slot_regVerify(const QString regname)
{
Q_UNUSED(regname)
}

void LoginModule::slot_regIncresase(const QString regname, const QString password)
{
    //  _m->query.exec("create table admin2 (username varchar(20) , password varchar(20))")
    //  _m->query.prepare("insert into admin (username,password)"
    //                      "values(:username,:password)");
    //  _m->query.bindValue(":username", username);
    //  _m->query.bindValue(":password", password);
    //  _m->query.exec();
//    MySql * m_ = MySql::getMysql();
//    QString string = QString("insert into admin values('%1','%2')").arg(regname,password);
//   if(m_->operate(string)){
//    return true;}
//   else{ return false;}

}

void LoginModule::slot_logicVerify(const QString username, const QString password,bool& m_b_login)
{
    MySql * m_ = MySql::getMysql();
    QString string = QString("select * from admin where username= '%1' and password= '%2' ").arg(username,password);
    if(!m_->operate(string))
    {
        return;
    }
    if(m_->getNext()){
        QString a = m_->getValue(0).toString();
        QString b = m_->getValue(1).toString();
        qDebug()<<username<<password;

        qDebug()<<a<<b<<string;
        if(username == a && password == b){
            m_b_login = true;
            emit signal_logicVerifyfinishes(m_b_login);}
        else{
            m_b_login = false;
            emit signal_logicVerifyfinishes(m_b_login);}
    }
    else{
        m_b_login = false;
        emit signal_logicVerifyfinishes(m_b_login);}
}
