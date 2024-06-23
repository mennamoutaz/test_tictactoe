QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    shell.c \
    sqlite3.c \
    test_mainwindow.cpp

HEADERS += \
    mainwindow.h \
    sqlite3.h \
    sqlite3ext.h \
    test_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    tictactoe5.db



QT += testlib

CONFIG += testcases

# Specify the test source files
SOURCES += tests.cpp

# Specify the mainwindow.cpp file
# Assuming your mainwindow.cpp file is included in your project's sources
SOURCES += mainwindow.cpp

# Specify the header files
HEADERS += tests.h
HEADERS += mainwindow.h
SOURCES += test_mainwindow.cpp \
           moc_test_mainwindow.cpp

