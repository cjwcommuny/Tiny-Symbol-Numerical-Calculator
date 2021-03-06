#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <memory>
#include "Common/etlbase.h"
#include "Common/command.h"
#include "Notification/outputnumericalresultnotification_view.h"
#include "Notification/outputerrornotification_view.h"
#include "View/highlighttextbox.h"
#include "Common/point.h"


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

    void ChangeOutputResultText(const std::string str);
    std::shared_ptr<std::string> getResult() const;
    std::shared_ptr<std::vector<Point>> getVertexArr() const { return _vertexArr; }
    void set_getExpressionCommand(std::shared_ptr<Command> get_expression_command)
        {this->get_expression_command = get_expression_command;}
    void setResult(std::shared_ptr<std::string> result) {this->result = result;}
    void setVertexArr(std::shared_ptr<std::vector<Point>> vertexArr) { _vertexArr = vertexArr; }
    std::shared_ptr<OutputNumericalResultNotification_view> getNotification() {return notification;}
    std::shared_ptr<OutputErrorNotification_view> getNotificationError() {return notification_error;}
    Ui::view *getUi() {return ui;}
    void drawCurve();

signals:

public slots:
private slots:
    void on_returnButton_clicked();

private:
    //notification
    std::shared_ptr<OutputErrorNotification_view> notification_error;
    std::shared_ptr<OutputNumericalResultNotification_view> notification;
    Ui::view *ui;

    std::shared_ptr<Command> get_expression_command;
    std::shared_ptr<std::string> result;
    std::shared_ptr<std::vector<Point>> _vertexArr;

    void setupEditor();
    HighlightTextBox *highlighter;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // WINDOW_H
