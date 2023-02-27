#ifndef LOGIN_H
#define LOGIN_H
#include <QSqlDatabase>
#include <QWidget>
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

public slots:
    void slot_LoginOver();

private slots:
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();

    void on_toolButton_11_clicked();

signals:
    void signals_login(const QString n,const QString p,bool &m_b_login);
    void signals_signup();

    void signals_MainwindowsShow();
private:
    Ui::Login *ui;
    QLineEdit * lineEdit;
    QPoint reltvpos;
    bool m_move;

    bool m_b_login;
    bool m_b_signup;

};

#endif // LOGIN_H
