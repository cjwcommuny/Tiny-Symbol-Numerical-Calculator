#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include <vector>
#include "Common/etlbase.h"
#include "Common/matrix.h"
#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Viewmodel/viewmodel.h"
#include "Common/matrix.h"
#include "Algorithm/matrixparser.h"
#include "Algorithm/computedeterminant.h"
#include "Common/Point.h"




class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    void notifyResult();
    void notifyCurveResult();
    void notifyFailure();
    bool transmit_expression(std::string str);
    std::shared_ptr<std::string> getExpression() {return expression;}
    std::shared_ptr<std::vector<Point>> getVertexArr() { return _vertexArr; }
  private:
    std::shared_ptr<std::string> expression;
    std::shared_ptr<std::vector<Point>> _vertexArr;
};

#endif // MODEL_H
