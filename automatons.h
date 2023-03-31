#ifndef AUTOMATONS_H
#define AUTOMATONS_H

#include <QString>

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
    QString token;
    int charcounter = 0;

    //Private Methods
    void StartAutomatons();

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

public:
    Automatons();
    QString GetToken(QString word);
};

#endif // AUTOMATONS_H
