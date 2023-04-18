#ifndef WORKERCOMPILER_H
#define WORKERCOMPILER_H

#include <QObject>
#include <QTextStream>
#include <QMultiMap>
#include <QVector>
#include "automatons.h"

//TEMPORARIO
#include <QThread>
#include <QFile>
#include <QDebug>
//TEMPORARIO

class WorkerCompiler : public QObject{

    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT

private:
    //Private Attributes
    QMultiMap<QString,QString> hashtable;
    QVector<Token> tokenlist, undefinedtokens;

    //Private Methods
    bool LexicalAnalysis(QString &code, int &linenumber, QString &invalidchar);
    bool SyntacticAnalysis(QString &code);
    void Tokenize(QString word, int linenumber, int columnnumber);

    //TEMPORARIO
    void PrintTokensToFile(QString filename);

public:
    WorkerCompiler(QObject *parent = nullptr);

public slots:
    void Compile(QString text);

signals:
    void Error(int type, QString message = QString(), int errorline = -1);
    void Done(int type, QString message = QString());
    void DisplayInfo(QString message, int messagetype = 1);
};

#endif // WORKERCOMPILER_H
