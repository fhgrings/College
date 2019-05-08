<<<<<<< HEAD
//#include "QVector"
//#include "QThread"

//#define GRAPHICTHREAD_H


//class GraphicThread : public QThread
//{
//    Q_OBJECT

//protected:
//    void run();

//private:

//    double dblBtnCounter = 0;
//    QVector <double> x,y1,y2;
//    int minX = 0 , maxX = 9;

//};
=======
#include "QVector"
#include "QThread"
#include "qcustomplot.h"

class GraphicThread
{
public:
    GraphicThread();
    ~GraphicThread();

    QCustomPlot grafico;

    void replot(double pConexoes);

private:
    QVector <double> VEtempo,Conexoes;
    int RangeMin;

    double dblTempo;

};
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787

