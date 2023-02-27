#include "librarymanagementsystem.h"
LibraryManagementSystem::LibraryManagementSystem(QObject *parent)
    : QObject{parent}
{

}

void LibraryManagementSystem::loginShow()                                                                           //登录按钮接口
{
   this->m_l.show();
}
