#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ticket.h"
#include "QQueue"

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
    void on_normalPushButton_clicked();

    void on_prioritariaPushButton_clicked();

    void on_atenderPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QQueue<Ticket> normalQueue;
    QQueue<Ticket> preferencialQueue;
    int filaNormal;
    int filaPreferencial;
    int escolhaFila;

};

#endif // MAINWINDOW_H
