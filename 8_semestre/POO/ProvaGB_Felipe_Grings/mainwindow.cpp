#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQueue>

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

void MainWindow::on_pushButton_adicionar_clicked()
{

    listaItens.enqueue(ui->lineEdit->text());
    ui->textEdit_Mostrar->append(ui->lineEdit->text());

}

void MainWindow::on_pushButton_remover_clicked()
{
    if(!listaItens.isEmpty())
        listaItens.dequeue();



    ui->textEdit_Mostrar->setFocus();
    QTextCursor storeCursorPos = ui->textEdit_Mostrar->textCursor();
    ui->textEdit_Mostrar->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
    ui->textEdit_Mostrar->moveCursor(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
    ui->textEdit_Mostrar->moveCursor(QTextCursor::Start, QTextCursor::KeepAnchor);

    ui->textEdit_Mostrar->textCursor().removeSelectedText();
    ui->textEdit_Mostrar->textCursor().deleteChar();

}
