#include "livro.h"

livro::livro()
{

}

QString livro::getNome() const
{
    return nome;
}

void livro::setNome(const QString &value)
{
    nome = value;
}

QString livro::getAutor() const
{
    return Autor;
}

void livro::setAutor(const QString &value)
{
    Autor = value;
}

QString livro::getAno() const
{
    return Ano;
}

void livro::setAno(const QString &value)
{
    Ano = value;
}
