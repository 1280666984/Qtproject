#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H

#include <QObject>
#include "loginmodule.h"
#include "login.h"
#include "mainwindow.h"

class LibraryManagementSystem : public QObject
{
    Q_OBJECT
public:
    explicit LibraryManagementSystem(QObject *parent = nullptr);
    void loginShow();

private:

private slots:

signals:


private:
    Login m_l;
    MainWindow m_m;
    LoginModule m_login;
};

#endif // LIBRARYMANAGEMENTSYSTEM_H
