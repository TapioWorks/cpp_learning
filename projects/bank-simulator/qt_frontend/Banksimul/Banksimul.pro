QT       += core gui
QT       +=network
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialoglock.cpp \
    main.cpp \
    mainwindow.cpp \
    naytasaldo.cpp \
    nostoreply.cpp \
    nostowindow.cpp \
    paawindow.cpp \
    selaatilitapahtumia.cpp

HEADERS += \
    dialoglock.h \
    mainwindow.h \
    naytasaldo.h \
    nostoreply.h \
    nostowindow.h \
    paawindow.h \
    selaatilitapahtumia.h

FORMS += \
    dialoglock.ui \
    mainwindow.ui \
    naytasaldo.ui \
    nostoreply.ui \
    nostowindow.ui \
    paawindow.ui \
    selaatilitapahtumia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-DLLRestApi-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/release/ -lDLLRestApi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-DLLRestApi-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLRestApi





win32: LIBS += -L$$PWD/../build-DLLSerialport-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lDLLSerialport

INCLUDEPATH += $$PWD/../DLLSerialport
DEPENDPATH += $$PWD/../DLLSerialport

win32: LIBS += -L$$PWD/../build-DLLRestApi-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lDLLRestApi

INCLUDEPATH += $$PWD/../DLLRestApi
DEPENDPATH += $$PWD/../DLLRestApi

win32: LIBS += -L$$PWD/../build-DLLPinCode-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/../DLLPinCode
DEPENDPATH += $$PWD/../DLLPinCode
