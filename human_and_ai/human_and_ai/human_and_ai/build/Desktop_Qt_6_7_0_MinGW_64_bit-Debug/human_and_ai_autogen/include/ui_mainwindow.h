/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_0_1;
    QPushButton *pushButton_1_1;
    QPushButton *pushButton_2_1;
    QPushButton *pushButton_0_2;
    QPushButton *pushButton_1_2;
    QPushButton *pushButton_2_2;
    QLabel *turnLabel;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_0_0;
    QPushButton *pushButton_1_0;
    QPushButton *pushButton_2_0;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_0_1 = new QPushButton(centralwidget);
        pushButton_0_1->setObjectName("pushButton_0_1");
        pushButton_0_1->setGeometry(QRect(209, 493, 141, 20));
        pushButton_1_1 = new QPushButton(centralwidget);
        pushButton_1_1->setObjectName("pushButton_1_1");
        pushButton_1_1->setGeometry(QRect(209, 515, 141, 20));
        pushButton_2_1 = new QPushButton(centralwidget);
        pushButton_2_1->setObjectName("pushButton_2_1");
        pushButton_2_1->setGeometry(QRect(209, 537, 141, 20));
        pushButton_0_2 = new QPushButton(centralwidget);
        pushButton_0_2->setObjectName("pushButton_0_2");
        pushButton_0_2->setGeometry(QRect(389, 490, 141, 20));
        pushButton_1_2 = new QPushButton(centralwidget);
        pushButton_1_2->setObjectName("pushButton_1_2");
        pushButton_1_2->setGeometry(QRect(389, 510, 141, 20));
        pushButton_2_2 = new QPushButton(centralwidget);
        pushButton_2_2->setObjectName("pushButton_2_2");
        pushButton_2_2->setGeometry(QRect(389, 530, 141, 20));
        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setGeometry(QRect(150, 370, 251, 71));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 130, 104, 41));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(210, 130, 141, 31));
        pushButton_0_0 = new QPushButton(centralwidget);
        pushButton_0_0->setObjectName("pushButton_0_0");
        pushButton_0_0->setGeometry(QRect(6, 493, 151, 18));
        pushButton_1_0 = new QPushButton(centralwidget);
        pushButton_1_0->setObjectName("pushButton_1_0");
        pushButton_1_0->setGeometry(QRect(6, 515, 151, 18));
        pushButton_2_0 = new QPushButton(centralwidget);
        pushButton_2_0->setObjectName("pushButton_2_0");
        pushButton_2_0->setGeometry(QRect(6, 537, 151, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_0_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_1_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_0_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_1_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        turnLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">play against AI</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">play against player</p></body></html>", nullptr));
        pushButton_0_0->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_1_0->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2_0->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
