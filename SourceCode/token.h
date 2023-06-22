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
        separator,      //11
        nonterminal,
        endprogram
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
        minusminus,
        nont_program,
        nont_beforemain,
        nont_aftermain,
        nont_mainfunction,
        nont_arguments,
        nont_arglist,
        nont_more_arguments,
        nont_code_block,
        nont_code_block_return,
        nont_code,
        nont_return_statement,
        nont_var_declaration,
        nont_more_declaration,
        nont_loop_block,
        nont_ifelsestatement,
        nont_elsestatement,
        nont_more_else,
        nont_attribution,
        nont_value,
        nont_operation,
        nont_functioncall,
        nont_function_definition,
        nont_function_return,
        nont_return_type,
        nont_function_void,
    };

    enum class TokenDataType{
        value,
        tk_type,
        tk_subtype,
        scope
    };

private:

    //Private Attributes
    TokenType tk_type = TokenType::unidentified;
    TokenSubtype tk_subtype = TokenSubtype::unidentified;
    QString tk_hashkey;
    unsigned int tk_line = -1;
    unsigned int tk_column = -1;

public:
    Token();
    Token(TokenType tokentype, TokenSubtype tokensubtype, unsigned int line, unsigned int column);
    Token(TokenType tokentype, TokenSubtype tokensubtype, QString hashkey, unsigned int line, unsigned int column);
    bool IsNonTerminal();

    static QString GetTokenString(TokenType tk);
    static QString GetSubTokenString(TokenSubtype tk);

    //Getters
    TokenType GetTokenType();
    TokenSubtype GetTokenSubtype();
    QString GetHashKey();
    unsigned int GetLine();
    unsigned int GetColumn();

    //Setters
    void SetTokenType(TokenType tokentype);
    void SetTokenSubtype(TokenSubtype tokensubtype);
    void SetHashKey(QString hashkey);
    void SetLine(unsigned int line);
    void SetColumn(unsigned int column);
};

#endif // TOKEN_H
