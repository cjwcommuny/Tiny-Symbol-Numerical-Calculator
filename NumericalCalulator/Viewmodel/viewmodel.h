#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <memory>
#include "Common/etlbase.h"
#include "Model/model.h"
#include "Parameter/parameter.h"
#include "Common/command.h"
#include "Viewmodel/Command/getexpressioncommand.h"
#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Common/point.h"


class Model;

class Viewmodel: public Proxy_PropertyNotification<Viewmodel>, public Proxy_CommandNotification<Viewmodel>
{
public:
    Viewmodel();
    void bind(std::shared_ptr<Model> model);
    bool process_expression(std::string str);
    std::shared_ptr<std::string> getResult();
    std::shared_ptr<std::vector<Point>> getVertexArr() { return _vertexArr; }
    std::shared_ptr<Command> get_getExpressionCommand() {return std::static_pointer_cast<Command>(get_expression_command);}
protected:

private:
    std::shared_ptr<OutputNumericalResultNotification_viewmodel> notification;
    std::shared_ptr<Model> _model;
    std::shared_ptr<getExpressionCommand> get_expression_command;
    std::shared_ptr<std::string> result;
    std::shared_ptr<std::vector<Point>> _vertexArr;
    void notify(std::string str);
};

#endif // VIEWMODEL_H
