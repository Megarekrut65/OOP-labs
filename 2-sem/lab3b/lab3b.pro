QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Computer-network/basic_program.cpp \
    Computer-network/basic_server.cpp \
    Computer-network/message.cpp \
    Computer-network/program_registry.cpp \
    Computer-network/programs.cpp \
    Computer-network/servers.cpp \
    Windows/mainwindow.cpp \
    Windows/programbuilderwindow.cpp \
    main.cpp

HEADERS += \
    Computer-network/basic_program.h \
    Computer-network/basic_server.h \
    Computer-network/message.h \
    Computer-network/program_registry.h \
    Computer-network/programs.h \
    Computer-network/servers.h \
    Windows/mainwindow.h \
    Windows/programbuilderwindow.h

FORMS += \
    Windows/mainwindow.ui \
    Windows/programbuilderwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/main-icon.ico \
    Images/program-icon.ico
