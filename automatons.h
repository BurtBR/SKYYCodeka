#ifndef AUTOMATONS_H
#define AUTOMATONS_H

#include <QString>

class Automatons{

private:
    //Type definition
    typedef bool (Automatons::*State)(QChar);

    //Private Variables
    State ReservedWords = nullptr;
    QString token;
    int charcounter = 0;

    //Private Methods
    void StartAutomatons();

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
    bool Automaton_Reserved_FAIL(QChar);

public:
    Automatons();
    QString GetToken(QString word);
};

#endif // AUTOMATONS_H
