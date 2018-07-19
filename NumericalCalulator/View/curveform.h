#ifndef CURVEFORM_H
#define CURVEFORM_H

#include <QFrame>

namespace Ui {
class CurveForm;
}

class CurveForm : public QFrame
{
    Q_OBJECT

public:
    explicit CurveForm(QWidget *parent = 0);
    ~CurveForm();
    void paintEvent(QPaintEvent *e);

  private:
    Ui::CurveForm *ui;
};

#endif // CURVEFORM_H
