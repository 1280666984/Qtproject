#include "librarymanagementsystem.h"
LibraryManagementSystem::LibraryManagementSystem(QObject *parent)
    : QObject{parent}
{

}

void LibraryManagementSystem::loginShow()
{
   this->m_l.show();
}
