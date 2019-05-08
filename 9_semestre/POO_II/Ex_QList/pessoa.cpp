#include "pessoa.h"

pessoa::pessoa()
{

}

QString pessoa::getEndereco() const
{
    return endereco;
}

void pessoa::setEndereco(const QString &value)
{
    endereco = value;
}

QString pessoa::getCpf() const
{
    return cpf;
}

void pessoa::setCpf(const QString &value)
{
    cpf = value;
}

QString pessoa::getNome() const
{
    return nome;
}

void pessoa::setNome(const QString &value)
{
    nome = value;
}
