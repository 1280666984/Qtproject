#include <QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QFont>
#include <QFile>

#include <QtAlgorithms>
#include "mysql.h"
#include <QDebug>
#include "librarymanagementsystem.h"

int main(int argc, char *argv[])
{   

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


    LibraryManagementSystem l;
    l.loginShow();
//  数据库连接
    MySql* m = MySql::getMysql();
    m->open();


    return a.exec();
}
