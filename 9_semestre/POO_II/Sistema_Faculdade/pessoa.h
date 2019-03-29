#ifndef PESSOA_H
#define PESSOA_H
#include <QString>
#include <QDate>

class Pessoa
{
public:
    Pessoa();
    Pessoa(QString nome, QString endereco, QString CPF, QDate nascimento);


    QString getEndereco() const;
    void setEndereco(const QString &value);

    QDate getNascimento() const;
    void setNascimento(const QDate &value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getCPF() const;
    void setCPF(const QString &value);

protected:
    QString nome;
    QDate nascimento;
    QString endereco;
    QString CPF;


};

#endif // PESSOA_H
