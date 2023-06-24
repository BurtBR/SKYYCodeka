#ifndef SCOPECODE_H
#define SCOPECODE_H

#include <QString>
#include <QVector>

class ScopeCode{
private:
    QVector<int> scope = {0,-1};

public:
    ScopeCode();
    operator QString();
    ScopeCode operator++(int);
    ScopeCode operator--(int);
    bool IsDefined(QString scopestr);
    QVector<int> GetScope();
};

#endif // SCOPECODE_H
