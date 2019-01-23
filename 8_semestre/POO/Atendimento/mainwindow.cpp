#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQueue>
#include "ticket.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filaNormal=0;
    filaPreferencial=1;
    escolhaFila =0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_normalPushButton_clicked()
{
    filaNormal+=2;
    Ticket ticket(filaNormal);
    normalQueue.enqueue(ticket);
    ui->numeroLineEdit->setText(QString("%1").arg(filaNormal));

}

void MainWindow::on_prioritariaPushButton_clicked()
{
    filaPreferencial+=2;
    Ticket ticket(filaPreferencial);
    preferencialQueue.enqueue(ticket);
    ui->numeroLineEdit->setText(QString("%1").arg(ticket.value));

}

void MainWindow::on_atenderPushButton_clicked()
{


    if (!preferencialQueue.isEmpty()){
        Ticket ticket = preferencialQueue.dequeue();
        ui->lineEdit_num_atendido->setText(QString("%1").arg(ticket.value));
        ui->lineEdit_hora->setText(QString("%1").arg(ticket.timeString));
    } else
        escolhaFila=2;

    if(escolhaFila==2){
        if (!normalQueue.isEmpty()){
            Ticket ticket = normalQueue.dequeue();
            ui->lineEdit_num_atendido->setText(QString("%1").arg(ticket.value));
            ui->lineEdit_hora->setText(QString("%1").arg(ticket.timeString));
        }
        else
            ui->lineEdit_num_atendido->setText("No client");

        escolhaFila=0;
    }

    escolhaFila++;
}
