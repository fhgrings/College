#include "pacote.h"
#include <QStringList>

#define REMETENTE_TAG           "<remetente>"
#define DESTINATARIO_TAG        "<destinatario>"
#define CONTEUDO_TAG            "<conteudoArquivo>"
#define ARQUIVO_TAG             "<nomeArquivo>"
#define FIELD_END_TAG           "<fieldendtag>"
/*
 * formato utilizado para mensagem:

<remetente>"nome do remetente"<fieldendtag>
<destinatario>"nome do destinatario"<fieldendtag>
<nomeArquivo>"nome do arquivo"<fieldendtag>
<conteudoArquivo>"conteudo do arquivo"<fieldendtag>

*/

pacote::pacote()
{
    setNomeArquivo(QString());
    setConteudoArquivo(QString());
    setRemetente(QString());
    setDestinatario(QString());
}

pacote::~pacote()
{
    // do nothing
}

void pacote::setNomeArquivo(QString nomeArquivo) {
    this->nomeArquivo = nomeArquivo;
}

QString pacote::getNomeArquivo() {
    return this->nomeArquivo;
}

void pacote::setConteudoArquivo(QString conteudoArquivo) {
    this->conteudoArquivo = conteudoArquivo;
}

QString pacote::getConteudoArquivo() {
    return this->conteudoArquivo;
}

void pacote::setRemetente(QString remetente) {
    this->remetente = remetente;
}

QString pacote::getRemetente() {
    return this->remetente;
}

void pacote::setDestinatario(QString destinatario) {
    this->destinatario = destinatario;
}

QString pacote::getDestinatario() {
    return this->destinatario;
}

bool pacote::empacotarMensagem(QString* mensagem) {
    if ((this->nomeArquivo.size() > 0) &&
        (this->conteudoArquivo.size() > 0) &&
        (this->remetente.size() > 0) &&
        (this->destinatario.size() > 0)) {

        *mensagem = REMETENTE_TAG + this->getRemetente() + FIELD_END_TAG + DESTINATARIO_TAG + this->getDestinatario() + FIELD_END_TAG + ARQUIVO_TAG + this->getNomeArquivo() + FIELD_END_TAG + CONTEUDO_TAG + this->getConteudoArquivo();
        return true;
    } else {
        return false;
    }
}

bool pacote::desempacotarMensagem(QString mensagem) {
    QStringList fields = mensagem.split(FIELD_END_TAG);
    this->setRemetente(fields.at(0).split(REMETENTE_TAG).at(1));
    this->setDestinatario(fields.at(1).split(DESTINATARIO_TAG).at(1));
    this->setNomeArquivo(fields.at(2).split(ARQUIVO_TAG).at(1));
    this->setConteudoArquivo(fields.at(3).split(CONTEUDO_TAG).at(1));
    return true;
}
