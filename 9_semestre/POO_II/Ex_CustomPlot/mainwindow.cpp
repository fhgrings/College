#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f = new QFile();
}

MainWindow::~MainWindow()
{
    delete ui;
    f->close();
    delete f;
}

void MainWindow::leDados()
{
    QStringList strDados;

    while(!f->atEnd())
       strDados.append(f->readLine());

    QVector <double> x(strDados.length()),y(strDados.length());
    QString it ="";

    QStringList *temp = new QStringList();

    it = strDados[1];

    temp->append(it.split("",QString::KeepEmptyParts));
    int i=0;
    double minX = temp->first().toDouble();
    double minY = temp->last().toDouble();
    double maxX = 0 , maxY=0;

    delete temp;

    foreach(it,strDados)
    {
        if(i>0)
        {
            QStringList strLine;
            strLine = it.split(" ",QString::KeepEmptyParts);

            double dataX = strLine.first().toDouble();
            double dataY = strLine.last().toDouble();

            x[i-1] = dataX;
            y[i-1] = dataY;
            if(dataX>maxX)
                maxX = dataX;
            if(dataX<minX)
                minX = dataX;

            if(dataY>maxY)
                maxY = dataY;
            if(dataY<minY)
                minY = dataY;
        }
        i++;
    }
    ui->grafico->addGraph();
    ui->grafico->graph(0)->setData(x,y);
    ui->grafico->xAxis->setLabel("x");
    ui->grafico->yAxis->setLabel("y");
    ui->grafico->xAxis->setRange(minX,maxX+1);
    ui->grafico->yAxis->setRange(minY,maxY+1);
    ui->grafico->replot();
}

void MainWindow::on_btn_select_clicked()
{
        QString strFileName = QFileDialog::getOpenFileName(this,"Selecione o arquivo","C://");
        ui->lineEdit_file->setText(strFileName);

        f->setFileName(ui->lineEdit_file->text());// Associa o objeto f a um arquivo chamado com nome digitado no campo

        if( !f->exists() ) {// Arquivo não existe
            ui->label_sucesss->setText("Arquivo não Existe.");
            return;
        }

        if( !f->open(QIODevice::ReadOnly | QIODevice::Text) ){ // Se existir abre
             ui->label_sucesss->setText( "Sem permissão para Abrir o arquivo.");
             return;
        }

        ui->label_sucesss->setText( "Arquivo Aberto com Sucesso.");

        leDados();
}
