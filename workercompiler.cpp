#include "workercompiler.h"

WorkerCompiler::WorkerCompiler(QObject *parent) : QObject{parent}{

}

//---------------------------SLOTS---------------------------

void WorkerCompiler::Compile(QString text){

    //TEMPORARIO
    if(!text.size())
        QThread::sleep(5);
    //TEMPORARIO

    int linecounter = 0;

    for(int i=0; i<text.size() ;i++){

        switch(text[i].toLatin1()){
        case 'a':
            break;
        case '\n':
            linecounter++;
            break;
        default:
            emit Error(2, "Caractere desonhecido na linha " + QString::number(linecounter) + ": " + text[i], linecounter);
            return;
        }

    }

    emit Done(2);
}

//---------------------------SLOTS---------------------------
