#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QMultiMap>

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
        michwhail,
        forevisky,
        ikov,
        kalashn,
        niet,
        yebat,
        strongon,
        strongonoff,
        plus,
        minus,
        times,
        division,
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

private:
    //Private Attributes
    TokenType tk_type = TokenType::unidentified;
    TokenSubtype tk_subtype = TokenSubtype::unidentified;
    QMultiMap<QString,QString>::iterator tk_position;
    unsigned int tk_line = -1;
    unsigned int tk_column = -1;

public:
    Token();
    Token(TokenType tokentype, TokenSubtype tokensubtype, unsigned int line, unsigned int column);
    Token(TokenType tokentype, QMultiMap<QString,QString>::iterator hashposition, unsigned int line, unsigned int column);

    static QString GetTokenString(TokenType tk);
    static QString GetSubTokenString(TokenSubtype tk);

    //Getters
    TokenType GetTokenType();
    TokenSubtype GetTokenSubtype();
    QMultiMap<QString,QString>::iterator GetPosition();
    unsigned int GetLine();
    unsigned int GetColumn();

    //Setters
    void SetTokenType(TokenType tokentype);
    void SetTokenSubtype(TokenSubtype tokensubtype);
    void SetPosition(QMultiMap<QString,QString>::iterator position);
    void SetLine(unsigned int line);
    void SetColumn(unsigned int column);
};

#endif // TOKEN_H
