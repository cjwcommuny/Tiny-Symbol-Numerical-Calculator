#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <memory>
#include "lib/etlbase.h"
#include "Viewmodel/Command/command.h"
#include "Viewmodel/Command/getexpressioncommand.h"
#include "Notification/notification.h"

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
signals:

public slots:
private slots:
    void on_returnButton_clicked();

private:
    Ui::view *ui;

    std::shared_ptr<Command> get_expression_command;

    //notification
    OutputNumericalResultNotification notification;
};

#endif // WINDOW_H
