#ifndef LIVRO_H
#define LIVRO_H

#include "QString"
class livro
{
public:
    livro();

    QString getNome() const;
    void setNome(const QString &value);

    QString getAutor() const;
    void setAutor(const QString &value);

    QString getAno() const;
    void setAno(const QString &value);

private:
    QString nome;
    QString Autor;
    QString Ano;
};

#endif // LIVRO_H
