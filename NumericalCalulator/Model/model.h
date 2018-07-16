#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "lib/etlbase.h"
#include "Common/matrix.h"
#include "Notification/notification.h"
#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Viewmodel/viewmodel.h"
#include "Common/matrix.h"

class Viewmodel;
class Matrix;

class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    void notify();
    void transmit_expression(std::string str);
    std::shared_ptr<std::string> getExpression() {return expression;}
private:
    std::shared_ptr<std::string> expression;
<<<<<<< HEAD
    template <typename T, typename sizeT = size_t>
    std::shared_ptr<matrix<T, sizeT>> SingleRowmatrixParser(std::string expression);
    template <typename T, typename sizeT = size_t>
    std::shared_ptr<matrix<T, sizeT>> matrixParser(std::string expression);
=======
    std::shared_ptr<Matrix> matrixParser(std::string expression);
>>>>>>> 5ce1cec1d081c58a6e672e29aadc875035c4d560
};

#endif // MODEL_H
