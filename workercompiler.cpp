#include "workercompiler.h"

WorkerCompiler::WorkerCompiler(QObject *parent) : QObject{parent}{

}

bool WorkerCompiler::IsValidChar(const QChar &c){

    switch(c.toLower().toLatin1()){
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;

    case '{':
    case '}':
    case '(':
    case ')':
    case '\"':
    case '\'':
    case ';':
    case ':':
    case ',':
    case '.':
    case '&':
    case '!':
    case '|':
    case '+':
    case '-':
    case '*':
    case '/':
        return true;

    case ' ':
    case '\t':
    case '\n':
        return true;

    default:
        break;
    }

    return false;
}

//---------------------------SLOTS---------------------------

void WorkerCompiler::Compile(QString text){

    //TEMPORARIO
    if(!text.size())
        QThread::sleep(5);
    //TEMPORARIO

    int linecounter = 1;

    for(int i=0; i<text.size() ;i++){

        if(!IsValidChar(text[i])){
            emit Error(2, "Caractere desonhecido na linha " + QString::number(linecounter) + ": " + text[i], linecounter);
            return;
        }

        if(text[i] == '\n')
            linecounter++;

    }

    emit Done(2);
}

//---------------------------SLOTS---------------------------
