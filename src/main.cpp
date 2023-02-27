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

#if defined Q_OS_WIN32
#else
#endif

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


    AppDataBase * one = AppDataBase::getAppDataBase();
    one->openDatabase("text");

    LibraryManagementSystem l;
    l.loginShow();


    return a.exec();
}
