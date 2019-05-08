#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "qmessagebox.h"
#include "qfile.h"

#include "pacote.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connectionInit() to be called whenever the connection is estabished
    connect(&tcpSocket,SIGNAL(connected()), this, SLOT(connectionInit()));

    // handleError( ); is called if an error occurs when connecting to the server
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(handleError(QAbstractSocket::SocketError)));

    // dataArrived(); is called when the data has arrived from the server
    connect(&tcpSocket,SIGNAL(readyRead()),this, SLOT(dataArrived()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_SelectFile_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName(this,"Selecione o arquivo","C://","Text File (*.txt)");
    ui->lineEdit_nomeArquivo->setText(strFileName);
}

void MainWindow::connectionInit()
{
    QMessageBox::information(this,"Connected", "Connection Successful");

    ui->pushButton_Connect->setText("Conectado");

}

void MainWindow::handleError(QAbstractSocket::SocketError err)
{
    QMessageBox::critical(this,"Error", tcpSocket.errorString());

    tcpSocket.close();
}
void MainWindow::dataArrived()
{
    QByteArray buf = tcpSocket.read(200); //maximum read 100 bytes

    pacote p;


    bool e = p.desempacotarMensagem(buf);

    ui->textEdit->append(buf);

    if(e==true){
        QString msg = QString("Arquivo %1 recebido de %2 para %3").arg(p.getNomeArquivo()).arg(p.getRemetente()).arg(p.getDestinatario());
        QMessageBox::information(this,"Arquivo recebido", msg);
        salvarArquivo(p.getNomeArquivo(), p.getConteudoArquivo());

        ui->textEdit->append(QString("Server >> ") +p.getDestinatario()); //put this data into the text browser

    }else{
        QMessageBox::information(this,"Arquivo recebido", "Arquivo recebido mas corrompido!");
    }

}

void MainWindow::salvarArquivo(QString nome, QString conteudo)
{
    QFile f(nome);

    if(f.exists()) {// Se arquivo existe
        QMessageBox::critical(this, "Error", "Um arquivo com este nome já existe");
        return;
    }

    if ( f.open(QIODevice::ReadWrite) )
    {
        QTextStream stream(&f);
        stream << conteudo << endl;
        f.flush();
        f.close();

    }else{
        QMessageBox::critical(this,"Error", "Algo errado ao criar arquivo");
    }
}



void MainWindow::on_pushButton_Connect_clicked()
{
    // Read the IP address from the text field in the UI (user-interface)
    QHostAddress addr( ui->lineEdit_ServerIp->text() );

    // Attempt to connect to server
    // Note : For simplicity we are not doing a DNS lookup of the IP address. But in real application you need
    //        to do a DNS lookup before attempting to connect. Please search on google "Qt DNS lookup" to
    //        understand how to do a DNS lookup
    tcpSocket.connectToHost(addr, ui->lineEdit_ServerPort->text().toUShort()  );

}

void MainWindow::on_pushButton_SendFile_clicked()
{
    if( !tcpSocket.isOpen() )
    {
        QMessageBox::critical(this, "No Server Connected", "No Server Connected");
        return;
    }


    pacote p = pacote();
    p.setConteudoArquivo( conteudoArquivo(ui->lineEdit_nomeArquivo->text()));

    p.setNomeArquivo(ui->lineEdit_nomeArquivo->text());
    p.setDestinatario(ui->lineEdit_Destino->text());
    p.setRemetente(ui->lineEdit_ServerIp->text());
    p.setRemetente("0");

    p.empacotarMensagem(&msg);

    tcpSocket.write(msg.toUtf8());
}

QString MainWindow::conteudoArquivo(QString nome){
        {
            QMessageBox::critical(this, "No Server Connected", "No Server Connected");
            return;
        }
        // Retrive the text that is written in the UI. The input area where we are supposed to write our message
        QString str = ui->lineEdit_nomeArquivo->text();

        // Send this data to the server. str.ToUtf8() is done to convert QStrint to QByteArray.
        // Never mind if you don't understand this clearly. Just remember this conversion is required if you want to send
        // the data
        tcpSocket.write(str.toUtf8());

        // Set this same data into the textBrower.
        // Note : 2 strings can be concatenated with a "+"
//        ui->textBrowser->append(QString("ME >> ")+str);

        // Clear the sending input box
        ui->lineEdit_nomeArquivo->clear();
}
