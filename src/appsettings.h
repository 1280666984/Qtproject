#ifndef APPSETTINGS_H
#define APPSETTINGS_H
#include "appconfigdef.h"

#include <QVariant>
#include <QSettings>

//#define appSettingsInstance AppSettings::getInstance()
class AppSettings
{
public:
    static AppSettings * getInstance();
    static QVariant getSettings(const QString key);
    static void setSetting(const QString key,const QVariant value);
    static void quit();
    ~AppSettings();

private:
    explicit AppSettings();
    AppSettings(const  AppSettings &) = delete;
    AppSettings & operator=(const AppSettings &) = delete;
private:
   static AppSettings*  m_appSettings;
   static QSettings *   m_Settings;
};

#endif // APPSETTINGS_H
