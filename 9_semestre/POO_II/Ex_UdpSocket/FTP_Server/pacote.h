#ifndef PACOTE_H
#define PACOTE_H

#pragma once
#include <QString>

class pacote
{
public:
    // construtores e destrutores
    pacote();
    ~pacote();

    void setNomeArquivo(QString nomeArquivo);
    QString getNomeArquivo();

    void setConteudoArquivo(QString conteudoArquivo);
    QString getConteudoArquivo();

    void setRemetente(QString remetente);
    QString getRemetente();

    void setDestinatario(QString destinatario);
    QString getDestinatario();

    bool empacotarMensagem(QString* mensagem);
    bool desempacotarMensagem(QString mensagem);

private:
    QString nomeArquivo;
    QString conteudoArquivo;
    QString remetente;
    QString destinatario;
};

#endif // PACOTE_H
