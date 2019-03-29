#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "pessoa.h"


class Professor : public Pessoa
{
public:
    Professor();
    Professor(int id, QString cargo, QString nome, QString CPF, QString enderenco, QDate nascimento);

    QString getCargo() const;
    void setCargo(const QString &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString cargo;

};

#endif // PROFESSOR_H
