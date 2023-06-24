#include "scopecode.h"

ScopeCode::ScopeCode(){

}

ScopeCode::operator QString(){
    QString aux;

    aux.append(QString::number(scope[0]));
    for(int i=1; i<(scope.size()-1) ;i++){
        aux.append(" " + QString::number(scope[i]));
    }

    return aux;
}

ScopeCode ScopeCode::operator++(int){
    ScopeCode aux = *this;

    scope.append(-1);
    scope[scope.size()-2]++;

    return aux;
}

ScopeCode ScopeCode::operator--(int){
    ScopeCode aux = *this;

    if(scope.size() > 2){
        scope.pop_back();
    }

    return aux;
}
bool ScopeCode::IsDefined(QString scopestr){
    QStringList list = scopestr.split(' ');

    if(list.size() > (scope.size()-1))
        return false;

    for(int i=0; i<list.size() ;i++){
        if(list[i].toInt() != scope[i])
            return false;
    }

    return true;
}

QVector<int> ScopeCode::GetScope(){
    return scope;
}
