#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>

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
    void on_pushButton_adicionar_clicked();

    void on_pushButton_remover_clicked();


private:
    Ui::MainWindow *ui;

    QQueue<QString> listaItens;

};

#endif // MAINWINDOW_H
