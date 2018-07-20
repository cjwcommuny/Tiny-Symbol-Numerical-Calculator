#ifndef CURVEFORM_H
#define CURVEFORM_H

#include <QFrame>
#include <memory>
#include <vector>
#include "common/point.h"

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
    void setVertexArr(std::shared_ptr<std::vector<Point>> vertexArr) { _vertexArr = vertexArr; }
    void setIsDraw(bool flag) { isDraw = flag; }
    //std::shared_ptr<OutputNumericalResultNotification_curveform> getNotification() {return notification;}
    //Ui::CurveForm getUi() {return ui;}
  private:
    //std::shared_ptr<OutputNumericalResultNotification_curveform> notification;
    Ui::CurveForm *ui;
    std::shared_ptr<std::vector<Point>> _vertexArr;
    bool isDraw;
};

#endif // CURVEFORM_H
