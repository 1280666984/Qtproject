QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

DESTDIR = $$PWD/bin

HEADERS += \
    appconfig.h \
    appdata.h \
    appevent.h \
    appinit.h \
    librarymanagementsystem.h \
    savelog.h

SOURCES += \
    appconfig.cpp \
    appdata.cpp \
    appevent.cpp \
    appinit.cpp \
    librarymanagementsystem.cpp \
    main.cpp \
    savelog.cpp

RESOURCES +=

RC_ICONS


INCLUDEPATH += \
  $$PWD/framefile/view \
  $$PWD/framefile/model \
  $$PWD/framefile/controller

include($$PWD/framefile/view/ui.pri)
include($$PWD/framefile/model/appdatabase.pri)
include($$PWD/framefile/model/mysql.pri)
include($$PWD/framefile/controller/control.pri)



DISTFILES += \
    qrc.qss \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

