#ifndef LoginModule_H
#define LoginModule_H
#include <QObject>
#include <QSharedPointer>
#include <QMutex>

class LoginModule : public QObject
{
    Q_OBJECT
public:   
    static QSharedPointer<LoginModule> getInstance();
protected:

private:
    explicit LoginModule(QObject *parent = nullptr);
    LoginModule( const LoginModule & LoginModule ) = delete ;
    LoginModule& operator =(LoginModule&) = delete;

public slots:
    bool slot_regVerify(QString regname);
    void slot_regIncresase(QString regname,QString password);
    void slot_logicVerify(QString username,QString password,bool &m_b_login);

signals:
    void signal_regIncresasefinishes(bool m_b_login);
    void signal_logicVerifyfinishes(bool m_b_signup);

private:
    static QSharedPointer<LoginModule> m_LoginModule_ptr;
    static QMutex m_mutex;  

};

#endif // LoginModule_H
