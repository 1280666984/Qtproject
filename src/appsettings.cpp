#include "appsettings.h"
#include <QObject>
#include <QSettings>
#include <QFile>

static const  QString APP_DATA_DIR_KEY("appadtadir");
static const  QString SHOTCUT_INI_FILENAME("/config/config.ini");
static QScopedPointer<AppSettings> instance;
static QString AppDataForSession;

QSettings AppSettings::m_Setting(APP_DATA_DIR_KEY,QSettings::IniFormat);


AppSettings& AppSettings::Singleton()
{
    if(!instance){
        if(AppDataForSession.isEmpty()){
            instance.reset(new AppSettings);
            if(instance->m_Settings.value(APP_DATA_DIR_KEY).isValid()
                    && QFile::exists(instance->m_Settings.value(APP_DATA_DIR_KEY).toString() + SHOTCUT_INI_FILENAME))
                instance.reset(new AppSettings(instance->m_Settings.value(APP_DATA_DIR_KEY).toString() + SHOTCUT_INI_FILENAME));
        }else{
            instance.reset(new AppSettings(AppDataForSession));
        }

    }
    return *instance;
}

AppSettings::AppSettings(const QString &appDataLocation)
    :QObject()
    ,m_Settings(appDataLocation ,QSettings::IniFormat)
{
}


//        QString m_qstrFilename = QString(QCoreApplication::applicationDirPath() + );
QVariant AppSettings::getSettings(QString key)
{

    return m_Setting.value(key);
}

void AppSettings::setSetting(const QString key, const QVariant value)
{
    return m_Setting.setValue(key,value);
}

AppSettings::~AppSettings()
{

}

void AppSettings::reset()
{
    for(auto &Key: m_Settings.allKeys()){
        m_Settings.remove(Key);
    }
}
