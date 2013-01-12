QT       += core gui sql

TARGET = technologybasic

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h\
    defines.h

FORMS    += mainwindow.ui

win32: {
RC_FILE += technologybasic.rc
}
