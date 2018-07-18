#include "curveform.h"
#include "ui_curveform.h"
#include "QPainter"
#include <cmath>

CurveForm::CurveForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurveForm)
{
    ui->setupUi(this);
}

CurveForm::~CurveForm()
{
    delete ui;
}

void CurveForm::paintEvent(QPaintEvent*e)
{
    QPainter painter(this);
    size_t height = 300;
    size_t width = 400;
    std::cout << "=============start test==========" << std::endl;
    std::string str("x^2 + x + 1");
    LinkList l(str);
    l.get();
    std::cout << "============= parser end===========" << std::endl;
    vector<Point> po = generatePolynomialPoint(l, 0, 400, 1, 400, 300);
    std::cout << "============= generate end===========" << std::endl;
    double xPre = 0, yPre = 0;
    double x = 0, y = 0;
    for (auto iter = po.begin(); iter != po.end(); ++iter) {
        x = iter->getX();
        y = height - iter->getY();
        painter.drawLine(QPointF(x, height-y), QPointF(xPre, height - yPre));
        xPre = x;
        yPre = y;
    }
    //size_t height = height();
    //size_t width = width();
    /*
    size_t height = 300;
    size_t width = 400;
    double xPre = 0, yPre = 0;
    double x = 0, y = 0;
    int segmentNum = 200;
    int yFactor = 100;
    int yDisplacement = 100;
    for (int i = 0; i < segmentNum; ++i) {
        x = width / segmentNum * i;
        y = yFactor * sin(x) + yDisplacement;
        painter.drawLine(QPointF(x, height-y), QPointF(xPre, height - yPre));
        xPre = x;
        yPre = y;
    }*/
    //painter.drawLine(QPointF(0, 0), QPointF(100, 100));
}


