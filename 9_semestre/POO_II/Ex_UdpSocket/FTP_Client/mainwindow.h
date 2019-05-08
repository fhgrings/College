#define MAINWINDOW_H

#include "qlist.h"
#include "qstring.h"
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();





private slots:

    // This function is called when the connection has been established successfully with the server stated.
    void connectionInit();

    // This function is called if there is an error (or disruption) in the connection
    void handleError(QAbstractSocket::SocketError err);

    // This function is called when the data is fully arrived from the server to the client
    void dataArrived();

    void salvarArquivo(QString nome, QString conteudo);

    //This function is called when you click on select file
    void on_pushButton_SelectFile_clicked();


    void on_pushButton_Connect_clicked();

    void on_pushButton_SendFile_clicked();

private:
    Ui::MainWindow *ui;

    // Variable (socket) to hold the client connection data
    QTcpSocket tcpSocket;

    // Variable (listClientes) to hold the client that are connect on server
    QList<QString> listaClientes;
};

