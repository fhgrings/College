<<<<<<< HEAD
//#include "graphicthread.h"

//GraphicThread::GraphicThread()
//{

//}

//void GraphicThread::run()
//{
//    sleep(1);
//    if(dblBtnCounter<10)
//    {
//        int xPos = QString::number(dblBtnCounter).toInt();
//        x.insert(xPos,dblBtnCounter);
//        y1.insert(xPos,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
//        y2.insert(xPos,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
//    }
//    else
//    {
//        for(int i = 0; i<9;i++)
//        {
//          x.replace(i,x.value(i+1));
//          y1.replace(i,y1.value(i+1));
//          y2.replace(i,y2.value(i+1));
//        }
//        x.replace(9,dblBtnCounter);
//        y1.replace(9,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
//        y2.replace(9,((10 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0));
//        minX++;
//        maxX++;
//    }
//    ui->grafico->addGraph();
//    ui->grafico->addGraph();
//    ui->grafico->graph(0)->setData(x,y1);
//    ui->grafico->graph(1)->setData(x,y2);
//    ui->grafico->xAxis->setLabel("x");
//    ui->grafico->yAxis->setLabel("y");
//    ui->grafico->xAxis->setRange(minX,maxX);
//    ui->grafico->yAxis->setRange(0,10);
//    ui->grafico->graph(0)->setPen(QPen(Qt::green)); //linha do grafico verde
//    ui->grafico->graph(1)->setPen(QPen(Qt::red)); //linha do grafico vermelho
//    ui->grafico->replot();

//    dblBtnCounter++;
//}
=======
#include "graphicthread.h"
#include "time.h"
GraphicThread::GraphicThread()
{
    RangeMin = 0;
}

GraphicThread::~GraphicThread()
{

}

void GraphicThread::replot(double pConexoes)
{
    VEtempo.append(dblTempo);
    Conexoes.append(pConexoes);
    grafico.addGraph();
    grafico.graph(0)->setData(VEtempo,Conexoes);
    grafico.xAxis->setLabel("Tempo(s)");
    grafico.yAxis->setLabel("Conexoes/min");
    grafico.graph(0)->setPen(QPen(Qt::red)); //linha do grafico verde
    grafico.replot();

    if(RangeMin<5)
    {
        grafico.xAxis->setRange(0,5);
    }
    else
    {
        grafico.xAxis->setRange(RangeMin,RangeMin+5);
    }

    grafico.yAxis->setRange(0,100);

    RangeMin++;
}
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
