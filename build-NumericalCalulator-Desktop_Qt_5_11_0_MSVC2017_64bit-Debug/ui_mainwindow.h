/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *returnButton;
    QTabWidget *inputTabWidget;
    QWidget *tab;
    QPlainTextEdit *input_text;
    QWidget *tab_2;
    QPlainTextEdit *input_text2;
    QTabWidget *outputTabWidget_2;
    QWidget *outputTab;
    QPlainTextEdit *output_text;
    QWidget *tab_4;
    QPlainTextEdit *errorTextOuput;
    QPushButton *clearInputButton;
    QPushButton *clearOutputButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        returnButton = new QPushButton(centralWidget);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(240, 240, 181, 41));
        inputTabWidget = new QTabWidget(centralWidget);
        inputTabWidget->setObjectName(QStringLiteral("inputTabWidget"));
        inputTabWidget->setGeometry(QRect(30, 0, 650, 231));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        input_text = new QPlainTextEdit(tab);
        input_text->setObjectName(QStringLiteral("input_text"));
        input_text->setGeometry(QRect(0, 0, 650, 211));
        inputTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        input_text2 = new QPlainTextEdit(tab_2);
        input_text2->setObjectName(QStringLiteral("input_text2"));
        input_text2->setGeometry(QRect(0, 0, 641, 211));
        inputTabWidget->addTab(tab_2, QString());
        outputTabWidget_2 = new QTabWidget(centralWidget);
        outputTabWidget_2->setObjectName(QStringLiteral("outputTabWidget_2"));
        outputTabWidget_2->setGeometry(QRect(29, 340, 651, 141));
        outputTab = new QWidget();
        outputTab->setObjectName(QStringLiteral("outputTab"));
        output_text = new QPlainTextEdit(outputTab);
        output_text->setObjectName(QStringLiteral("output_text"));
        output_text->setGeometry(QRect(0, 0, 651, 121));
        output_text->setReadOnly(true);
        outputTabWidget_2->addTab(outputTab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        errorTextOuput = new QPlainTextEdit(tab_4);
        errorTextOuput->setObjectName(QStringLiteral("errorTextOuput"));
        errorTextOuput->setGeometry(QRect(0, 3, 651, 111));
        errorTextOuput->setReadOnly(true);
        outputTabWidget_2->addTab(tab_4, QString());
        clearInputButton = new QPushButton(centralWidget);
        clearInputButton->setObjectName(QStringLiteral("clearInputButton"));
        clearInputButton->setGeometry(QRect(30, 240, 181, 41));
        clearOutputButton = new QPushButton(centralWidget);
        clearOutputButton->setObjectName(QStringLiteral("clearOutputButton"));
        clearOutputButton->setGeometry(QRect(130, 290, 181, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(clearInputButton, SIGNAL(clicked()), input_text, SLOT(clear()));
        QObject::connect(clearOutputButton, SIGNAL(clicked()), output_text, SLOT(clear()));

        inputTabWidget->setCurrentIndex(0);
        outputTabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        returnButton->setText(QApplication::translate("MainWindow", "Return!", nullptr));
        inputTabWidget->setTabText(inputTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        inputTabWidget->setTabText(inputTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        outputTabWidget_2->setTabText(outputTabWidget_2->indexOf(outputTab), QApplication::translate("MainWindow", "Output", nullptr));
        outputTabWidget_2->setTabText(outputTabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Error", nullptr));
        clearInputButton->setText(QApplication::translate("MainWindow", "ClearInput", nullptr));
        clearOutputButton->setText(QApplication::translate("MainWindow", "ClearOutput", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
