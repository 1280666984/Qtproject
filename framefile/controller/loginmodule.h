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
    bool slot_regIncresase(QString regname,QString password);
    bool slot_logicVerify(QString username,QString password);

signals:
    void signal_regIncresasefinishes();
    void signal_logicVerifyfinishes();

private:
    static QSharedPointer<LoginModule> m_LoginModule_ptr;
    static QMutex m_mutex;  
};

#endif // LoginModule_H
