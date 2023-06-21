#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QMultiMap>

//TEMPORARIO
#include <QDebug>
//TEMPORARIO

class Token{

public:
    enum class TokenType{
        unidentified,   //0
        mainfunction,   //1
        keyword,        //2
        identifier,     //3
        constant,       //4
        operation,      //5
        begincode,      //6
        endcode,        //7
        beginargument,  //8
        endargument,    //9
        eol,            //10
        separator       //11
    };

    enum class TokenSubtype{
        unidentified,
        intsky,
        charovsky,
        floatsky,
        bolichisky,
        chernobyl,
        palavrovka,
        forevisky,
        ikov,
        kalashn,
        niet,
        yebat,
        strongon,
        strongonoff,
        moscow,
        tovarish,
        plus,
        minus,
        times,
        division,
        pow,
        attribution,
        equalequal,
        notequal,
        bigger,
        smaller,
        biggerequal,
        smallerequal,
        and_op,
        or_op,
        plusplus,
        minusminus
    };

    enum class TokenDataType{
        key,
        var_type,
        scope
    };

private:

    //Private Attributes
    TokenType tk_type = TokenType::unidentified;
    TokenSubtype tk_subtype = TokenSubtype::unidentified;
    QString tk_data;
    unsigned int tk_line = -1;
    unsigned int tk_column = -1;

public:
    Token();
    Token(TokenType tokentype, TokenSubtype tokensubtype, unsigned int line, unsigned int column);
    Token(TokenType tokentype, QString hashkey, unsigned int line, unsigned int column);

    static QString GetTokenString(TokenType tk);
    static QString GetSubTokenString(TokenSubtype tk);

    //Getters
    TokenType GetTokenType();
    TokenSubtype GetTokenSubtype();
    QString GetData();
    unsigned int GetLine();
    unsigned int GetColumn();

    //Setters
    void SetTokenType(TokenType tokentype);
    void SetTokenSubtype(TokenSubtype tokensubtype);
    void SetData(QString data);
    void SetLine(unsigned int line);
    void SetColumn(unsigned int column);
};

#endif // TOKEN_H
