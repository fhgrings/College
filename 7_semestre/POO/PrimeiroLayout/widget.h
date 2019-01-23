#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_sum_clicked();

    void on_sub_clicked();

    void on_mult_clicked();

    void on_div_clicked();

    void on_cc_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
