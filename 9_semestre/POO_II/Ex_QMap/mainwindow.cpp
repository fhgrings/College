#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livro.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    livro livro = livro();

    livro.setAno(ui->lineEditAno->text());
    livro.setNome(ui->lineEditNome->text());
    livro.setAutor(ui->lineEditAutor->text());

    int number;
    int randomValue = qrand() % number;

    livrosMaps.insert(randomValue,livro);
}

void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->lineEditID->text();

    livrosMaps.remove(key);
}
