
#include "token.h"

Token::Token(){

}

Token::Token(TokenType tokentype, TokenSubtype tokensubtype, unsigned int line, unsigned int column){
    tk_type = tokentype;
    tk_subtype = tokensubtype;
    tk_line = line;
    tk_column = column;
}

Token::Token(TokenType tokentype, QMap<QString,QString>::iterator hashposition, unsigned int line, unsigned int column){
    tk_type = tokentype;
    tk_position = hashposition;
    tk_line = line;
    tk_column = column;
}

//-----------------------------------
//--------------Getters--------------
//-----------------------------------
Token::TokenType Token::GetTokenType(){return tk_type;}

Token::TokenSubtype Token::GetTokenSubtype(){return tk_subtype;}

QMap<QString,QString>::iterator Token::GetPosition(){return tk_position;}

unsigned int Token::GetLine(){return tk_line;}

unsigned int Token::GetColumn(){return tk_column;}


//-----------------------------------
//--------------Setters--------------
//-----------------------------------
void Token::SetTokenType(TokenType tokentype){tk_type = tokentype;}

void Token::SetTokenSubtype(TokenSubtype tokensubtype){tk_subtype = tokensubtype;}

void Token::SetPosition(QMap<QString,QString>::iterator position){tk_position = position;}

void Token::SetLine(unsigned int line){tk_line = line;}

void Token::SetColumn(unsigned int column){tk_column = column;}
