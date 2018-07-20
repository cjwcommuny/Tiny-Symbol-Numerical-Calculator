#include "View/view.h"
#include "ui_view.h"
#include <QPainter>
#include <iostream>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view),
    notification(std::make_shared<OutputNumericalResultNotification_view>(this)),
    notification_error(std::make_shared<OutputErrorNotification_view>(this))
{
    ui->setupUi(this);
    setupEditor();
    //ui->curveGraphView->getNotification()
}

View::~View()
{
    delete ui;
}

void View::on_returnButton_clicked()
{
    QString str = ui->inputTextBox->toPlainText();
    get_expression_command->SetParameter(std::make_shared<StringParameter>(str.toStdString()));
    get_expression_command->Exec();
}

void View::ChangeOutputResultText(const std::string str)
{
    ui->resultTextBox->setPlainText(QString::fromStdString(str));
}

std::shared_ptr<std::string> View::getResult() const
{
    return result;
}

void View::paintEvent(QPaintEvent *)
{
    QPainter painter(ui->curveGraphView);
    painter.drawLine(QPointF(0, 0), QPointF(100, 100));
}


void View::setupEditor()
{
    highlighter = new HighlightTextBox(ui->inputTextBox->document());
}

void View::drawCurve()
{
    std::cout << "===========draw curve==========" << std::endl;
    getUi()->curveGraphView->setVertexArr(getVertexArr());
    getUi()->curveGraphView->setIsDraw(true);
    getUi()->curveGraphView->update();
}
