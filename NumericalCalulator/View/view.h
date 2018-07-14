#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
class view;
}


class View : public QMainWindow
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    ~View();
signals:

public slots:
private:
    Ui::view *ui;
};

#endif // WINDOW_H
