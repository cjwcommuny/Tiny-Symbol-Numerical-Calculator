#include "curveform.h"
#include "ui_curveform.h"
#include <QPainter>
#include "Common/point.h"
#include <iostream>

CurveForm::CurveForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CurveForm),
    _vertexArr(nullptr),
    isDraw(false)
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
    //painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(rect());

    //pen used to draw axis
    QPen coodinatePen; 
    coodinatePen.setWidth(3); //设置宽度 
    coodinatePen.setBrush(Qt::black); //设置颜色 
    //painter.setPen(coodinatePen); //选中画笔

    //pen used to draw text
    QPen textPen;
    textPen.setWidth(2);
    textPen.setBrush(Qt::black);

    //pen used to draw curve
    QPen curvePen;
    curvePen.setWidth(3);
    curvePen.setBrush(Qt::red);

    if (isDraw == true) {
        //QPainter painter(this);
        std::cout << "==========isDraw = true =========" << std::endl;
        const double segment = 15;
        double realWidth = this->geometry().width() - segment;
        double realHeight = this->geometry().height() - segment;
        //generate a vertex array
        std::vector<Point> &vertexArr = *_vertexArr;
        std::cout << "=============== curveForm _vertexArr test ===========" << std::endl;
        foreach (auto point, *_vertexArr) {
            std::cout << "X: " << point.getX() << " Y: " << point.getY() << std::endl;
        }
        std::cout << "=============== curveForm _vertexArr test end===========" << std::endl;

        //get xMax and yMax
        double xMax = 0, yMax = 0;//modify for test
        foreach (auto point, vertexArr) {
            if (point.getX() > xMax) {
                xMax = point.getX();
            }
            if (point.getY() > yMax) {
                yMax = point.getY();
            }
        }

        //compute factor 
        double xFactor = xMax / realHeight;
        double yFactor = yMax / realWidth;
        double factor = (xFactor < yFactor) ? xFactor : yFactor;

        //draw curve
        painter.setPen(curvePen);
        int x = 0, y = 0;
        int xPre = segment, yPre = realHeight;
        std::cout << "factor: " << factor << " segment: " << segment << " realhight: " << realHeight << " realwidth: " << realWidth << std::endl;
        std::cout << "============ draw curve===============" << std::endl;
        foreach (auto point, vertexArr) {
            x = point.getX() / factor + segment;
            y = realHeight - point.getY() / factor;
            std::cout << "X: " << x << " Y: " << y << std::endl;
            if (x > realWidth || y < segment) {//point out of widget view
                break;
            }
            painter.drawLine(QPointF(xPre, yPre), QPointF(x, y));
            xPre = x;
            yPre = y;
        }
        std::cout << "============ curve drawing end ===============" << std::endl;

        //draw coodinate system
        const int scale = 50;
        const int scaleTeeth = 5;
        painter.setPen(coodinatePen);
        painter.drawLine(QPointF(segment, realHeight), QPointF(realWidth, realHeight)); //x axis
        painter.drawLine(QPointF(segment, realHeight), QPointF(segment, segment)); //y axis
        painter.drawLine(QPointF(realWidth, realHeight), QPointF(realWidth - scaleTeeth, realHeight - scaleTeeth));//x-arrow
        painter.drawLine(QPointF(realWidth, realHeight), QPointF(realWidth - scaleTeeth, realHeight + scaleTeeth));//x-arrow
        painter.drawLine(QPointF(segment, segment), QPointF(segment - scaleTeeth, segment + scaleTeeth)); //y-arrow
        painter.drawLine(QPointF(segment, segment), QPointF(segment + scaleTeeth, segment + scaleTeeth)); //y-arrow
        int xScaleNum = (realWidth + segment - 2 * segment) / scale;
        int yScaleNum = (realHeight - segment) / scale;
        painter.setPen(textPen);
        painter.drawText(QPointF(0 + scaleTeeth, realHeight + segment - scaleTeeth), QString::number(0));//(0,0) point
        for (int i = 1; i < xScaleNum; ++i) {// x axis
            painter.setPen(coodinatePen);
            painter.drawLine(QPointF(i * scale, realHeight), QPointF(i * scale, realHeight - scaleTeeth));
            painter.setPen(textPen);
            painter.drawText(QPointF(i * scale, realHeight - scaleTeeth), QString::number(int(i * scale * factor)));
        }
        for (int i = 1; i < yScaleNum; ++i) {// y axis
            painter.setPen(coodinatePen);
            painter.drawLine(QPointF(segment, realHeight - i * scale), QPointF(segment + scaleTeeth, realHeight - i * scale));
            painter.setPen(textPen);
            painter.drawText(QPointF(segment + scaleTeeth, realHeight - i * scale), QString::number(int(i * scale * factor)));
        }

    }
}
