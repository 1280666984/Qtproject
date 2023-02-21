#ifndef CONTROL_H
#define CONTROL_H
#include <QObject>
#include <QSharedPointer>
#include <QMutex>

class Control : public QObject
{
    Q_OBJECT
public:   
    static QSharedPointer<Control> getInstance();
    bool regVerify(QString regname);
    bool regIncresase(QString regname,QString password);
    bool logicVerify(QString username,QString password);

protected:

private:
    explicit Control(QObject *parent = nullptr);
    Control( const Control & control ) = delete ;
    Control& operator =(Control&) = delete;

private:
    static QSharedPointer<Control> m_control_ptr;
    static QMutex m_mutex;
signals:

};

#endif // CONTROL_H
