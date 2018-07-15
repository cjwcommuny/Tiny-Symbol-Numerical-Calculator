#include "View/view.h"
#include "ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::view), notification(std::make_shared<OutputNumericalResultNotification_view>(this)), get_expression_command(std::make_shared<getExpressionCommand>(_viewmodel.get()))
{
     ui->setupUi(this);
     AddNotification(notification);//bind notification
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

void View::set_get_expression_command(std::shared_ptr<Command> command)
{
    get_expression_command = command;

}

void View::ChangeOutputResultText(const std::string str)
{
    ui->resultTextBox->setPlainText(QString::fromStdString(str));
}
