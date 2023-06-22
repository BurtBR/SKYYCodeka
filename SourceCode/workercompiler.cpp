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
        tokenlist.append(Token(Token::TokenType::unidentified, Token::TokenSubtype::unidentified, lastline, 1));
        return false;
    }

    return true;
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
    case Token::TokenType::identifier:

        if(hashkey[0] == '\"')
            hashkey = "@str" + QString::number(tokenlist.size());

        //If the identifier/constant isn't on hashtable, insert it
        InsertTokenToHash(Token(currenttoken, datatype, hashkey, linenumber, columnnumber), hashkey, word);

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

    PrintTokensToFile("lexer.skyy");

    if(!SyntacticAnalysis()){
        PrintSyntaxTreeToFile("syntax.skyy");
        emit Error(2, "Falha na sintaxe, compilação interrompida", tokenlist.first().GetLine());
        return;
    }

    PrintSyntaxTreeToFile("syntax.skyy");

    emit Done(2);
}

//---------------------------SLOTS---------------------------
