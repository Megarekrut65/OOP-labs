QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

CONFIG -= app_bundle

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
    Windows/messagetextwindow.cpp \
    Windows/programbuilderwindow.cpp \
    Windows/programwindow.cpp \
    Windows/serverinfowindow.cpp \
    Windows/serverwindow.cpp \
    app_messages.cpp \
    main.cpp \
    my_view_model.cpp \
    progress_bar_animation.cpp

HEADERS += \
    Computer-network/basic_program.h \
    Computer-network/basic_server.h \
    Computer-network/message.h \
    Computer-network/program_registry.h \
    Computer-network/programs.h \
    Computer-network/servers.h \
    Tests/doctest.h \
    Tests/testing_program.h \
    Windows/mainwindow.h \
    Windows/messagetextwindow.h \
    Windows/programbuilderwindow.h \
    Windows/programwindow.h \
    Windows/serverinfowindow.h \
    Windows/serverwindow.h \
    app_messages.h \
    my_view_model.h \
    progress_bar_animation.h

FORMS += \
    Windows/mainwindow.ui \
    Windows/messagetextwindow.ui \
    Windows/programbuilderwindow.ui \
    Windows/programwindow.ui \
    Windows/serverinfowindow.ui \
    Windows/serverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/error-type.ico \
    Images/info-type.ico \
    Images/main-icon.ico \
    Images/none-type.ico \
    Images/program-window-icon.ico \
    Images/server-window-icon.ico \
    Images/warning-type.ico
