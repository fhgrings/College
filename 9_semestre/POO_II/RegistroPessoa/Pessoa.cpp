#include "Pessoa.h"

Pessoa::Pessoa()
{

}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &value)
{
    endereco = value;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

int Pessoa::getCPF() const
{
    return CPF;
}

void Pessoa::setCPF(int value)
{
    CPF = value;
}
