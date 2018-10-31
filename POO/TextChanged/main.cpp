#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget janela;

        QLineEdit *campoTexto = new QLineEdit;
        QLabel *linhas = new QLabel("Digite o texto");

        QVBoxLayout *layout = new QVBoxLayout(&janela);



        QPushButton *button = new QPushButton("Botao fechar", &janela);
        layout->addWidget(campoTexto);
        layout->addWidget(linhas);
        layout->addWidget(button);

        QObject::connect(campoTexto, SIGNAL(textChanged(QString)), linhas, SLOT(setText(QString)));

        QObject::connect(button, SIGNAL(clicked()), &janela, SLOT(close()));
        janela.show();




    return app.exec();
}
