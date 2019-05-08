#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    x = new QVector<double>(0);//vai alocando os dados conforme necessário, o QVector já aloca dinamicamente quando um dado é inserido
//    y1 = new QVector<double>(0);//
//    y2 = new QVector<double>(0);//
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRandomY_clicked()

{

    sleep(1);
    if(dblBtnCounter<10)
    {
        int xPos = QString::number(dblBtnCounter).toInt();
        x.insert(xPos,dblBtnCounter);
        y1.insert(xPos,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
        y2.insert(xPos,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
    }
    else
    {
        for(int i = 0; i<9;i++)
        {
          x.replace(i,x.value(i+1));
          y1.replace(i,y1.value(i+1));
          y2.replace(i,y2.value(i+1));
        }
        x.replace(9,dblBtnCounter);
        y1.replace(9,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
        y2.replace(9,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
        minX++;
        maxX++;
    }
    ui->grafico->addGraph();
    ui->grafico->addGraph();
    ui->grafico->graph(0)->setData(x,y1);
    ui->grafico->graph(1)->setData(x,y2);
    ui->grafico->xAxis->setLabel("x");
    ui->grafico->yAxis->setLabel("y");
    ui->grafico->xAxis->setRange(minX,maxX);
    ui->grafico->yAxis->setRange(0,10);
    ui->grafico->graph(0)->setPen(QPen(Qt::green)); //linha do grafico verde
    ui->grafico->graph(1)->setPen(QPen(Qt::red)); //linha do grafico vermelho
    ui->grafico->replot();

    dblBtnCounter++;
}
