#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "Model/model.h"
#include <memory>

class Viewmodel
{
public:
    Viewmodel();
protected:

private:
    std::shared_ptr<Model> model;
};

#endif // VIEWMODEL_H
