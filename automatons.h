#ifndef AUTOMATONS_H
#define AUTOMATONS_H

#include <QString>

enum class Tokens{
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

enum class Keywords{
    intsky,         //0
    charovsky,      //1
    floatsky,       //2
    bolichisky,     //3
    chernobyl,      //4
    palavrovka,     //5
    michwhail,      //6
    forevisky,      //7
    ikov,           //8
    kalashn,        //9
    niet,           //10
    yebat,          //11
    strongon,       //12
    strongonoff     //13
};

enum class Operations{
    plus,           //0
    minus,          //1
    times,          //2
    division,       //3
    attribution,    //4
    equalequal,     //5
    notequal,       //6
    bigger,         //7
    smaller,        //8
    biggerequal,    //9
    smallerequal,   //10
    and_op,         //12
    or_op,          //13
    plusplus,       //14
    minusminus      //15
};

class Automatons{

private:
    //Type definition
    typedef bool (Automatons::*State)(QChar);

    //Private Variables
    State reservedWords = nullptr;
    State floatNumber = nullptr;
    State integerNumber = nullptr;
    State stringWord = nullptr;
    State operatorSymbol = nullptr;
    State identifierWord = nullptr;
    State limiters = nullptr;
    Tokens token;
    int charcounter = 0;
    int *datatype = nullptr;

    //Private Methods
    void StartAutomatons(int &keyoptype);

    //Failed automaton method
    bool Automaton_FAIL(QChar);

    //Reserved Word Automaton
    bool Automaton_Reserved_0(QChar c);
    bool Automaton_Reserved_bolichisky(QChar c);
    bool Automaton_Reserved_ch(QChar c);
    bool Automaton_Reserved_ch_arovsky(QChar c);
    bool Automaton_Reserved_ch_ernobyl(QChar c);
    bool Automaton_Reserved_f(QChar c);
    bool Automaton_Reserved_f_loatsky(QChar c);
    bool Automaton_Reserved_f_orevisky(QChar c);
    bool Automaton_Reserved_i(QChar c);
    bool Automaton_Reserved_i_kov(QChar c);
    bool Automaton_Reserved_i_ntsky(QChar c);
    bool Automaton_Reserved_kalashn(QChar c);
    bool Automaton_Reserved_m(QChar c);
    bool Automaton_Reserved_m_otherland(QChar c);
    bool Automaton_Reserved_m_ickwhail(QChar c);
    bool Automaton_Reserved_niet(QChar c);
    bool Automaton_Reserved_palavrovka(QChar c);
    bool Automaton_Reserved_strongon(QChar c);
    bool Automaton_Reserved_strongon_off(QChar c);
    bool Automaton_Reserved_yebat(QChar c);

    //Identifier Automaton
    bool Automaton_Identifier_0(QChar c);
    bool Automaton_Identifier_1(QChar c);

    //Integer Automaton
    bool Automaton_Integer_0(QChar c);
    bool Automaton_Integer_1(QChar c);

    //Float Automaton
    bool Automaton_Float_0(QChar c);
    bool Automaton_Float_Before(QChar c);
    bool Automaton_Float_After(QChar c);

    //String Automaton
    bool Automaton_String_0(QChar c);
    bool Automaton_String_1(QChar c);

    //Operator Automaton
    bool Automaton_Operator_0(QChar c);
    bool Automaton_Operator_Plus(QChar c);
    bool Automaton_Operator_Minus(QChar c);
    bool Automaton_Operator_Equal(QChar c);
    bool Automaton_Operator_Not(QChar c);
    bool Automaton_Operator_And(QChar c);
    bool Automaton_Operator_Or(QChar c);
    bool Automaton_Operator_bigger(QChar c);
    bool Automaton_Operator_smaller(QChar c);

    //Symbol Automaton
    bool Automaton_Symbol_0(QChar c);

public:
    Automatons();
    Tokens GetToken(QString word, int &keyoptype);
    static QString GetTokenString(Tokens tk);
};

#endif // AUTOMATONS_H
