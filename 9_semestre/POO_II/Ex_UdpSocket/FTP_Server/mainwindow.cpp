#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStringListModel"

#include "pacote.h"

<<<<<<< HEAD
#include <pthread.h>

=======

void MainWindow::ReplotGrafico()
{
    objGrafico->replot(counter);
}
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set : acceptTheConnection() will be called whenever there is a new connection
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptTheConnection()));
<<<<<<< HEAD
=======

    objGrafico = new GraphicThread();
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
}

MainWindow::~MainWindow()
{
    delete ui;
}


// This fucnction will be called when the button (in the ui) called "startServer" is clicked
void MainWindow::on_startServer_clicked()
{
    // Retrive port number from the user-interface (ui)
//    QString portNum = ui->port->text();

    // Instruction to start listening for incoming connection.
    bool status = tcpServer.listen(QHostAddress::Any, portValue );

    // Check, if the server did start correctly or not
    if( status == true )
    {
        QMessageBox::information(this,"Server Started", QString("Server now listening on port# ")+portValue );
//        ui->statusLabel->setText( QString("Server now listening on port# ")+portValue );
    }
    else
    {
        QMessageBox::critical(this, "Server Start failure", tcpServer.errorString() );
    }
    portValue++;
}


// This function is called whenever we have an incoming connection
void MainWindow::acceptTheConnection()
{

    // In the label (in the ui) print that there in an in-comming connection
//    ui->statusLabel->setText("Incoming connection");

    // Accept and establish the connection. Note that, the data-transfer happens with `connectionSoc` and not with `tcpServer`
    // `tcpServer` only waits and listens to new connections
    socketUsersMap.insert(counter,tcpServer.nextPendingConnection());


<<<<<<< HEAD


=======
    ui->textEdit->append("Cliente - " + QString::number(counter));


//    for(int i=0; i<socketUsersMap.size(); i++){
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
        // Set : respondToConnection() will be called whenever the data (coming from client) is available
        connect(socketUsersMap[counter], SIGNAL(readyRead()), this, SLOT(respondToConnection()) );

        // Set : connectionAboutToClose() will be called whenever the connection is close by the client
        connect(socketUsersMap[counter], SIGNAL(disconnected()), this, SLOT(connectionAboutToClose()));

<<<<<<< HEAD
        qDebug() << socketUsersMap.size();

        ui->textEdit->clear();

        //Avisar todos os usuarios de um novo cliente na rede
        foreach (QTcpSocket* socket, socketUsersMap) {
            ui->textEdit->append("Cliente - " + socketUsersMap.key(socket));


            QString msg;

            pacote p = pacote();

            p.setConteudoArquivo("OK");
            p.setDestinatario("9");
            p.setNomeArquivo("OK");
            p.setRemetente("9");

            p.empacotarMensagem(&msg);

            qDebug() << msg;
            foreach (QTcpSocket* socketFinal, socketUsersMap) {
                socketFinal->write(msg.toUtf8());
            }
        }
          counter ++;


=======


        //Avisar todos os usuarios de um novo cliente na rede
//        for(int j = 0; j<socketUsersMap.size(); j++) {
//            QString bufString = "Cliente - " + counter;
//            bufString = bufString.toUpper();
//            socketUsersMap[j]->write(bufString.toUtf8());
//        }

        counter ++;

        ReplotGrafico();
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
}

// Will be called whenever the data (coming from client) is available
void MainWindow::respondToConnection()
{

//    QTcpSocket clientSender = new QTcpSocket();
//    QTcpSocket clientReciever = new QTcpSocket();

    for(int i=0; i<socketUsersMap.size(); i++){
        // Declare a byte array (this is how it is done with Qt)
        QByteArray buf;

        // Read the incoming data. Here 200 is the maximum length
        buf = socketUsersMap[i]->read(200);

        if(!buf.isEmpty()){

            pacote p = pacote();
            p.desempacotarMensagem(buf);

            int destinatario = p.getDestinatario().toInt();

<<<<<<< HEAD
            ui->textEdit->append(QString::number(destinatario));

            socketUsersMap[i]->write(buf);
=======
            socketUsersMap[destinatario]->write(buf);
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
        }
    }
}


// Will be called whenever the connection is close by the client
void MainWindow::connectionAboutToClose()
{

<<<<<<< HEAD
    foreach (QTcpSocket* socket, socketUsersMap) {
        QString bufString = QString::number(socketUsersMap.key(socket)) + " / ";
        bufString = bufString.toUpper();
        foreach (QTcpSocket* socketFinal, socketUsersMap) {
            socketFinal->write(bufString.toUtf8());
        }
=======
    //Avisar todos os usuarios de um novo cliente na rede
    for(int j = 0; j<socketUsersMap.size(); j++) {
//        if( !socketUsersMap[j]->isOpen() ) {
//            socketUsersMap[j]->close();
//        } else {
            QString bufString = "Desconectado - " + j;
            bufString = bufString.toUpper();
            socketUsersMap[j]->write(bufString.toUtf8());
//        }
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
    }
}

