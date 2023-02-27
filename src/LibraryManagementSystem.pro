#QT模块添加
QT  += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#app模板
TEMPLATE = app

#应用程序存放的目录
win32:CONFIG(debug,debug|release){
      DESTDIR = $$PWD/bin/debug
}else:win32:CONFIG(release,debug|relese){
      DESTDIR =$$PWD/bin/release
}


#  程序名字和t图标
TARGET  = LibManagSys
RC_FILE = $$PWD/icons/logo.rc
#编译器选项和配置
CONFIG += c++17
CONFIG += warn_on
#win32:QMAKE_CXXFLAGS += /utf-8

SOURCES += \
    librarymanagementsystem.cpp \
    main.cpp \

HEADERS += \
    librarymanagementsystem.h \

#文件目录
INCLUDEPATH += \
  $$PWD/class \
  $$PWD/gui   \
  $$PWD/core  \
  $$PWD/model

#添加的pri子目录
include($$PWD/class/class.pri)
include($$PWD/gui/ui.pri)
include($$PWD/core/core.pri)
include($$PWD/model/appdatabase.pri)


#其他文件
DISTFILES += \
    $$PWD/styles\qrc.qss \
    $$PWD/icons\logo.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

