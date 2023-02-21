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
    bool slot_regVerify(const QString regname);
    void slot_regIncresase(const QString regname,const QString password);
    void slot_logicVerify(const QString username,const QString password,bool &m_b_login);

signals:
    void signal_regIncresasefinishes(const bool m_b_login);
    void signal_logicVerifyfinishes(const bool m_b_signup);

private:
    static QSharedPointer<LoginModule> m_LoginModule_ptr;
    static QMutex m_mutex;  

};

#endif // LoginModule_H
