QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Code/file_functions.cpp \
    Code/file_opening_mode.cpp \
    Code/memory_opening_mode.cpp \
    Code/monster.cpp \
    Code/opening_mode.cpp \
    addwindow.cpp \
    enteridwindow.cpp \
    findhpdamagewindow.cpp \
    findmenuwindow.cpp \
    findnamewindow.cpp \
    findtypetimewindow.cpp \
    infowindow.cpp \
    interactivewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    modelfunctions.cpp \
    mymessage.cpp \
    showmonsters.cpp

HEADERS += \
    Code/file_functions.h \
    Code/file_mode.h \
    Code/file_opening_mode.h \
    Code/memory_opening_mode.h \
    Code/monster.h \
    Code/opening_mode.h \
    addwindow.h \
    enteridwindow.h \
    findhpdamagewindow.h \
    findmenuwindow.h \
    findnamewindow.h \
    findtypetimewindow.h \
    infowindow.h \
    interactivewindow.h \
    mainwindow.h \
    modelfunctions.h \
    mylibrary.h \
    mymessage.h \
    showmonsters.h

FORMS += \
    addwindow.ui \
    enteridwindow.ui \
    findhpdamagewindow.ui \
    findmenuwindow.ui \
    findnamewindow.ui \
    findtypetimewindow.ui \
    infowindow.ui \
    interactivewindow.ui \
    mainwindow.ui \
    showmonsters.ui

TRANSLATIONS += \
    lab1a-qt_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/delete.ico \
    Images/edit.ico \
    Images/find.ico \
    Images/info.ico \
    Images/monster.ico \
    Images/monsters.ico \
    Images/plus.ico
