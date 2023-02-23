#include "librarymanagementsystem.h"

LibraryManagementSystem::LibraryManagementSystem(QObject *parent)
    : QObject{parent}
{

  //connect(&m_l,&Login::signals_login,LoginModule::getInstance().data(),&LoginModule::slot_logicVerify);             //登录连接
  //connect(LoginModule::getInstance().data(),&LoginModule::signal_logicVerifyfinishes,&m_l,&Login::slot_LoginOver);  //验证返回
 // connect(&m_l,&Login::signals_MainwindowsShow,&m_m,&MainWindow::show);                                             //主程序show
}

void LibraryManagementSystem::loginShow()                                                                           //登录按钮接口
{
   this->m_l.show();
}
