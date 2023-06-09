#include "workercompiler.h"

WorkerCompiler::WorkerCompiler(QObject *parent) : QObject{parent}{

}

WorkerCompiler::~WorkerCompiler(){

}

void WorkerCompiler::PrintTokensToFile(QString filename){

    QFile fp(filename);
    QTextStream out(&fp);
    QString tokentext ,straux;

    if(!fp.open(QFile::WriteOnly)){
        emit DisplayInfo("Falha ao gerar arquivo de análise léxica", 0);
        return;
    }

    for(int i=0; i<tokenlist.size() ;i++){

        tokentext = "<" + Token::GetTokenString(tokenlist[i].GetTokenType()) + ",";
        tokentext.append(Token::GetSubTokenString(tokenlist[i].GetTokenSubtype()) + ",");
        tokentext.append(tokenlist[i].GetHashKey() + ",");
        tokentext.append(QString::number(tokenlist[i].GetLine()) + ",");
        tokentext.append(QString::number(tokenlist[i].GetColumn()) + ">");

        if(hashtable.contains(tokenlist[i].GetHashKey())){
            tokentext.append(" STORED: ");
            straux = hashtable.value(tokenlist[i].GetHashKey());
            tokentext.append(GetDataFromString(straux, Token::TokenDataType::value));
        }

        tokentext.append("\n");
        out << tokentext;
    }

    fp.close();
}

void WorkerCompiler::PrintSyntaxTreeToFile(QString filename){
    QFile fp(filename);
    QTextStream out(&fp);
    SyntaxTreeNode *nodeaux = &syntaxtree;
    int level = 0;

    nodeaux->ResetIndex();

    if(!fp.open(QFile::WriteOnly)){
        emit DisplayInfo("Falha ao gerar arquivo de análise sintática", 0);
        return;
    }

    while(nodeaux){
        for(int i=0; i<level ;i++)
            out << "\t";
        out << "<" << Token::GetTokenString(nodeaux->GetNodeToken().GetTokenType()) << ",";
        out << Token::GetSubTokenString(nodeaux->GetNodeToken().GetTokenSubtype()) << ",";
        out << nodeaux->GetTokenHashKey() << ">\n";
        nodeaux = nodeaux->Next(level);
    }

    fp.close();
}

void WorkerCompiler::PrintHashToFile(QString filename){

    QFile fp(filename);
    QTextStream out(&fp);
    QMultiHash<QString,QString>::iterator iterator = hashtable.begin();
    QStringList data, line, straux;

    if(!fp.open(QFile::WriteOnly)){
        emit DisplayInfo("Falha ao gerar arquivo de análise sintática", 0);
        return;
    }

    while(iterator != hashtable.end()){
        out << iterator.key() << ":\n";

        data = iterator.value().split("\n");

        for(int i=0; i<data.size() ;i++){
            line = data[i].split("=");
            if(line.size()){

                out << Token::GetTokenDataString((Token::TokenDataType)line.at(0).toInt()) << "=";

                switch((Token::TokenDataType)line.at(0).toInt()){
                case Token::TokenDataType::scope:
                    out << line.at(1) << "\n";
                    break;
                case Token::TokenDataType::tk_subtype:
                    out << Token::GetSubTokenString((Token::TokenSubtype)line.at(1).toInt()) << "\n";
                    break;
                case Token::TokenDataType::tk_type:
                    out << Token::GetTokenString((Token::TokenType)line.at(1).toInt()) << "\n";
                    break;
                case Token::TokenDataType::value:
                    out << line.at(1) << "\n";
                    break;
                case Token::TokenDataType::returntype:
                    out << Token::GetSubTokenString((Token::TokenSubtype)line.at(1).toInt()) << "\n";
                    break;
                case Token::TokenDataType::attributestypes:
                    straux = line.at(1).split(" ");
                    out << Token::GetSubTokenString((Token::TokenSubtype)straux.at(0).toInt());
                    for(int j=1; j<straux.size() ;j++){
                        out << " " << Token::GetSubTokenString((Token::TokenSubtype)straux.at(j).toInt());
                    }
                    out << "\n";
                    break;
                default:
                    break;
                }
            }
        }

        out << "\n\n";
        iterator++;
    }

    fp.close();
}

