#ifndef PESSOA_H
#define PESSOA_H

#include "QString"

class pessoa
{
public:
    pessoa();
    QString getEndereco() const;
    void setEndereco(const QString &value);

    QString getCpf() const;
    void setCpf(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

private:
    QString nome;
    QString cpf;
    QString endereco;
};

#endif // PESSOA_H
