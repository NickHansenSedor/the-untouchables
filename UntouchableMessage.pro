#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T14:44:18
#
#-------------------------------------------------

QT       += core gui sql
QT       += sql
QT       += core
#CONFIG   += c++11 console      #Removing this gets rid of the cmd prompt,unsure what it effects thus far

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UntouchableMessage
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    cryptfiledevice.cpp \
    encryptwindow.cpp \
    sendwindow.cpp \
    setkey.cpp \
    uploadwindow.cpp \
    mainwindow.cpp \
    decryptwindow.cpp

HEADERS  += dialog.h \
    mainwindow.h \
   cryptfiledevice.h \
    sendwindow.h \
    setkey.h \
    uploadwindow.h \
    encryptwindow.h \
    decryptwindow.h

FORMS    += dialog.ui \
    encryptwindow.ui \
    sendwindow.ui \
    setkey.ui \
    uploadwindow.ui \
    mainwindow.ui \
    decryptwindow.ui

win32 {
INCLUDEPATH += c:/OpenSSL-Win64/include
LIBS += -Lc:/OpenSSL-Win64/lib -llibeay32
}
linux|macx {
LIBS += -lcrypto
}

DISTFILES +=
