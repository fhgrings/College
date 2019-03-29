#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>




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

   QFile file(ui->lineEdit->text());// Associa o objeto f a um arquivo chamado com nome digitado no campo

   if( !file.exists() ) {// Arquivo não existe
       ui->textEdit->setText("Arquivo não Existe.");
       return;
   }

   if( !file.open(QIODevice::ReadWrite | QIODevice::Text) ){ // Se existir abre
        ui->textEdit->setText( "Sem permissão para Abrir o arquivo.");
        return;
   }

   // Arquivo foi aberto. Agora necessita fechá-lo
   ui->textEdit->setText(file.readAll());
   file.close();
   return;


}

void MainWindow::on_salvar_pushButton_clicked()
{
    QFile f( ui->lineEdit->text() );
    if( !f.open(QIODevice::WriteOnly | QIODevice::Append ) ) {
    return;
    }
    QTextStream ts(&f);
    ts << "This is a test-run.";
    f.close();
    return;
}
