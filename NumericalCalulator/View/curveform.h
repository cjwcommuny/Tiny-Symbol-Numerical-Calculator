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
    void setVertexArr(std::shared_ptr<vector<Point>> vertexArr) { _vertexArr = vertexArr; }
    void setIsDraw(bool flag) { isDraw = flag; }

  private:
    Ui::CurveForm *ui;
    std::shared_ptr<vector<Point>> _vertexArr;
    bool isDraw;
};

#endif // CURVEFORM_H
