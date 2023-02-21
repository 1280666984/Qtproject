#include <QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QFont>
#include <QFile>

#include <QtAlgorithms>
#include "mysql.h"
#include "login.h"
#include "mainwindow.h"
#include <QDebug>

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



    //数据库连接
    MySql* m = MySql::getMysql();
    m->open();

    Login l;
    MainWindow w;

    //l.show();
    w.show();
    //QObject::connect(&l,&Login::showmain,&w,&MainWindow::receiveLogin);
    return a.exec();
}