bool WorkerCompiler::LexicalAnalysis(QString &code, int &linenumber, QString &invalidchar){

    QTextStream stream(&code);
    QString word;
    QChar c;
    bool isString = false;
    int columnnumber = 1;

    while(!stream.atEnd()){

        columnnumber++;
        stream >> c;

        if(c == '\\'){
            while(c != '\n' && !stream.atEnd())
                stream >> c;

            //Reset parameters
            columnnumber = 2;
            linenumber++;

            //Read one more char (the next after the comment)
            if(!stream.atEnd())
                stream >> c;
            else
                break;
        }

        if(isString && c!='\"')
            word += c;
        else{
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
            case '.':
            case '_':
                word += c;
                break;

            case '\"':
                if(isString){
                    Tokenize(word + '\"', linenumber, (columnnumber - word.size() - 2) );
                    word.clear();
                }else if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1));
                    word.clear();
                    word += c;
                }else{
                    word += c;
                }

                isString = (1 ^ isString);
                break;

            case '|': //can only be ||

                //Tokenize any word before it
                if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }

                word += c;
                stream >> c;
                columnnumber++;
                word += c;
                if(c != '|'){
                    invalidchar = (word);
                    return false;
                    break;
                }else{
                    Tokenize(word, linenumber, columnnumber - 2);
                    word.clear();
                }
                break;

            case '&': //can only be &&

                //Tokenize any word before it
                if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }

                word += c;
                stream >> c;
                columnnumber++;
                word += c;
                if(c != '&'){
                    invalidchar = (word);
                    return false;
                    break;
                }else{
                    Tokenize(word, linenumber, columnnumber - 2);
                    word.clear();
                }
                break;

            //Single Symbols
            case '{':
            case '}':
            case '(':
            case ')':
            case ';':
            case ',':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                if(word.size())
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1));

                Tokenize(QString(c), linenumber, columnnumber - 1);
                word.clear();
                break;

            //Symbols that can be more than one char
            case '!':
            case '>':
            case '<':
            case '=':
                if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }

                word = c;
                stream >> c;
                columnnumber++;

                switch(c.toLatin1()){
                case '!':
                case '>':
                case '<':
                case '=':
                    word += c;
                    Tokenize(word, linenumber, (columnnumber - 1) );
                    break;
                default:
                    stream.seek(stream.pos()-1);
                    columnnumber--;
                    Tokenize(word, linenumber, (columnnumber - 1) );
                    break;
                }

                word.clear();
                break;

            case ' ':
            case '\t':
                if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }
                break;
            case '\n':
                if(word.size()){
                    Tokenize(word, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }
                columnnumber = 1;
                linenumber++;
                break;

            default:
                invalidchar = c;
                return false;
                break;
            }//End switch

        }//End else

    } //End While

    if(word.size())
        Tokenize(word, linenumber, (columnnumber - word.size()));

    return true;
}

bool WorkerCompiler::SyntacticAnalysis(){

    if(!tokenlist.size())
        return true;

    QString strmessage;
    SyntaxTreeNode *nodeaux;
    int lastline = tokenlist.last().GetLine();

    syntaxtree = SyntaxTreeNode();
    syntaxtree.SetTokenType(Token::TokenType::nonterminal);
    syntaxtree.SetTokenSubtype(Token::TokenSubtype::nont_program);

    nodeaux = &syntaxtree;
    while(tokenlist.size() && nodeaux){

        if(!nodeaux->Derivation(tokenlist, strmessage)){
            emit DisplayInfo(strmessage, 0);
            return false;
        }
        nodeaux = nodeaux->Next();
    }

    if(tokenlist.size()){
        emit DisplayInfo("Código extra após finalizar o programa!", 0);
        return false;
    }

    if(nodeaux){
        if(nodeaux->GetNodeToken().GetTokenSubtype() == Token::TokenSubtype::nont_beforemain)
            emit DisplayInfo("Eperava função motherland ao fim do código", 0);
        else
            emit DisplayInfo("Eperava " + Token::GetSubTokenString(nodeaux->GetNodeToken().GetTokenSubtype()) + " ao fim do código", 0);
        tokenlist.append(Token(Token::TokenType::unidentified, Token::TokenSubtype::unidentified, lastline, -1));
        return false;
    }

    return true;
}

