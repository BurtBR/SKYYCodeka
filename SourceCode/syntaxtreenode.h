#ifndef SYNTAXTREENODE_H
#define SYNTAXTREENODE_H

#include <QVector>
#include <QQueue>
#include "token.h"

class SyntaxTreeNode{
private:
    SyntaxTreeNode *parent = nullptr;
    QVector<SyntaxTreeNode> childs;
    Token nodetoken;
    int lastchildindex = -1;

    void DeleteNode(SyntaxTreeNode *node);

public:
    SyntaxTreeNode();
    SyntaxTreeNode(SyntaxTreeNode *nodeparent, Token tk);
    ~SyntaxTreeNode();

    SyntaxTreeNode ChildAt(int index);
    void AppendToken(const Token &tk);
    void DeleteTokenAt(int index);
    SyntaxTreeNode *DeleteSelf();
    bool HasChilds();
    SyntaxTreeNode *Next();
    SyntaxTreeNode *Next(int &level);
    SyntaxTreeNode *NextNonTerminal();
    bool Derivation(QQueue<Token> &streamtoken, QString &message);
    void ResetIndex();

    //Getters
    Token GetNodeToken();
    SyntaxTreeNode *GetChild(int index);
    QString GetTokenHashKey();

    //Setters
    void SetParent(SyntaxTreeNode *node);
    void SetNodeToken(const Token &tk);
    void SetTokenType(Token::TokenType type);
    void SetTokenSubtype(Token::TokenSubtype type);
    void SetTokenHashKey(QString hashkey);
};

#endif // SYNTAXTREENODE_H
