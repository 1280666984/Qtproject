QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

TARGET = LibManagSys
DESTDIR = $$PWD/bin
TEMPLATE = app
RC_FILE = $$PWD/icons/logo.rc

HEADERS += \
    appconfigdef.h \
    appevent.h \
    appinit.h \
    appsettings.h \
    librarymanagementsystem.h \
    appdata.h

SOURCES += \
    appevent.cpp \
    appinit.cpp \
    appsettings.cpp \
    librarymanagementsystem.cpp \
    main.cpp \
    appdata.cpp

RESOURCES +=


CONFIG += DEBUG_AND_RELEASE
CONFIG(debug,debug|release){
}else{
}

INCLUDEPATH += \
  $$PWD/view \
  $$PWD/model \
  $$PWD/controller

include($$PWD/view/ui.pri)
include($$PWD/model/appdatabase.pri)
include($$PWD/controller/control.pri)




DISTFILES += \
    $$PWD/styles\qrc.qss \
    $$PWD/icons\logo.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

