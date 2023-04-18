#include "workercompiler.h"

WorkerCompiler::WorkerCompiler(QObject *parent) : QObject{parent}{

}

bool WorkerCompiler::LexicalAnalysis(QString &code, int &linenumber, QString &invalidchar){

    QFile file("lexer.skyy");
    QTextStream stream(&code), out(&file);
    QString word;
    QChar c;
    bool isString = false;
    int columnnumber = 1;

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        linenumber = -1;
        return false;
    }

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
                    Tokenize(word + '\"', out, linenumber, (columnnumber - word.size() - 2) );
                    word.clear();
                }else if(word.size()){
                    Tokenize(word, out, linenumber, (columnnumber - word.size() - 1));
                    word.clear();
                    word += c;
                }else{
                    word += c;
                }

                isString = (1 ^ isString);
                break;

            case '|': //can only be ||
                break;

            case '&': //can only be &&
                word += c;
                stream >> c;
                columnnumber++;
                word += c;
                if(c != '&'){
                    invalidchar = (word);
                    file.close();
                    return false;
                    break;
                }else{
                    Tokenize(word, out, linenumber, columnnumber - 2);
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
                    Tokenize(word, out, linenumber, (columnnumber - word.size() - 1));

                Tokenize(QString(c), out, linenumber, columnnumber - 1);
                word.clear();
                break;

            //Symbols that can be more than one char
            case '!':
            case '>':
            case '<':
            case '=':
                if(word.size()){
                    Tokenize(word, out, linenumber, (columnnumber - word.size() - 1) );
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
                    Tokenize(word, out, linenumber, (columnnumber - 1) );
                    break;
                default:
                    stream.seek(stream.pos()-1);
                    columnnumber--;
                    Tokenize(word, out, linenumber, (columnnumber - 1) );
                    break;
                }

                word.clear();
                break;

            case ' ':
            case '\t':
                if(word.size()){
                    Tokenize(word, out, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }
                break;
            case '\n':
                if(word.size()){
                    Tokenize(word, out, linenumber, (columnnumber - word.size() - 1) );
                    word.clear();
                }
                columnnumber = 1;
                linenumber++;
                break;

            default:
                invalidchar = c;
                file.close();
                return false;
                break;
            }//End switch

        }//End else

    } //End While

    if(word.size())
        Tokenize(word, out, linenumber, (columnnumber - word.size()));

    file.close();
    return true;
}

void WorkerCompiler::Tokenize(QString word, QTextStream &out, int linenumber, int columnnumber){

    Automatons lexers;
    int datatype = -1;
    Token::TokenType currenttoken = lexers.GetToken(word, datatype);
    QString tokenoutput = "<";

    switch(currenttoken){
    case Token::TokenType::unidentified:
        emit DisplayInfo("Blyat!!! Sequência desconhecida na linha " + QString::number(linenumber) + ": "+ word, 0);
        tokenoutput.append(QString::number((int)currenttoken) + "," + word);
        break;

    case Token::TokenType::mainfunction:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::keyword:
        tokenoutput.append(QString::number((int)currenttoken) + "," + QString::number(datatype));
        break;

    case Token::TokenType::identifier:
        tokenoutput.append(QString::number((int)currenttoken) + "," + word);
        break;

    case Token::TokenType::constant:
        tokenoutput.append(QString::number((int)currenttoken) + "," + word);
        break;

    case Token::TokenType::operation:
        tokenoutput.append(QString::number((int)currenttoken) + "," + QString::number(datatype));
        break;

    case Token::TokenType::begincode:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::endcode:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::beginargument:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::endargument:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::eol:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    case Token::TokenType::separator:
        tokenoutput.append(QString::number((int)currenttoken) + ",");
        break;

    default:
        break;
    }

    tokenoutput.append("," + QString::number(linenumber) + "," + QString::number(columnnumber) + ">\n");

    out << tokenoutput;
}

//---------------------------SLOTS---------------------------

void WorkerCompiler::Compile(QString text){

    //TEMPORARIO
    if(!text.size())
        QThread::sleep(5);
    //TEMPORARIO

    QString c;
    int linecounter = 1;

    if(!LexicalAnalysis(text, linecounter, c)){

        if(linecounter == -1){
            emit Error(0, "Falha ao criar arquivo de saída da análise léxica", linecounter);
        }else{
            emit Error(2, "Caractere desonhecido na linha " + QString::number(linecounter) + ": " + c, linecounter);
            return;
        }

    }

    emit Done(2);
}

//---------------------------SLOTS---------------------------
