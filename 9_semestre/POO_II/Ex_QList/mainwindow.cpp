#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pessoa.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i = pessoasList.begin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pessoa pessoa = pessoa();

    pessoa.setNome(ui->lineEditNome->text());
    pessoa.setCpf(ui->lineEditCPF->text());
    pessoa.setEndereco(ui->lineEditEndereco->text());

    pessoasList.append(pessoa);
}

void MainWindow::on_pushButton_3_clicked()
{
    i++;

    ui->lineEditID->setText((*i).getNome());
}

void MainWindow::on_pushButton_5_clicked()
{
    i--;

    ui->lineEditID->setText((*i).getNome());
}
