#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRandomY_clicked();

private:
    Ui::MainWindow *ui;
    double dblBtnCounter = 0;
    QVector <double> x,y1,y2;
    int minX = 0 , maxX = 9;
};

#endif // MAINWINDOW_H
