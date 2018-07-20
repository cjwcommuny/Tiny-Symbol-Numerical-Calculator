/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
<<<<<<< HEAD
=======
#include "curveform.h"
>>>>>>> master

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *inputTextBox;
    QPushButton *returnButton;
    QTabWidget *outputTabWidget;
    QWidget *tab;
    QPlainTextEdit *resultTextBox;
    QWidget *tab_2;
    QPlainTextEdit *ErrorTextBox;
<<<<<<< HEAD
=======
    CurveForm *curveGraphView;
>>>>>>> master
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName(QStringLiteral("view"));
<<<<<<< HEAD
        view->resize(720, 720);
=======
        view->resize(720, 836);
>>>>>>> master
        centralWidget = new QWidget(view);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputTextBox = new QPlainTextEdit(centralWidget);
        inputTextBox->setObjectName(QStringLiteral("inputTextBox"));
        inputTextBox->setGeometry(QRect(20, 10, 681, 91));
        returnButton = new QPushButton(centralWidget);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(40, 130, 131, 51));
        outputTabWidget = new QTabWidget(centralWidget);
        outputTabWidget->setObjectName(QStringLiteral("outputTabWidget"));
<<<<<<< HEAD
        outputTabWidget->setGeometry(QRect(20, 210, 681, 211));
=======
        outputTabWidget->setGeometry(QRect(20, 210, 681, 141));
>>>>>>> master
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        resultTextBox = new QPlainTextEdit(tab);
        resultTextBox->setObjectName(QStringLiteral("resultTextBox"));
<<<<<<< HEAD
        resultTextBox->setGeometry(QRect(0, 0, 681, 191));
=======
        resultTextBox->setGeometry(QRect(0, 0, 681, 111));
>>>>>>> master
        outputTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ErrorTextBox = new QPlainTextEdit(tab_2);
        ErrorTextBox->setObjectName(QStringLiteral("ErrorTextBox"));
<<<<<<< HEAD
        ErrorTextBox->setGeometry(QRect(-7, -4, 681, 191));
        outputTabWidget->addTab(tab_2, QString());
=======
        ErrorTextBox->setGeometry(QRect(-7, -4, 681, 121));
        outputTabWidget->addTab(tab_2, QString());
        curveGraphView = new CurveForm(centralWidget);
        curveGraphView->setObjectName(QStringLiteral("curveGraphView"));
        curveGraphView->setGeometry(QRect(20, 380, 671, 341));
>>>>>>> master
        view->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(view);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 26));
        view->setMenuBar(menuBar);
        mainToolBar = new QToolBar(view);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        view->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(view);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        view->setStatusBar(statusBar);

        retranslateUi(view);
        QObject::connect(returnButton, SIGNAL(clicked()), inputTextBox, SLOT(copy()));

<<<<<<< HEAD
        outputTabWidget->setCurrentIndex(0);
=======
        outputTabWidget->setCurrentIndex(1);
>>>>>>> master


        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QMainWindow *view)
    {
        view->setWindowTitle(QApplication::translate("view", "MainWindow", Q_NULLPTR));
        returnButton->setText(QApplication::translate("view", "PushButton", Q_NULLPTR));
        outputTabWidget->setTabText(outputTabWidget->indexOf(tab), QApplication::translate("view", "Output", Q_NULLPTR));
        outputTabWidget->setTabText(outputTabWidget->indexOf(tab_2), QApplication::translate("view", "Error/Warning", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
