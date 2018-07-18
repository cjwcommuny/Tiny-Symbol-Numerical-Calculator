#ifndef CURVEFORM_H
#define CURVEFORM_H

#include <QWidget>
#include "Common/polynomial.h"
#include "Common/drawpolynomialcurve.h"

namespace Ui {
class CurveForm;
}

class CurveForm : public QWidget
{
    Q_OBJECT

public:
    explicit CurveForm(QWidget *parent = 0);
    ~CurveForm();
    void paintEvent(QPaintEvent*e);

private:
    Ui::CurveForm *ui;

};

#endif // CURVEFORM_H
