QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_program.cpp \
    basic_server.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    my_tree_model.cpp \
    program_factory.cpp \
    programs.cpp \
    servers.cpp

HEADERS += \
    basic_program.h \
    basic_server.h \
    mainwindow.h \
    message.h \
    my_tree_model.h \
    program_factory.h \
    programs.h \
    servers.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