bool WorkerCompiler::SemanticAnalysis(){

    if(!SemanticHashInit())
        return false;

    if(!SemanticVerifyOperationTypes())
        return false;

    return true;
}

bool WorkerCompiler::SemanticHashInit(){
    SyntaxTreeNode *nodeaux = &syntaxtree;
    Token::TokenSubtype currentvartype = Token::TokenSubtype::unidentified;
    ScopeCode scope, scopeaux;
    QString straux, identifieraux, vartypesaux;
    QStringList strlist;
    int intaux = 0;

    nodeaux->ResetIndex();

    while(nodeaux){

        switch(nodeaux->GetTokenType()){
        case Token::TokenType::nonterminal:
            switch(nodeaux->GetTokenSubtype()){
            case Token::TokenSubtype::nont_var_declaration:
                nodeaux = nodeaux->Next();
                currentvartype = nodeaux->GetTokenSubtype();
                while(nodeaux->GetTokenType() != Token::TokenType::eol){
                    if(nodeaux->GetTokenType() == Token::TokenType::identifier){
                        nodeaux->SetTokenSubtype(currentvartype);
                        if(!InsertIdentifier(nodeaux->GetTokenHashKey(), currentvartype, scope)){
                            emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                            return false;
                        }
                    }
                    nodeaux = nodeaux->Next();
                }
                break;
            case Token::TokenSubtype::nont_function_return:
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                currentvartype = nodeaux->GetTokenSubtype();

                nodeaux = nodeaux->Next();
                nodeaux->SetTokenSubtype(Token::TokenSubtype::returnfuntion);
                if(!InsertIdentifier(nodeaux->GetTokenHashKey(), Token::TokenSubtype::returnfuntion, scope)){
                    emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                    return false;
                }

                SetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::returntype, QString::number((int)currentvartype), scope);

                scopeaux = scope++;
                identifieraux = nodeaux->GetTokenHashKey();
                vartypesaux.clear();

                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                while(nodeaux->GetTokenType() != Token::TokenType::endargument){
                    switch(nodeaux->GetTokenType()){
                    case Token::TokenType::identifier:
                        nodeaux->SetTokenSubtype(currentvartype);
                        if(!InsertIdentifier(nodeaux->GetTokenHashKey(), currentvartype, scope)){
                            emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                            return false;
                        }
                        break;
                    case Token::TokenType::keyword:
                        currentvartype = nodeaux->GetTokenSubtype();
                        if(!vartypesaux.size())
                            vartypesaux.append(QString::number((int)currentvartype));
                        else
                            vartypesaux.append(" " + QString::number((int)currentvartype));
                        break;
                    default:
                        break;
                    }
                    nodeaux = nodeaux->Next();
                }
                if(vartypesaux.size())
                    SetDataFromHash(identifieraux,Token::TokenDataType::attributestypes, vartypesaux, scopeaux);
                break;
                //END FUNCTION RETURN

            case Token::TokenSubtype::nont_function_void:
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();

                nodeaux->SetTokenSubtype(Token::TokenSubtype::voidfunction);
                if(!InsertIdentifier(nodeaux->GetTokenHashKey(), Token::TokenSubtype::voidfunction, scope)){
                    emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                    return false;
                }

                scopeaux = scope++;
                identifieraux = nodeaux->GetTokenHashKey();
                vartypesaux.clear();

                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                while(nodeaux->GetTokenType() != Token::TokenType::endargument){
                    switch(nodeaux->GetTokenType()){
                    case Token::TokenType::identifier:
                        nodeaux->SetTokenSubtype(currentvartype);
                        if(!InsertIdentifier(nodeaux->GetTokenHashKey(), currentvartype, scope)){
                            emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                            return false;
                        }
                        break;
                    case Token::TokenType::keyword:
                        currentvartype = nodeaux->GetTokenSubtype();
                        if(!vartypesaux.size())
                            vartypesaux.append(QString::number((int)currentvartype));
                        else
                            vartypesaux.append(" " + QString::number((int)currentvartype));
                        break;
                    default:
                        break;
                    }

                    nodeaux = nodeaux->Next();
                }
                if(vartypesaux.size())
                    SetDataFromHash(identifieraux,Token::TokenDataType::attributestypes, vartypesaux, scopeaux);
                break;
                //END VOID FUNCTION

            case Token::TokenSubtype::nont_functioncall:
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();

                identifieraux = nodeaux->GetTokenHashKey();
                straux = GetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::tk_subtype, scope);
                if(!straux.size()){
                    emit Error(2, "Variável não declarada: " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                    return false;
                }

                nodeaux->SetTokenSubtype((Token::TokenSubtype) straux.toInt());

                straux = GetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::attributestypes, scope);
                if(straux.size())
                    strlist = straux.split(" ");
                else
                    strlist.clear();
                intaux = 0;

                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                while(nodeaux->GetTokenType() != Token::TokenType::endargument){
                    switch(nodeaux->GetTokenSubtype()){
                    case Token::TokenSubtype::nont_value:
                        nodeaux = nodeaux->Next();

                        if(nodeaux->GetTokenType() == Token::TokenType::identifier){
                            straux = GetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::tk_subtype, scope);
                            if(!straux.size()){
                                emit Error(2, "Variável não declarada: " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                                return false;
                            }
                            nodeaux->SetTokenSubtype((Token::TokenSubtype) straux.toInt());
                        }

                        if(intaux >= strlist.size()){
                            emit Error(2, "Quantidade de dados incompatível: " + identifieraux, nodeaux->GetTokenLine());
                            return false;
                        }


                        if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::strongon ||
                            nodeaux->GetTokenSubtype() == Token::TokenSubtype::strongonoff){

                            if(strlist.at(intaux).toInt() != (int)Token::TokenSubtype::bolichisky){
                                emit Error(2, "Tipo incorreto de dado: " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                                return false;
                            }

                        }else if((int)nodeaux->GetTokenSubtype() != strlist.at(intaux).toInt()){
                            emit Error(2, "Tipo incorreto de dado: " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                            return false;
                        }
                        intaux++;
                        break;
                    default:
                        break;
                    }

                    nodeaux = nodeaux->Next();
                }

                if(intaux != strlist.size()){
                    emit Error(2, "Quantidade de dados incompatível: " + identifieraux, nodeaux->GetTokenLine());
                    return false;
                }
                break;
                //END FUNCTIONCALL

            case Token::TokenSubtype::nont_mainfunction:
                scope++;
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                while(nodeaux->GetTokenType() != Token::TokenType::endargument){
                    switch(nodeaux->GetTokenType()){
                    case Token::TokenType::identifier:
                        nodeaux->SetTokenSubtype(currentvartype);
                        if(!InsertIdentifier(nodeaux->GetTokenHashKey(), currentvartype, scope)){
                            emit Error(2, "Multiplas definições de " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                            return false;
                        }
                        break;
                    case Token::TokenType::keyword:
                        currentvartype = nodeaux->GetTokenSubtype();
                        break;
                    default:
                        break;
                    }

                    nodeaux = nodeaux->Next();
                }
                break;
                //END MAINFUNCTION

            case Token::TokenSubtype::nont_loop_block:
                scope++;
                break;
            case Token::TokenSubtype::nont_ifelsestatement:
                scope++;
                break;
            default:
                break;
            }
            break;
        //END TYPE NONTERMINAL

        case Token::TokenType::endcode:
            scope--;
            break;

        case Token::TokenType::identifier:
            straux = GetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::tk_subtype, scope);
            if(!straux.size()){
                emit Error(2, "Variável não declarada: " + nodeaux->GetTokenHashKey(), nodeaux->GetTokenLine());
                return false;
            }
            nodeaux->SetTokenSubtype((Token::TokenSubtype) straux.toInt());
            break;

        default:
            break;
        }

        nodeaux = nodeaux->Next();
    };

    return true;
}

