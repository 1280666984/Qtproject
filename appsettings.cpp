#include "appsettings.h"

AppSettings* AppSettings::m_appSettings = nullptr;
QSettings  * AppSettings::m_Settings = nullptr;

AppSettings::AppSettings()
{

}
void AppSettings::quit(){}

AppSettings* AppSettings::getInstance()
{
    if(nullptr == m_appSettings){
        m_appSettings = new AppSettings;
        QString m_qstrFilename = QString(QCoreApplication::applicationDirPath() + "/Config.ini");
        m_Settings    = new QSettings(m_qstrFilename,QSettings::IniFormat); }
    return m_appSettings;
}

QVariant AppSettings::getSettings(QString key)
{
    return m_Settings->value(key);
}

void AppSettings::setSetting(const QString key, const QVariant value)
{
    return m_Settings->setValue(key,value);
}


AppSettings::~AppSettings()
{
    delete this->m_Settings;
}
