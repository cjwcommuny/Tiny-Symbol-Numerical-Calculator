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

namespace Ui {
class view;
}


class View : public QMainWindow, public Proxy_PropertyNotification<View>
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    ~View();

    void set_get_expression_command(std::shared_ptr<Command> command);
    void bind(std::shared_ptr<Viewmodel> viewmodel) {_viewmodel = viewmodel;}
signals:

public slots:
private slots:
    void on_returnButton_clicked();

private:
    Ui::view *ui;
    std::shared_ptr<Viewmodel> _viewmodel;

    std::shared_ptr<Command> get_expression_command;

    //notification
    OutputNumericalResultNotification_view notification;

    void ChangeOutputResultText(const std::string str);
};

#endif // WINDOW_H
