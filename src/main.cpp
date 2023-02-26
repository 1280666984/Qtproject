#include <QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QFont>
#include <QFile>
#include <QtAlgorithms>
#include <QDebug>

#include "librarymanagementsystem.h"
#include "appdatabase.h"
#include "appsettings.h"
#include "appinit.h"



//#ifdef Q_OS_WIN
//#ifdef QT_DEBUG

int main(int argc, char *argv[])
{
//    QString   m_qstrFilename = QString(QCoreApplication::applicationDirPath() + "/Config.ini");
    QApplication a(argc, argv);

//    int font_Id = !QFontDatabase::addApplicationFont(":/abc.ttf");
//    QStringList font_list = QFontDatabase::applicationFontFamilies(font_Id);
//   if(font_list.empty()){
//       qDebug()<<1;
//   }
//    QFont f;
//    f.setFamily(font_list[0]);
//    a.setFont(f);

    QSettings sett;
     sett.setValue("animal/snake", 58);
     sett.value("animal/snake", 1024).toInt();   // returns 58
     sett.value("animal/zebra", 1024).toInt();   // returns 1024
     sett.value("animal/zebra").toInt();

    AppDataBase * one = AppDataBase::getAppDataBase();
    one->openDatabase("text");

    LibraryManagementSystem l;
    l.loginShow();


    return a.exec();
}
