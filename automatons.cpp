#include "automatons.h"

Automatons::Automatons(){

}

void Automatons::StartAutomatons(int &keyoptype){
    datatype = &keyoptype;
    charcounter = 0;
    reservedWords = &Automaton_Reserved_0;
    floatNumber = &Automaton_Float_0;
    integerNumber = &Automaton_Integer_0;
    stringWord = &Automaton_String_0;
    operatorSymbol = &Automaton_Operator_0;
    identifierWord = &Automaton_Identifier_0;
    limiters = &Automaton_Symbol_0;
}

Token::TokenType Automatons::GetToken(QString word, int &keyoptype){
    StartAutomatons(keyoptype);

    for(charcounter=0; charcounter<word.size() ;charcounter++){

        if((this->*stringWord)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*reservedWords)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*floatNumber)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*integerNumber)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*operatorSymbol)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*identifierWord)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

        if((this->*limiters)(word[charcounter]))
            if(charcounter == (word.size()-1))
                return token;

    } // End for

    return Token::TokenType::unidentified;
}

QString Automatons::GetTokenString(Token::TokenType tk){

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
    default:
        return "";
        break;
    }

    return "";
}

bool Automatons::Automaton_FAIL(QChar){
    return false;
}

//--------RESERVED WORD AUTOMATON--------

bool Automatons::Automaton_Reserved_0(QChar c){

    switch(c.toLatin1()){
    case 'b':
        reservedWords = &Automaton_Reserved_bolichisky;
        break;
    case 'c':
        reservedWords = &Automaton_Reserved_ch;
        break;
    case 'f':
        reservedWords = &Automaton_Reserved_f;
        break;
    case 'i':
        reservedWords = &Automaton_Reserved_i;
        break;
    case 'k':
        reservedWords = &Automaton_Reserved_kalashn;
        break;
    case 'm':
        reservedWords = &Automaton_Reserved_m;
        break;
    case 'n':
        reservedWords = &Automaton_Reserved_niet;
        break;
    case 'p':
        reservedWords = &Automaton_Reserved_palavrovka;
        break;
    case 's':
        reservedWords = &Automaton_Reserved_strongon;
        break;
    case 'y':
        reservedWords = &Automaton_Reserved_yebat;
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_bolichisky(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'l')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'i')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'c')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'h')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'i')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 9:
        reservedWords = &Automaton_FAIL;
        if(c == 'y'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::bolichisky;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch(QChar c){
    switch(charcounter){
    case 1:
        if(c != 'h')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c == 'a')
            reservedWords = &Automaton_Reserved_ch_arovsky;
        else if(c == 'e')
            reservedWords = &Automaton_Reserved_ch_ernobyl;
        else
            reservedWords = &Automaton_FAIL;
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch_arovsky(QChar c){

    switch(charcounter){
    case 3:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'v')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        reservedWords = &Automaton_FAIL;
        if(c == 'y'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::charovsky;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch_ernobyl(QChar c){

    switch(charcounter){
    case 3:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'n')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'b')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'y')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        reservedWords = &Automaton_FAIL;
        if(c == 'l'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::chernobyl;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_f(QChar c){

    if(c == 'l')
        reservedWords = &Automaton_Reserved_f_loatsky;
    else if(c == 'o')
        reservedWords = &Automaton_Reserved_f_orevisky;
    else
        reservedWords = &Automaton_FAIL;

    return false;

}

bool Automatons::Automaton_Reserved_f_loatsky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 't')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        reservedWords = &Automaton_FAIL;
        if(c == 'y'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::floatsky;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_f_orevisky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'e')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'v')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'i')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        reservedWords = &Automaton_FAIL;
        if(c == 'y'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::forevisky;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_i(QChar c){
    if(c == 'k')
        reservedWords = &Automaton_Reserved_i_kov;
    else if(c == 'n')
        reservedWords = &Automaton_Reserved_i_ntsky;
    else
        reservedWords = &Automaton_FAIL;

    return false;
}

bool Automatons::Automaton_Reserved_i_kov(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        reservedWords = &Automaton_FAIL;
        if(c == 'v'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::ikov;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_i_ntsky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 't')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        reservedWords = &Automaton_FAIL;
        if(c == 'y'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::intsky;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_kalashn(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'l')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 's')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'h')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        reservedWords = &Automaton_FAIL;
        if(c == 'n'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::kalashn;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_m(QChar c){

    if(c == 'o')
        reservedWords = &Automaton_Reserved_m_otherland;
    else if(c == 'i')
        reservedWords = &Automaton_Reserved_m_ickwhail;
    else
        reservedWords = &Automaton_FAIL;

    return false;
}

bool Automatons::Automaton_Reserved_m_otherland(QChar c){

    switch(charcounter){
    case 2:
        if(c != 't')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'h')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'e')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'l')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        if(c != 'n')
            reservedWords = &Automaton_FAIL;
        break;
    case 9:
        reservedWords = &Automaton_FAIL;
        if(c == 'd'){
            token = Token::TokenType::mainfunction;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_m_ickwhail(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'c')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'w')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'h')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'i')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        reservedWords = &Automaton_FAIL;
        if(c == 'l'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::michwhail;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_niet(QChar c){
    switch(charcounter){
    case 1:
        if(c != 'i')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'e')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c == 't'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::niet;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }
    return false;
}

