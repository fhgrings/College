#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    QList<pessoa*> cadastros;

private slots:
    void on_pushButton_Cadastrar_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
