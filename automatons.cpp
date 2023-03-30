#include "automatons.h"

Automatons::Automatons(){

}

void Automatons::StartAutomatons(){
    charcounter = 0;
    ReservedWords = &Automaton_Reserved_0;
}

QString Automatons::GetToken(QString word){
    StartAutomatons();

    for(charcounter=0; charcounter<word.size() ;charcounter++){

        if((this->*ReservedWords)(word[charcounter])){
            if(charcounter == (word.size()-1))
                return token;
        }

    }

    return "TK_bunda";
}

//--------RESERVED WORD AUTOMATON--------

bool Automatons::Automaton_Reserved_0(QChar c){

    switch(c.toLatin1()){
    case 'b':
        ReservedWords = &Automaton_Reserved_bolichisky;
        break;
    case 'c':
        ReservedWords = &Automaton_Reserved_ch;
        break;
    case 'f':
        ReservedWords = &Automaton_Reserved_f;
        break;
    case 'i':
        ReservedWords = &Automaton_Reserved_i;
        break;
    case 'k':
        ReservedWords = &Automaton_Reserved_kalashn;
        break;
    case 'm':
        ReservedWords = &Automaton_Reserved_m;
        break;
    case 'p':
        ReservedWords = &Automaton_Reserved_palavrovka;
        break;
    case 's':
        ReservedWords = &Automaton_Reserved_strongon;
        break;
    case 'y':
        ReservedWords = &Automaton_Reserved_yebat;
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_bolichisky(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c != 'l')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'i')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'c')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'h')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'i')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 9:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'y'){
            token = "TK_bolichisky";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch(QChar c){
    switch(charcounter){
    case 1:
        if(c != 'h')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c == 'a')
            ReservedWords = &Automaton_Reserved_ch_arovsky;
        else if(c == 'e')
            ReservedWords = &Automaton_Reserved_ch_ernobyl;
        else
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch_arovsky(QChar c){

    switch(charcounter){
    case 3:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'v')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'y'){
            token = "TK_charovsky";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_ch_ernobyl(QChar c){

    switch(charcounter){
    case 3:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'n')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'b')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'y')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'l'){
            token = "TK_chernobyl";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_f(QChar c){

    if(c == 'l')
        ReservedWords = &Automaton_Reserved_f_loatsky;
    else if(c == 'o')
        ReservedWords = &Automaton_Reserved_f_orevisky;
    else
        ReservedWords = &Automaton_Reserved_FAIL;

    return false;

}

bool Automatons::Automaton_Reserved_f_loatsky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 't')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'y'){
            token = "TK_floatsky";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_f_orevisky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'e')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'v')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'i')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'y'){
            token = "TK_forevisky";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_i(QChar c){
    if(c == 'k')
        ReservedWords = &Automaton_Reserved_i_kov;
    else if(c == 'n')
        ReservedWords = &Automaton_Reserved_i_ntsky;
    else
        ReservedWords = &Automaton_Reserved_FAIL;

    return false;
}

bool Automatons::Automaton_Reserved_i_kov(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'v'){
            token = "TK_ikov";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_i_ntsky(QChar c){

    switch(charcounter){
    case 2:
        if(c != 't')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'y'){
            token = "TK_intsky";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_kalashn(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c != 'l')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 's')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'h')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'n'){
            token = "TK_kalashn";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_m(QChar c){

    if(c == 'o')
        ReservedWords = &Automaton_Reserved_m_otherland;
    else if(c == 'i')
        ReservedWords = &Automaton_Reserved_m_ickwhail;
    else
        ReservedWords = &Automaton_Reserved_FAIL;

    return false;
}

bool Automatons::Automaton_Reserved_m_otherland(QChar c){

    switch(charcounter){
    case 2:
        if(c != 't')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'h')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'e')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'l')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        if(c != 'n')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 9:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'd'){
            token = "TK_motherland";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_m_ickwhail(QChar c){

    switch(charcounter){
    case 2:
        if(c != 'c')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'w')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'h')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'i')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'l'){
            token = "TK_mickwhail";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_palavrovka(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c != 'l')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'v')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c != 'v')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 8:
        if(c != 'k')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 9:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'a'){
            token = "TK_palavrovka";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_strongon(QChar c){

    switch(charcounter){
    case 1:
        if(c != 't')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c != 'r')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        if(c != 'n')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 5:
        if(c != 'g')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 6:
        if(c != 'o')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 7:
        if(c == 'n'){
            token = "TK_strongon";
            return true;
        }
        break;
    case 8:
        if(c == 'o')
            ReservedWords = &Automaton_Reserved_strongon_off;
        else
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_strongon_off(QChar c){

    switch(charcounter){
    case 9:
        if(c != 'f')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 10:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 'f'){
            token = "TK_strongonoff";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_yebat(QChar c){

    switch(charcounter){
    case 1:
        if(c != 'e')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 2:
        if(c != 'b')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 3:
        if(c != 'a')
            ReservedWords = &Automaton_Reserved_FAIL;
        break;
    case 4:
        ReservedWords = &Automaton_Reserved_FAIL;
        if(c == 't'){
            token = "TK_yebat";
            return true;
        }
        break;
    default:
        ReservedWords = &Automaton_Reserved_FAIL;
        break;
    }

    return false;
}

bool Automatons::Automaton_Reserved_FAIL(QChar){
    return false;
}
//------END RESERVED WORD AUTOMATON------