bool WorkerCompiler::SemanticVerifyOperationTypes(){

    SyntaxTreeNode *nodeaux = &syntaxtree;
    int lineaux;
    Token::TokenSubtype currentvartype = Token::TokenSubtype::unidentified;
    Token::TokenSubtype currentreturntype = Token::TokenSubtype::unidentified;

    nodeaux->ResetIndex();

    while(nodeaux){

        switch(nodeaux->GetNodeToken().GetTokenSubtype()){
        case Token::TokenSubtype::nont_value:
            nodeaux = nodeaux->Next();
            if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::nont_functioncall){
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::voidfunction){
                    emit Error(2, "Função chernobyl não retorna valor algum", nodeaux->GetTokenLine());
                    return false;
                }
            }
            break;
        case Token::TokenSubtype::nont_attribution:
            nodeaux = nodeaux->Next();
            currentvartype = nodeaux->GetTokenSubtype();
            lineaux = nodeaux->GetTokenLine();
            nodeaux = nodeaux->Next();
            nodeaux = nodeaux->Next();
            if(currentvartype != GetValueType(nodeaux)){
                emit Error(2, "Atribuição de tipo incompatível. Esperado: " + Token::GetSubTokenString(currentvartype), lineaux);
                return false;
            }
            break;
        case Token::TokenSubtype::nont_function_definition:
            nodeaux = nodeaux->Next();
            if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::nont_function_return){
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                nodeaux = nodeaux->Next();
                currentreturntype = nodeaux->GetTokenSubtype();
            }
            break;
        case Token::TokenSubtype::nont_return_statement:
            nodeaux = nodeaux->Next();
            lineaux = nodeaux->GetTokenLine();
            nodeaux = nodeaux->Next();
            if(GetValueType(nodeaux) != currentreturntype){
                emit Error(2, "Tipo de retorno incompatível. Esperado: " + Token::GetSubTokenString(currentreturntype), lineaux);
                return false;
            }
            break;
        default:
            break;
        }

        nodeaux = nodeaux->Next();
    }

    return true;
}

