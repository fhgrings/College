#include "pessoa.h"

Pessoa::Pessoa(QString nome, QString endereco, QString CPF, QDate nascimento)
{
    setEndereco(this->endereco);
    setNascimento(this->nascimento);
    setNome(this->nome);
    setCPF(this->CPF);
}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &value)
{
    endereco = value;
}

QDate Pessoa::getNascimento() const
{
    return nascimento;
}

void Pessoa::setNascimento(const QDate &value)
{
    nascimento = value;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

QString Pessoa::getCPF() const
{
    return CPF;
}

void Pessoa::setCPF(const QString &value)
{
    CPF = value;
}