bool Automatons::Automaton_Reserved_palavrovka(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'l')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'v')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c != 'v')
            reservedWords = &Automaton_FAIL;
        break;
    case 8:
        if(c != 'k')
            reservedWords = &Automaton_FAIL;
        break;
    case 9:
        reservedWords = &Automaton_FAIL;
        if(c == 'a'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::palavrovka;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_strongon(QChar c){

    switch(charcounter){
    case 1:
        if(c != 't')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'r')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        if(c != 'n')
            reservedWords = &Automaton_FAIL;
        break;
    case 5:
        if(c != 'g')
            reservedWords = &Automaton_FAIL;
        break;
    case 6:
        if(c != 'o')
            reservedWords = &Automaton_FAIL;
        break;
    case 7:
        if(c == 'n'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::strongon;
            return true;
        }
        break;
    case 8:
        if(c == 'o')
            reservedWords = &Automaton_Reserved_strongon_off;
        else
            reservedWords = &Automaton_FAIL;
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_strongon_off(QChar c){

    switch(charcounter){
    case 9:
        if(c != 'f')
            reservedWords = &Automaton_FAIL;
        break;
    case 10:
        reservedWords = &Automaton_FAIL;
        if(c == 'f'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::strongonoff;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_yebat(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'e')
            reservedWords = &Automaton_FAIL;
        break;
    case 2:
        if(c != 'b')
            reservedWords = &Automaton_FAIL;
        break;
    case 3:
        if(c != 'a')
            reservedWords = &Automaton_FAIL;
        break;
    case 4:
        reservedWords = &Automaton_FAIL;
        if(c == 't'){
            token = Token::TokenType::keyword;
            *datatype = (int)Token::TokenSubtype::yebat;
            return true;
        }
        break;
    default:
        reservedWords = &Automaton_FAIL;
        break;
    }

    return false;
}
//------END RESERVED WORD AUTOMATON------



//----------IDENTIFIER AUTOMATON---------
bool Automatons::Automaton_Identifier_0(QChar c){

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
        identifierWord = &Automaton_Identifier_1;
        token = Token::TokenType::identifier;
        return true;
        break;
    default:
        identifierWord = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Identifier_1(QChar c){

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
    case '_':
        token = Token::TokenType::identifier;
        return true;
        break;
    default:
        identifierWord = &Automaton_FAIL;
        break;
    }

    return false;
}

//--------END IDENTIFIER AUTOMATON-------



//---------FLOAT NUMBER AUTOMATON--------
bool Automatons::Automaton_Float_0(QChar c){

    if(c >= '0' && c <= '9'){
        floatNumber = &Automaton_Float_Before;
    }else{
        floatNumber = &Automaton_FAIL;
    }

    return false;
}

bool Automatons::Automaton_Float_Before(QChar c){

    if(c == '.'){
        floatNumber = &Automaton_Float_After;
    }else if((c < '0') && (c > '9')){
        floatNumber = &Automaton_FAIL;
    }

    return false;
}

bool Automatons::Automaton_Float_After(QChar c){

    if(c >= '0' && c <= '9'){
        token = Token::TokenType::constant;
        return true;
    }else{
        floatNumber = &Automaton_FAIL;
    }

    return false;
}
//------END FLOAT NUMBER AUTOMATON-------



//--------INTEGER NUMBER AUTOMATON-------

bool Automatons::Automaton_Integer_0(QChar c){
    if((c > '0') && (c <= '9')){
        integerNumber = &Automaton_Integer_1;
        token = Token::TokenType::constant;
        return true;
    }else if(c == '0'){
        integerNumber = &Automaton_FAIL;
        token = Token::TokenType::constant;
        return true;
    }

    integerNumber = &Automaton_FAIL;
    return false;
}

bool Automatons::Automaton_Integer_1(QChar c){

    if((c >= '0') && (c <= '9')){
        token = Token::TokenType::constant;
        return true;
    }

    integerNumber = &Automaton_FAIL;
    return false;
}
//-----END INTEGER NUMBER AUTOMATON------



//------------STRING AUTOMATON-----------
bool Automatons::Automaton_String_0(QChar c){
    if((c == '\"') && (charcounter == 0))
        stringWord = &Automaton_String_1;
    else
        stringWord = &Automaton_FAIL;

    return false;
}

bool Automatons::Automaton_String_1(QChar c){
    if(c == '\"'){
        stringWord = &Automaton_FAIL;
        token = Token::TokenType::constant;
        return true;
    }

    return false;
}
//----------END STRING AUTOMATON---------



//-----------OPERATOR AUTOMATON----------
bool Automatons::Automaton_Operator_0(QChar c){

    switch(c.toLatin1()){
    case '+':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::plus;
        operatorSymbol = &Automaton_Operator_Plus;
        return true;
        break;
    case '-':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::minus;
        operatorSymbol = &Automaton_Operator_Minus;
        return true;
        break;
    case '*':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::times;
        operatorSymbol = &Automaton_FAIL;
        return true;
        break;
    case '/':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::division;
        operatorSymbol = &Automaton_FAIL;
        return true;
        break;
    case '=':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::attribution;
        operatorSymbol = &Automaton_Operator_Equal;
        return true;
        break;
    case '!':
        operatorSymbol = &Automaton_Operator_Not;
        break;
    case '&':
        operatorSymbol = &Automaton_Operator_And;
        break;
    case '|':
        operatorSymbol = &Automaton_Operator_Or;
        break;
    case '>':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::bigger;
        operatorSymbol = &Automaton_Operator_bigger;
        return true;
        break;
    case '<':
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::smaller;
        operatorSymbol = &Automaton_Operator_smaller;
        return true;
        break;
    default:
        operatorSymbol = &Automaton_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Operator_Plus(QChar c){

    operatorSymbol = &Automaton_FAIL;

    if(c == '+'){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::plusplus;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Minus(QChar c){

    operatorSymbol = &Automaton_FAIL;

    if(c == '-'){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::minusminus;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Equal(QChar c){

    operatorSymbol = &Automaton_FAIL;

    if(c == '='){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::equalequal;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Not(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::notequal;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_And(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '&'){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::and_op;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Or(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '|'){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::or_op;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_bigger(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::biggerequal;
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_smaller(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = Token::TokenType::operation;
        *datatype = (int)Token::TokenSubtype::smallerequal;
        return true;
    }

    return false;
}
//--------------END AUTOMATON------------



//------------SYMBOL AUTOMATON-----------

bool Automatons::Automaton_Symbol_0(QChar c){

    limiters = &Automaton_FAIL;

    switch(c.toLatin1()){
    case '{':
        token = Token::TokenType::begincode;
        return true;
        break;
    case '}':
        token = Token::TokenType::endcode;
        return true;
        break;
    case '(':
        token = Token::TokenType::beginargument;
        return true;
        break;
    case ')':
        token = Token::TokenType::endargument;
        return true;
        break;
    case ';':
        token = Token::TokenType::eol;
        return true;
        break;
    case ',':
        token = Token::TokenType::separator;
        return true;
        break;
    default:
        break;
    }

    return false;

}
//----------END SYMBOL AUTOMATON---------
