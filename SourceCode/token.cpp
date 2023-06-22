#include "token.h"

Token::Token(){

}

Token::Token(TokenType tokentype, TokenSubtype tokensubtype, unsigned int line, unsigned int column){
    tk_type = tokentype;
    tk_subtype = tokensubtype;
    tk_line = line;
    tk_column = column;
}

Token::Token(TokenType tokentype, TokenSubtype tokensubtype, QString hashkey, unsigned int line, unsigned int column){
    tk_type = tokentype;
    tk_subtype = tokensubtype;
    tk_hashkey = hashkey;
    tk_line = line;
    tk_column = column;
}

bool Token::IsNonTerminal(){
    if(tk_type == TokenType::nonterminal)
        return true;
    return false;
}

QString Token::GetTokenString(Token::TokenType tk){

    switch(tk){
    case Token::TokenType::unidentified:
        return "unidentified";
        break;
    case Token::TokenType::mainfunction:
        return "mainfunction";
        break;
    case Token::TokenType::keyword:
        return "keyword";
        break;
    case Token::TokenType::identifier:
        return "identifier";
        break;
    case Token::TokenType::constant:
        return "constant";
        break;
    case Token::TokenType::operation:
        return "operation";
        break;
    case Token::TokenType::begincode:
        return "begincode";
        break;
    case Token::TokenType::endcode:
        return "endcode";
        break;
    case Token::TokenType::beginargument:
        return "beginargument";
        break;
    case Token::TokenType::endargument:
        return "endargument";
        break;
    case Token::TokenType::eol:
        return "eol";
        break;
    case Token::TokenType::separator:
        return "separator";
        break;
    case Token::TokenType::nonterminal:
        return "nonterminal";
        break;
    default:
        break;
    }

    return QString();
}

QString Token::GetSubTokenString(TokenSubtype tk){

    switch(tk){
    case TokenSubtype::unidentified:
        return "unidentified";
        break;
    case TokenSubtype::intsky:
        return "intsky";
        break;
    case TokenSubtype::charovsky:
        return "charovsky";
        break;
    case TokenSubtype::floatsky:
        return "floatsky";
        break;
    case TokenSubtype::bolichisky:
        return "bolichisky";
        break;
    case TokenSubtype::chernobyl:
        return "chernobyl";
        break;
    case TokenSubtype::palavrovka:
        return "palavrovka";
        break;
    case TokenSubtype::forevisky:
        return "forevisky";
        break;
    case TokenSubtype::ikov:
        return "ikov";
        break;
    case TokenSubtype::kalashn:
        return "kalashn";
        break;
    case TokenSubtype::niet:
        return "niet";
        break;
    case TokenSubtype::yebat:
        return "yebat";
        break;
    case TokenSubtype::strongon:
        return "strongon";
        break;
    case TokenSubtype::strongonoff:
        return "strongonoff";
        break;
    case TokenSubtype::moscow:
        return "moscow";
        break;
    case TokenSubtype::tovarish:
        return "tovarish";
        break;
    case TokenSubtype::plus:
        return "plus";
        break;
    case TokenSubtype::minus:
        return "minus";
        break;
    case TokenSubtype::times:
        return "times";
        break;
    case TokenSubtype::division:
        return "division";
        break;
    case TokenSubtype::pow:
        return "pow";
        break;
    case TokenSubtype::attribution:
        return "attribution";
        break;
    case TokenSubtype::equalequal:
        return "equalequal";
        break;
    case TokenSubtype::notequal:
        return "notequal";
        break;
    case TokenSubtype::bigger:
        return "bigger";
        break;
    case TokenSubtype::smaller:
        return "smaller";
        break;
    case TokenSubtype::biggerequal:
        return "biggerequal";
        break;
    case TokenSubtype::smallerequal:
        return "smallerequal";
        break;
    case TokenSubtype::and_op:
        return "and_op";
        break;
    case TokenSubtype::or_op:
        return "or_op";
        break;
    case TokenSubtype::plusplus:
        return "plusplus";
        break;
    case TokenSubtype::minusminus:
        return "minusminus";
        break;
    case TokenSubtype::nont_program:
        return "program";
        break;
    case TokenSubtype::nont_beforemain:
        return "beforemain";
        break;
    case TokenSubtype::nont_aftermain:
        return "aftermain";
        break;
    case TokenSubtype::nont_mainfunction:
        return "mainfuction";
        break;
    case TokenSubtype::nont_arguments:
        return "arguments";
        break;
    case TokenSubtype::nont_arglist:
        return "arg_list";
        break;
    case TokenSubtype::nont_more_arguments:
        return "more_arguments";
        break;
    case TokenSubtype::nont_code_block:
        return "code_block";
        break;
    case TokenSubtype::nont_code_block_return:
        return "code_block_return";
        break;
    case TokenSubtype::nont_code:
        return "code";
        break;
    case TokenSubtype::nont_return_statement:
        return "return_statement";
        break;
    case TokenSubtype::nont_var_declaration:
        return "var_declaration";
        break;
    case TokenSubtype::nont_more_declaration:
        return "more_declaration";
        break;
    case TokenSubtype::nont_loop_block:
        return "loop_block";
        break;
    case TokenSubtype::nont_ifelsestatement:
        return "ifelsestatement";
        break;
    case TokenSubtype::nont_elsestatement:
        return "elsestatement";
        break;
    case TokenSubtype::nont_more_else:
        return "more_else";
        break;
    case TokenSubtype::nont_attribution:
        return "attribution";
        break;
    case TokenSubtype::nont_value:
        return "value";
        break;
    case TokenSubtype::nont_operation:
        return "operation";
        break;
    case TokenSubtype::nont_number:
        return "number";
        break;
    case TokenSubtype::nont_functioncall:
        return "functioncall";
        break;
    case TokenSubtype::nont_function_definition:
        return "function_definition";
        break;
    case TokenSubtype::nont_function_return:
        return "function_return";
        break;
    case TokenSubtype::nont_function_void:
        return "function_void";
        break;
    default:
        break;
    }

    return QString();
}

//-----------------------------------
//--------------Getters--------------
//-----------------------------------
Token::TokenType Token::GetTokenType(){return tk_type;}

Token::TokenSubtype Token::GetTokenSubtype(){return tk_subtype;}

QString Token::GetHashKey(){return tk_hashkey;}

unsigned int Token::GetLine(){return tk_line;}

unsigned int Token::GetColumn(){return tk_column;}


//-----------------------------------
//--------------Setters--------------
//-----------------------------------
void Token::SetTokenType(TokenType tokentype){tk_type = tokentype;}

void Token::SetTokenSubtype(TokenSubtype tokensubtype){tk_subtype = tokensubtype;}

void Token::SetHashKey(QString hashkey){tk_hashkey = hashkey;}

void Token::SetLine(unsigned int line){tk_line = line;}

void Token::SetColumn(unsigned int column){tk_column = column;}
