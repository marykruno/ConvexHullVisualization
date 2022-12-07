/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionclear_All;
    QAction *actionbackground_color;
    QAction *actionpoints_color;
    QAction *actionconvex_hull_color;
    QAction *actionchoose_algorithm;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1184, 637);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionclear_All = new QAction(MainWindow);
        actionclear_All->setObjectName("actionclear_All");
        actionbackground_color = new QAction(MainWindow);
        actionbackground_color->setObjectName("actionbackground_color");
        actionpoints_color = new QAction(MainWindow);
        actionpoints_color->setObjectName("actionpoints_color");
        actionconvex_hull_color = new QAction(MainWindow);
        actionconvex_hull_color->setObjectName("actionconvex_hull_color");
        actionchoose_algorithm = new QAction(MainWindow);
        actionchoose_algorithm->setObjectName("actionchoose_algorithm");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1184, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionclear_All);
        menuOptions->addAction(actionbackground_color);
        menuOptions->addAction(actionpoints_color);
        menuOptions->addAction(actionconvex_hull_color);
        menuOptions->addAction(actionchoose_algorithm);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionclear_All->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
#if QT_CONFIG(tooltip)
        actionclear_All->setToolTip(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
#endif // QT_CONFIG(tooltip)
        actionbackground_color->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
#if QT_CONFIG(tooltip)
        actionbackground_color->setToolTip(QCoreApplication::translate("MainWindow", "Background color", nullptr));
#endif // QT_CONFIG(tooltip)
        actionpoints_color->setText(QCoreApplication::translate("MainWindow", "Points color", nullptr));
#if QT_CONFIG(tooltip)
        actionpoints_color->setToolTip(QCoreApplication::translate("MainWindow", "Points color", nullptr));
#endif // QT_CONFIG(tooltip)
        actionconvex_hull_color->setText(QCoreApplication::translate("MainWindow", "Convex hull color", nullptr));
#if QT_CONFIG(tooltip)
        actionconvex_hull_color->setToolTip(QCoreApplication::translate("MainWindow", "Convex hull color", nullptr));
#endif // QT_CONFIG(tooltip)
        actionchoose_algorithm->setText(QCoreApplication::translate("MainWindow", "Choose algorithm", nullptr));
        actionchoose_algorithm->setIconText(QCoreApplication::translate("MainWindow", "Choose algorithm", nullptr));
#if QT_CONFIG(tooltip)
        actionchoose_algorithm->setToolTip(QCoreApplication::translate("MainWindow", "Choose algorithm", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
