#-------------------------------------------------
#
# Project created by QtCreator 2018-12-10T15:21:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cloth_simulation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += $$PWD/src
SOURCES += \
    src/clothwindow.cpp \
    src/main.cpp \
    src/ply_Module.cpp \
    src/tinyply.cpp \
    src/ClothMain.cpp



INCLUDEPATH += $$PWD/headers
HEADERS += \
    headers/clothwindow.h \
    headers/ply_Module.h \
    headers/tinyply.h

INCLUDEPATH += $$PWD/GUI
FORMS += \
    GUI/clothwindow.ui

# Add some user defined libraries
INCLUDEPATH += /usr/include/eigen3

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
