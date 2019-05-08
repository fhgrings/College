#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f = new QFile(); // aloca um novo objeto do tipo QFile e atribui ao ponteiro f

    ts = new  QTextStream(f);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f;
}

void MainWindow::on_pushButton_clicked()
{
    f->setFileName(ui->lineEdit->text());// Associa o objeto f a um arquivo chamado com nome digitado no campo

    if( !f->exists() ) {// Arquivo não existe
        ui->textEdit->setText("Arquivo não Existe.");
        return;
    }

    if( !f->open(QIODevice::ReadWrite | QIODevice::Text) ){ // Se existir abre
         ui->textEdit->setText( "Sem permissão para Abrir o arquivo.");
         return;
    }

    f->read();
    ui->textEdit->setText( "Arquivo Aberto com Sucesso.");
    return;
}

void MainWindow::on_pushButton_4_clicked()
{

    if( !f->isOpen()){ // Se o arquivo ainda não foi aberto
         ui->textEdit->setText( "Nenhum arquivo foi aberto.");
         return;
    }

    ui->textEdit->setText(f->readLine());
    return;
}

void MainWindow::on_pushButton_3_clicked()
{
    if( !f->isOpen()){ // Se o arquivo ainda não foi aberto
         ui->textEdit->setText( "Nenhum arquivo foi aberto.");
         return;
    }

    f->seek(ui->lineEdit_3->text().toDouble()); //ajusta a posição de leitura
    ui->textEdit->setText(f->read(ui->lineEdit_4->text().toDouble())); // o parametro passado para o metodo read indica quantos bytes ler
    return;
}

void MainWindow::on_pushButton_2_clicked()
{
    if( !f->isOpen()){ // Se o arquivo ainda não foi aberto
         ui->textEdit->setText( "Nenhum arquivo foi aberto.");
         return;
    }

    f->seek(ui->lineEdit_2->text().toDouble()); //ajusta a posição de leitura
    ui->textEdit->setText(f->readLine());
    return;
}

void MainWindow::on_pushButton_5_clicked()
{
    f->close();
    ui->textEdit->setText( "Arquivo fechado.");
    return;
}

void MainWindow::on_pushButton_6_clicked()
{

    if( !f->isOpen()){ // Se o arquivo ainda não foi aberto
         ui->textEdit->setText( "Nenhum arquivo foi aberto.");
         return;
    }
    // ts é o TextStream declarado no .h e associado ao arquivo f no contrutor da classe
    ui->textEdit->setText(ts->readLine());
    return;


}

void MainWindow::salvarArquivo(QString nome, QString conteudo)
{
    QFile f(nome);

    if(f.exists()) {// Se arquivo existe
        QMessageBox::critical(this, "Error", "Um arquivo com este nome já existe");
        return;
    }

    if ( f.open(QIODevice::ReadWrite) )
    {
        QTextStream stream(&f);
        stream << conteudo << endl;
        f.flush();
        f.close();

    }else{
        QMessageBox::critical(this,"Error", "Algo errado ao criar arquivo");
    }
}

void MainWindow::on_btn_Salvar_clicked()
{
    if( !file->isOpen())// Se o arquivo ainda não foi aberto
    {
        ui->textEdit_arquivo->setText("Nenhum arquivo foi aberto.");
        return;
    }
    QString strVetor(ui->textEdit_vetor->toPlainText() + ",");

    QByteArray chrVetor;

    QString Byte,i;
    int pos = 0;
    foreach(i,strVetor)
    {
        if(i!=",")
            Byte+=i;
        else
        {
            if(pos<10)
            {
                if(ValidateByte(Byte))
                {
                        chrVetor.insert(pos, Byte.toLocal8Bit());
                }
                else
                {
                    ui->textEdit_arquivo->setText("Byte Não é valido, digite apenas caracteres da tabela ascii separados por virgulas");
                    return;
                }
            }
            else
                break;
            Byte = "";
            pos++;
        }
    }
    QDataStream objBin(file);

    QByteArray::iterator it;
    for ( it = chrVetor.begin();it!=chrVetor.end();it++)
    {
        objBin.writeRawData(it,1);
        objBin.writeRawData("\n",1);
    }
    on_btn_Abrir_clicked();//só para atualizar o text com o conteudo do arquivo
}


