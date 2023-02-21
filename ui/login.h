#ifndef LOGIN_H
#define LOGIN_H
#include <QSqlDatabase>
#include <QWidget>
#include "mysql.h"
#include "ui_login.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event );
    void mouseReleaseEvent(QMouseEvent * event);
    bool eventFilter(QObject *wcg , QEvent * event);

private slots:
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();

    void on_toolButton_11_clicked();
signals:
    void showenroll();
    void showmain();

private:
    Ui::Login *ui;
    QLineEdit * lineEdit;
    QPoint reltvpos;
    bool _move;
 //   MySql * _m;

};

#endif // LOGIN_H
