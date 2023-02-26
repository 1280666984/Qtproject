#ifndef APPSETTINGS_H
#define APPSETTINGS_H
#include "appconfigdef.h"
#include <QSharedPointer>
#include <QMutex>
#include <QVariant>
#include <QSettings>
#include <QObject>


class AppSettings:QObject
{
public:
    static AppSettings & Singleton();
    explicit AppSettings():QObject(){};
    explicit AppSettings(const QString & appDataLocation);

    void log();
    void sync();
    QString  language()  const;
    void setlanguage(const QString &s);
    QString  openPath()  const;
    void setOpenPath(const QString &s);
    QString  jobPriority() const;
    void setJobPrriority(const QString &s);
    QByteArray windowGeometry() const;
    void setWindowGEometry(const QByteArray &a);
    ~AppSettings();



    /*
     测试使用的静态对象及静态函数
    */
    static QSettings m_Setting;
    static void setSetting(const QString key,const QVariant value);
    static QVariant getSettings(const QString key);

private:

public slots:
    void reset();



private:
   QSettings  m_Settings;
   QString    m_appDataLocation;
};

#endif // APPSETTINGS_H
