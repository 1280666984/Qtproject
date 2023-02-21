#include "librarymanagementsystem.h"

LibraryManagementSystem::LibraryManagementSystem(QObject *parent)
    : QObject{parent}
{
  connect(&m_l,&Login::signals_login,LoginModule::getInstance().data(),&LoginModule::slot_logicVerify);
  connect(LoginModule::getInstance().data(),&LoginModule::signal_logicVerifyfinishes,&m_l,&Login::slot_LoginOver);
  connect(&m_l,&Login::signals_MainwindowsShow,&m_m,&MainWindow::show);
}

void LibraryManagementSystem::loginShow()
{
   this->m_l.show();
}
