#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <memory>
#include "lib/etlbase.h"
#include "Viewmodel/Command/command.h"
#include "Viewmodel/Command/getexpressioncommand.h"
#include "Notification/notification.h"

class OutputNumericalResultNotification_view;
class OutputNumericalResultNotification_viewmodel;
class Command;
class Viewmodel;

namespace Ui {
class view;
}


class View : public QMainWindow
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    ~View();

    //void set_get_expression_command(std::shared_ptr<Command> command);
    //void bind(std::shared_ptr<Viewmodel> viewmodel) {_viewmodel = viewmodel;}
    std::shared_ptr<OutputNumericalResultNotification_view> notification;
    void ChangeOutputResultText(const std::string str);
    std::shared_ptr<std::string> getResult() const;
    void set_getExpressionCommand(std::shared_ptr<Command> get_expression_command)
        {this->get_expression_command = get_expression_command;}
    void setResult(std::shared_ptr<std::string> result) {this->result = result;}
signals:

public slots:
private slots:
    void on_returnButton_clicked();

private:
    Ui::view *ui;
    //std::shared_ptr<Viewmodel> _viewmodel;

    std::shared_ptr<Command> get_expression_command;
    std::shared_ptr<std::string> result;
    //notification



};

#endif // WINDOW_H
