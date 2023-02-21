#include "control.h"
#include <QDebug>
#include <QString>
#include "mysql.h"
Control::Control(QObject *parent)
    : QObject{parent}
{}

QSharedPointer<Control> Control::m_control_ptr;
QMutex Control::m_mutex;

QSharedPointer<Control> Control::getInstance()
{
    if(nullptr == m_control_ptr){
        m_mutex.lock();
        if(nullptr == m_control_ptr){
            m_control_ptr = QSharedPointer<Control>(new Control,&QObject::deleteLater);}
        m_mutex.unlock();
    }
    return m_control_ptr;
}
bool Control::regVerify(QString regname)
{
Q_UNUSED(regname)
}

bool Control::regIncresase(QString regname, QString password)
{
    //  _m->query.exec("create table admin2 (username varchar(20) , password varchar(20))")
    //  _m->query.prepare("insert into admin (username,password)"
    //                      "values(:username,:password)");
    //  _m->query.bindValue(":username", username);
    //  _m->query.bindValue(":password", password);
    //  _m->query.exec();
    MySql * m_ = MySql::getMysql();
    QString string = QString("insert into admin values('%1','%2')").arg(regname,password);
   if(m_->operate(string)){
    return true;}
   else{ return false;}
}

bool Control::logicVerify(QString username, QString password)
{
    MySql * m_ = MySql::getMysql();
    QString string = QString("select * from admin where username= '%1' and password= '%2' ").arg(username,password);
    m_->operate(string);
    if(m_->getNext()){
        QString a = m_->getValue(0).toString();
        QString b = m_->getValue(1).toString();
        qDebug()<<username<<password;
        qDebug()<<string;
        qDebug()<<a<<b<<string;
        if(username == a && password == b){
            return true;}
        else{
            return false;
        }
    }
    else{
        return false;}
}
