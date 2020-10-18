QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addingtimer.cpp \
    editingtimer.cpp \
    main.cpp \
    mainwindow.cpp \
    mycolors.cpp \
    mysounds.cpp \
    mytimer.cpp \
    notdisturbmode.cpp \
    showtimer.cpp \
    timeperiod.cpp

HEADERS += \
    addingtimer.h \
    editingtimer.h \
    mainwindow.h \
    mycolors.h \
    mysounds.h \
    mytimer.h \
    notdisturbmode.h \
    showtimer.h \
    timeperiod.h

FORMS += \
    addingtimer.ui \
    editingtimer.ui \
    mainwindow.ui \
    notdisturbmode.ui \
    showtimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Sounds/timerSound.wav \
    files/timers.txt \
    sounds/timerSound1.wav \
    sounds/timerSound2.wav \
    sounds/timerSound3.wav \
    sounds/timerSound4.wav

RESOURCES += \
    resource.qrc
