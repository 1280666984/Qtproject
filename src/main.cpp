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

int main(int argc, char *argv[])
{
    QString   m_qstrFilename = QString(QCoreApplication::applicationDirPath() + "/Config.ini");
    QApplication a(argc, argv);
    QTextCodec *code = QTextCodec::codecForName("UTF_8");
    QTextCodec::setCodecForLocale(code);

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
