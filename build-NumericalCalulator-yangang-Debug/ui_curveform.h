/********************************************************************************
** Form generated from reading UI file 'curveform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEFORM_H
#define UI_CURVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveForm
{
public:

    void setupUi(QWidget *CurveForm)
    {
        if (CurveForm->objectName().isEmpty())
            CurveForm->setObjectName(QStringLiteral("CurveForm"));
        CurveForm->resize(400, 300);

        retranslateUi(CurveForm);

        QMetaObject::connectSlotsByName(CurveForm);
    } // setupUi

    void retranslateUi(QWidget *CurveForm)
    {
        CurveForm->setWindowTitle(QApplication::translate("CurveForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveForm: public Ui_CurveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEFORM_H
