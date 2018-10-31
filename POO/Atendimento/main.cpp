#include "mainwindow.h"
#include <QApplication>
#include <QQueue>
#include "ticket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    QQueue<Ticket> queue;


    Ticket* ticket = new Ticket();
    queue.enqueue(ticket);
    queue.enqueue(new Ticket(2));


    while (!queue.isEmpty()){

    }
    return a.exec();
}
