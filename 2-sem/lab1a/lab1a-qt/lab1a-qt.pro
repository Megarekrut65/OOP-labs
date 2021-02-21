QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Code/benchmark.cpp \
    Code/demo.cpp \
    Code/file_functions.cpp \
    Code/file_opening_mode.cpp \
    Code/interactive.cpp \
    Code/memory_opening_mode.cpp \
    Code/monster.cpp \
    Code/monster_menu.cpp \
    Code/my_reads.cpp \
    Code/opening_mode.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Code/benchmark.h \
    Code/demo.h \
    Code/file_functions.h \
    Code/file_mode.h \
    Code/file_opening_mode.h \
    Code/interactive.h \
    Code/memory_opening_mode.h \
    Code/monster.h \
    Code/monster_menu.h \
    Code/my_reads.h \
    Code/opening_mode.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lab1a-qt_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
