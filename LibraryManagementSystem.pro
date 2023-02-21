QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17


INCLUDEPATH += \
    $$PWD/ui \
    $$PWD/mysql\
    $$PWD/control

include($$PWD/ui/ui.pri)
include($$PWD/mysql/mysql.pri)
include($$PWD/control/control.pri)


HEADERS += \

SOURCES += \
   main.cpp \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qrc.qss \

RESOURCES +=



RC_ICONS