Token::TokenSubtype WorkerCompiler::GetValueType(SyntaxTreeNode *nodeaux){

    Token::TokenSubtype currentvartype = Token::TokenSubtype::unidentified;
    ScopeCode scopeaux;
    int levelaux = 0;

    nodeaux = nodeaux->Next();

    switch(nodeaux->GetTokenType()){
    case Token::TokenType::nonterminal:
        switch(nodeaux->GetTokenSubtype()){
        case Token::TokenSubtype::nont_functioncall:
            nodeaux = nodeaux->Next();
            nodeaux = nodeaux->Next();
            if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::voidfunction){
                return Token::TokenSubtype::unidentified;
            }
            //Functions are always declared in global scope
            currentvartype = (Token::TokenSubtype)GetDataFromHash(nodeaux->GetTokenHashKey(), Token::TokenDataType::returntype, scopeaux).toInt();
            //Skip arguments
            while((nodeaux->GetTokenType() != Token::TokenType::endargument) && (levelaux > 0))
                nodeaux->Next(levelaux);
            nodeaux->Next(levelaux);//eol
            break;
        default:
            break;
        }
        break;
    case Token::TokenType::identifier:
        currentvartype = nodeaux->GetTokenSubtype();
        break;
    case Token::TokenType::constant:
        currentvartype = nodeaux->GetTokenSubtype();
        break;
    case Token::TokenType::keyword:
        switch(nodeaux->GetTokenSubtype()){
        case Token::TokenSubtype::strongon:
        case Token::TokenSubtype::strongonoff:
            currentvartype = Token::TokenSubtype::bolichisky;
            break;
        case Token::TokenSubtype::niet:
            nodeaux = nodeaux->Next();
            return GetValueType(nodeaux);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    nodeaux = nodeaux->Next();

    if(nodeaux->GetTokenSubtype() == Token::TokenSubtype::nont_operation){
        nodeaux = nodeaux->Next();
        nodeaux = nodeaux->Next(); //operator
        if(currentvartype != GetValueType(nodeaux))
            return Token::TokenSubtype::unidentified;
        return currentvartype;
    }

    return currentvartype;
}

void WorkerCompiler::Tokenize(QString word, int linenumber, int columnnumber){

    Automatons lexers;
    Token::TokenSubtype datatype = Token::TokenSubtype::unidentified;
    Token::TokenType currenttoken = lexers.GetToken(word, datatype);
    QString hashkey = word;

    switch(currenttoken){
    case Token::TokenType::unidentified:
        emit DisplayInfo("Blyat!!! Sequência desconhecida na linha " + QString::number(linenumber) + ": "+ word, 0);
        undefinedtokens.append(Token(currenttoken, Token::TokenSubtype::unidentified, linenumber, columnnumber));
        break;

    case Token::TokenType::constant:
        if(hashkey[0] == '\"')
            hashkey = "@str" + QString::number(tokenlist.size());

        //If the identifier/constant isn't on hashtable, insert it
        InsertTokenToHash(Token(currenttoken, datatype, hashkey, linenumber, columnnumber), hashkey, word);

        tokenlist.append(Token(currenttoken, datatype, hashkey, linenumber, columnnumber));
        break;

    case Token::TokenType::identifier:
        tokenlist.append(Token(currenttoken, datatype, hashkey, linenumber, columnnumber));
        break;

    default:
        tokenlist.append(Token(currenttoken, datatype, linenumber, columnnumber));
        break;
    }
}

void WorkerCompiler::InsertTokenToHash(Token tk, QString hashkey, const QString &value){

    QString dataaux;

    if(!hashtable.contains(hashkey)){

        SetDataToString(dataaux, Token::TokenDataType::tk_type, QString::number((int)tk.GetTokenType()));
        SetDataToString(dataaux, Token::TokenDataType::tk_subtype, QString::number((int)tk.GetTokenSubtype()));
        if(tk.GetTokenType() == Token::TokenType::constant)
            SetDataToString(dataaux, Token::TokenDataType::value, value);

        hashtable.insert(hashkey, dataaux);
    }

}

QString WorkerCompiler::GetDataFromString(const QString &strdata, Token::TokenDataType datatype){
    QStringList datalist = strdata.split('\n'), dataline;

    if(strdata.size()){
        for(int i=0; i<datalist.size(); i++){
            dataline = datalist[i].split('=');
            if(dataline.size() == 2){
                if(dataline.at(0).toInt() == (int)datatype){
                    return dataline.at(1);
                }
            }
        }
    }

    return QString();
}

void WorkerCompiler::SetDataToString(QString &strdata, Token::TokenDataType datatype, const QString &value){
    QStringList datalist = strdata.split('\n'), dataline;
    bool datafound = false;

    if(strdata.size()){

        for(int i=0; i<datalist.size(); i++){
            dataline = datalist[i].split('=');
            if(dataline.size() == 2){
                if(dataline.at(0).toInt() == (int)datatype){
                    datalist[i] = (dataline.at(0) + "=" + value);
                    datafound = true;
                    break;
                }
            }
        }

        if(!datafound){
            datalist.append(QString::number((int)datatype) + "=" + value);
        }

        strdata.clear();
        strdata.append(datalist.at(0));
        for(int i=1; i<datalist.size() ;i++){
            strdata.append("\n" + datalist.at(i));
        }

    }else{
        strdata = QString::number((int)datatype) + "=" + value;
    }
}

QString WorkerCompiler::GetDataFromHash(QString hashkey, Token::TokenDataType datatype, ScopeCode &scope){

    QList<QString> itemlist = hashtable.values(hashkey);

    for(int i=0; i<itemlist.size() ;i++){
        if(scope.IsDefined(GetDataFromString(itemlist.at(i), Token::TokenDataType::scope))){
            return GetDataFromString(itemlist.at(i), datatype);
        }
    }

    return QString();
}

bool WorkerCompiler::SetDataFromHash(QString hashkey, Token::TokenDataType datatype, QString data, ScopeCode &scope){

    QMultiHash<QString,QString>::iterator iterator;
    QList<QString> itemlist;

    itemlist = hashtable.values(hashkey);

    for(int i=0; i<itemlist.size() ;i++){
        if(scope.IsDefined(GetDataFromString(itemlist.at(i), Token::TokenDataType::scope))){
            iterator = hashtable.find(hashkey, itemlist.at(i));
            SetDataToString(iterator.value(), datatype, data);
            return true;
        }
    }

    return false;
}

bool WorkerCompiler::InsertIdentifier(QString hashkey, Token::TokenSubtype datatype, ScopeCode &scope){
    QList<QString> itemlist;
    QString dataaux;

    SetDataToString(dataaux, Token::TokenDataType::tk_type, QString::number((int)Token::TokenType::identifier));
    SetDataToString(dataaux, Token::TokenDataType::tk_subtype, QString::number((int)datatype));
    SetDataToString(dataaux, Token::TokenDataType::scope, scope);

    itemlist = hashtable.values(hashkey);

    if(!itemlist.size()){
        hashtable.insert(hashkey, dataaux);
        return true;
    }

    for(int i=0; i<itemlist.size() ;i++){
        if(scope.IsDefined(GetDataFromString(itemlist.at(i), Token::TokenDataType::scope))){
            return false;
        }
    }

    hashtable.insert(hashkey, dataaux);
    return true;
}

//---------------------------SLOTS---------------------------

void WorkerCompiler::Compile(QString text){

    //TEMPORARIO
    if(!text.size())
        QThread::sleep(5);
    //TEMPORARIO

    QString c;
    int linecounter = 1;

    //Clear All Lists
    undefinedtokens.clear();
    tokenlist.clear();
    hashtable.clear();

    if(!LexicalAnalysis(text, linecounter, c)){

        if(linecounter == -1){
            emit Error(0, "Falha ao criar arquivo de saída da análise léxica", linecounter);
            return;
        }else{
            emit Error(2, "Caractere desonhecido na linha " + QString::number(linecounter) + ": " + c, linecounter);
            return;
        }

    }

    //The text is no longer needed
    text.clear();

    if(undefinedtokens.size()){
        emit Error(2, "Compilação interrompida", undefinedtokens[0].GetLine());
        return;
    }

    PrintTokensToFile("GENERATED FILES/lexer.skyy");

    if(!SyntacticAnalysis()){
        PrintSyntaxTreeToFile("GENERATED FILES/syntax.skyy");
        emit Error(2, "Falha na sintaxe, compilação interrompida", tokenlist.first().GetLine());
        return;
    }

    if(!SemanticAnalysis()){
        PrintSyntaxTreeToFile("GENERATED FILES/syntax.skyy");
        PrintHashToFile("GENERATED FILES/hash.skyy");
        return;
    }

    PrintSyntaxTreeToFile("GENERATED FILES/syntax.skyy");
    PrintHashToFile("GENERATED FILES/hash.skyy");

    emit Done(2);
}

//---------------------------SLOTS---------------------------
