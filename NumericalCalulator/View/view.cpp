#include "View/view.h"
#include "ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::view)
{
     ui->setupUi(this);
}

View::~View()
{
    delete ui;
}
