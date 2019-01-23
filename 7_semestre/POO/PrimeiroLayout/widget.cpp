#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sum_clicked()
{
    float firstValue, secondValue;

    firstValue = ui->op1->text().toFloat(NULL);
    secondValue = ui->op2->text().toFloat(NULL);

    ui->result->setText(QString("%1").arg(firstValue+secondValue));
}

void Widget::on_sub_clicked()
{
    float firstValue, secondValue;

    firstValue = ui->op1->text().toFloat(NULL);
    secondValue = ui->op2->text().toFloat(NULL);

    ui->result->setText(QString("%1").arg(firstValue-secondValue));
}

void Widget::on_mult_clicked()
{
    float firstValue, secondValue;

    firstValue = ui->op1->text().toFloat(NULL);
    secondValue = ui->op2->text().toFloat(NULL);

    ui->result->setText(QString("%1").arg(firstValue*secondValue));
}

void Widget::on_div_clicked()
{
    float firstValue, secondValue;

    firstValue = ui->op1->text().toFloat(NULL);
    secondValue = ui->op2->text().toFloat(NULL);

    ui->result->setText(QString("%1").arg(firstValue/secondValue));
}


void Widget::on_cc_clicked()
{
    ui->op1->setText("");
    ui->op2->setText("");
    ui->result->setText("");
}
