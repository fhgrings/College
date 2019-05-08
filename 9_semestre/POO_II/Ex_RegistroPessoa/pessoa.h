#ifndef PESSOA_H
#define PESSOA_H

#include <QObject>

class Pessoa
{
public:
    Pessoa();

    QString getEndereco() const;
    void setEndereco(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

    int getCPF() const;
    void setCPF(int value);

private:
    int CPF;
    QString nome;
    QString endereco;
};

#endif // PESSOA_H
