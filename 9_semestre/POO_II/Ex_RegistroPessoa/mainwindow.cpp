#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Pessoa.h"

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

void MainWindow::on_pushButton_Cadastrar_clicked()
{
    Pessoa pessoa();

    pessoa.setCPF(ui->lineEdit_CPF->text());
    pessoa.setEndereco(ui->lineEdit_End->text());
    pessoa.setNome(ui->lineEdit_Nome->text());

    cadastros.append(pessoa);
}



