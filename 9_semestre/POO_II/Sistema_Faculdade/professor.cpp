#include "professor.h"
#include "pessoa.h"

Professor::Professor(int id, QString cargo, QString nome, QString CPF, QString enderenco, QDate nascimento)
    :Pessoa(nome, CPF, endereco, nascimento)
{
    setCargo(this->cargo);
    setId(this->id);
}

QString Professor::getCargo() const
{
    return cargo;
}

void Professor::setCargo(const QString &value)
{
    cargo = value;
}

int Professor::getId() const
{
    return id;
}

void Professor::setId(int value)
{
    id = value;
}
