#include "curveform.h"
#include "ui_curveform.h"
#include <QPainter>

CurveForm::CurveForm(QWidget *parent) :
    QFrame(parent),
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
    //painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(rect());
}