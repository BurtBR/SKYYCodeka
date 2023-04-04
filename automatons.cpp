#include "automatons.h"

Automatons::Automatons(){

}

void Automatons::StartAutomatons(){
    charcounter = 0;
    reservedWords = &Automaton_Reserved_0;
    floatNumber = &Automaton_Float_0;
    integerNumber = &Automaton_Integer_0;
    stringWord = &Automaton_String_0;
    operatorSymbol = &Automaton_Operator_0;
    identifierWord = &Automaton_Identifier_0;
    limiters = &Automaton_Symbol_0;
}

QString Automatons::GetToken(QString word){
    StartAutomatons();

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

    return "unidentified";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "mainfunction";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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
            token = "keyword";
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

    if(c == QChar('3'))
        qDebug() << "Aqui";
    else
        qDebug() << c;

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
        token = "identifier";
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
        token = "identifier";
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
        token = "float";
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
        token = "integer";
        return true;
    }else if(c == '0'){
        integerNumber = &Automaton_FAIL;
        token = "integer";
        return true;
    }

    integerNumber = &Automaton_FAIL;
    return false;
}

bool Automatons::Automaton_Integer_1(QChar c){

    if((c >= '0') && (c <= '9')){
        token = "integer";
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
        token = "string";
        return true;
    }

    return false;
}
//----------END STRING AUTOMATON---------



//-----------OPERATOR AUTOMATON----------
bool Automatons::Automaton_Operator_0(QChar c){

    switch(c.toLatin1()){
    case '+':
        token = "operator";
        operatorSymbol = &Automaton_Operator_Plus;
        return true;
        break;
    case '-':
        token = "operator";
        operatorSymbol = &Automaton_Operator_Minus;
        return true;
        break;
    case '*':
        token = "operator";
        operatorSymbol = &Automaton_FAIL;
        return true;
        break;
    case '/':
        token = "operator";
        operatorSymbol = &Automaton_FAIL;
        return true;
        break;
    case '=':
        token = "operator";
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
        token = "operator";
        operatorSymbol = &Automaton_Operator_bigger;
        return true;
        break;
    case '<':
        token = "operator";
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
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Minus(QChar c){

    operatorSymbol = &Automaton_FAIL;

    if(c == '-'){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Equal(QChar c){

    operatorSymbol = &Automaton_FAIL;

    if(c == '='){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Not(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_And(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '&'){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_Or(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '|'){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_bigger(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = "operator";
        return true;
    }

    return false;
}

bool Automatons::Automaton_Operator_smaller(QChar c){

    operatorSymbol = &Automaton_FAIL;
    if(c == '='){
        token = "operator";
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
        token = "begincode";
        return true;
        break;
    case '}':
        token = "endcode";
        return true;
        break;
    case '(':
        token = "beginargument";
        return true;
        break;
    case ')':
        token = "endargument";
        return true;
        break;
    case ';':
        token = "eol";
        return true;
        break;
    case ',':
        token = "separator";
        return true;
        break;
    default:
        break;
    }

    return false;

}
//----------END SYMBOL AUTOMATON---------
