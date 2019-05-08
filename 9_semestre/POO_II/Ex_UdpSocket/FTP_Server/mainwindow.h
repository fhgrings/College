#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

#include <QMessageBox>
<<<<<<< HEAD
=======
#include "graphicthread.h"
#include <QThread>
>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787

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
    // Called automatically when "startServer" button is clicked
    void on_startServer_clicked();

    // Called automatically when a client attempts to connect
    void acceptTheConnection();

    // Called automatically when data sent by a client is fully available to the server
    void respondToConnection();

    // Called automatically when client has closed the connection
    void connectionAboutToClose();

<<<<<<< HEAD
=======
    void ReplotGrafico();

>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
private:
    int portValue = 8080;
    Ui::MainWindow *ui;
    bool firstTime = true;

    int counter = 0;

<<<<<<< HEAD
=======
    GraphicThread *objGrafico;

    QThread objThread;

>>>>>>> f8144f718ff3c88431105d271ab9dcd3d100c787
    // Variable(socket) to store listening tcpserver
    QTcpServer tcpServer;

    // Variable(socket) to store newly established connection with the client
    QMap<int, QTcpSocket*> socketUsersMap;
};

#endif // MAINWINDOW_H
