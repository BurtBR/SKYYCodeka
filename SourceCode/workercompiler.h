#ifndef WORKERCOMPILER_H
#define WORKERCOMPILER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMultiHash>
#include <QQueue>
#include <QStack>
#include "automatons.h"
#include "syntaxtree.h"

//TEMPORARIO
#include <QThread>
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
    QMultiHash<QString,QString> hashtable;
    QQueue<Token> tokenlist, undefinedtokens;
    SyntaxTree syntaxtree;


    //Private Methods
    bool LexicalAnalysis(QString &code, int &linenumber, QString &invalidchar);
    bool SyntacticAnalysis();
    void Tokenize(QString word, int linenumber, int columnnumber);
    void InsertTokenToHash(Token tk, QString hashkey, const QString &value);
    QString GetDataFromString(const QString &strdata, Token::TokenDataType datatype);
    void SetDataToString(QString &strdata, Token::TokenDataType datatype, const QString &value);

    //TEMPORARIO
    void PrintTokensToFile(QString filename);

public:
    WorkerCompiler(QObject *parent = nullptr);
    ~WorkerCompiler();

public slots:
    void Compile(QString text);

signals:
    void Error(int type, QString message = QString(), int errorline = -1);
    void Done(int type, QString message = QString());
    void DisplayInfo(QString message, int messagetype = 1);
};

#endif // WORKERCOMPILER_H
