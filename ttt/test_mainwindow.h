#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QObject>

class Tests : public QObject
{
    Q_OBJECT
    void testHashPassword();
    void testTimeToString();
    void testSignup();
    void testLogin();
};

#endif // TEST_MAINWINDOW_H
