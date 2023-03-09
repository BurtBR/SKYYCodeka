#include "workerfilehandler.h"

WorkerFileHandler::WorkerFileHandler(QObject *parent) : QObject(parent){

}

void WorkerFileHandler::LoadFile(QString filepath){

    QFile fp(filepath);
    QTextStream in(&fp);

    if(!fp.open(QIODevice::ReadOnly | QIODevice::Text)){
        emit Error(0, "Falha ao abrir o arquivo em thread");
        return;
    }

    while(!in.atEnd()){
        emit TextLoaded(in.read(200));
    }

    fp.close();

    emit Done(0, QString());

}

void WorkerFileHandler::SaveFile(QString text, QString filepath){

    QFile fp(filepath);
    QTextStream out(&fp);

    if(!fp.open(QIODevice::WriteOnly | QIODevice::Text)){
        emit Error(1, "Falha ao abrir o arquivo em thread");
        return;
    }

    out << text;

    fp.close();

    emit Done(1, QString());
}
