#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_buttonBuscar_clicked()
{
    palavraBuscada = ui->textoBusca->text();
    texto = ui->textEdit->toPlainText();

    if(ui->checkBox->checkState()){
        texto.replace(palavraBuscada, QString("<font color=\"#FF0000\">" + palavraBuscada + "</font>"), Qt::CaseSensitive);
    } else {

        texto.replace(palavraBuscada, QString("<font color=\"#FF0000\">" + palavraBuscada.toUpper() + "</font>"), Qt::CaseInsensitive);
    }
    ui->textEdit->setText(texto);

    int resultadoBusca = texto.count(palavraBuscada);

    ui->textoResultado->setText(QString("%1").arg(resultadoBusca));
}
