#include "syntaxtreenode.h"

SyntaxTreeNode::SyntaxTreeNode(){

}

SyntaxTreeNode::SyntaxTreeNode(SyntaxTreeNode *nodeparent, Token tk){
    parent = nodeparent;
    nodetoken = tk;
}

SyntaxTreeNode::~SyntaxTreeNode(){

}

void SyntaxTreeNode::DeleteNode(SyntaxTreeNode *node){
    for(int i=0; i<childs.size() ;i++){
        if(&childs[i] == node){
            lastchildindex--;
            childs.remove(i);
            return;
        }
    }
}

SyntaxTreeNode SyntaxTreeNode::ChildAt(int index){
    if(index < childs.size())
        return childs.at(index);

    return SyntaxTreeNode();
}

void SyntaxTreeNode::AppendToken(const Token &tk){
    childs.append(SyntaxTreeNode(this, tk));
}

void SyntaxTreeNode::DeleteTokenAt(int index){
    if(index < childs.size())
        childs.remove(index);
}

SyntaxTreeNode *SyntaxTreeNode::DeleteSelf(){
    if(parent){
        parent->DeleteNode(this);
    }
    return parent;
}

bool SyntaxTreeNode::HasChilds(){
    if(childs.size())
        return true;
    return false;
}

SyntaxTreeNode *SyntaxTreeNode::Next(){

    if(!HasChilds()){
        if(parent)
            return parent->Next();
        return nullptr;
    }

    if((lastchildindex+1) < childs.size()){
        return &childs[++lastchildindex];
    }else if(parent){
        return parent->Next();
    }

    return nullptr;
}

SyntaxTreeNode *SyntaxTreeNode::NextNonTerminal(){

    SyntaxTreeNode *nodeaux = Next();

    while(nodeaux){
        if(nodeaux->GetNodeToken().IsNonTerminal())
            return nodeaux;
        else
            nodeaux = nodeaux->Next();
    }

    return nullptr;
}

bool SyntaxTreeNode::Derivation(QQueue<Token> &streamtoken, QString &message){

    if(!nodetoken.IsNonTerminal()){
        if(streamtoken.first().GetTokenType() == nodetoken.GetTokenType() &&
           streamtoken.first().GetTokenSubtype() == nodetoken.GetTokenSubtype()){
            nodetoken = streamtoken.first();
            streamtoken.removeFirst();
            return true;
        }else{
            message = "Esperado token <" + Token::GetTokenString(nodetoken.GetTokenType()) + ",";
            message.append(Token::GetSubTokenString(nodetoken.GetTokenSubtype()) + "> e obteve <");
            message.append(Token::GetTokenString(streamtoken.first().GetTokenType()) + ",");
            message.append(Token::GetSubTokenString(streamtoken.first().GetTokenSubtype()) + ">");
            return false;
        }
    }

    lastchildindex = -1;
    childs.clear();

    switch(nodetoken.GetTokenSubtype()){
    case Token::TokenSubtype::nont_program:
        childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_beforemain, -1, -1)));
        childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_mainfunction, -1, -1)));
        childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_aftermain, -1, -1)));
        return true;
        break;

    case Token::TokenSubtype::nont_beforemain:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::moscow:
            case Token::TokenSubtype::chernobyl:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_function_definition, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_beforemain, -1, -1)));
                return true;
                break;
            case Token::TokenSubtype::intsky:
            case Token::TokenSubtype::charovsky:
            case Token::TokenSubtype::floatsky:
            case Token::TokenSubtype::bolichisky:
            case Token::TokenSubtype::palavrovka:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_var_declaration, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_beforemain, -1, -1)));
                return true;
                break;
            default:
                break;
            }
            break;
        case Token::TokenType::mainfunction:
            DeleteSelf();
            return true;
            break;
        default:
            message = "Esperado declaração de função ou variável, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_aftermain:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::moscow:
            case Token::TokenSubtype::chernobyl:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_function_definition, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_aftermain, -1, -1)));
                return true;
                break;
            case Token::TokenSubtype::intsky:
            case Token::TokenSubtype::charovsky:
            case Token::TokenSubtype::floatsky:
            case Token::TokenSubtype::bolichisky:
            case Token::TokenSubtype::palavrovka:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_var_declaration, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_aftermain, -1, -1)));
                return true;
                break;
            default:
                break;
            }
            break;
        default:
            message = "Esperado declaração de função ou variável, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_mainfunction:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::mainfunction:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_arguments, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code_block, -1, -1)));
            return true;
            break;
        default:
            message = "Esperado declaração da função motherland, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_arguments:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::beginargument:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_arglist, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::endargument, Token::TokenSubtype::unidentified, -1, -1)));
            return true;
            break;
        default:
            message = "Esperado inicio de argumento \"(\", recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_arglist:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::intsky:
            case Token::TokenSubtype::charovsky:
            case Token::TokenSubtype::floatsky:
            case Token::TokenSubtype::bolichisky:
            case Token::TokenSubtype::palavrovka:
                childs.append(SyntaxTreeNode(this, streamtoken.first()));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::identifier, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_more_arguments, -1, -1)));
                return true;
                break;
            default:
                message = "Esperado tipo de variável do argumento, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        case Token::TokenType::endargument:
            DeleteSelf();
            return true;
            break;
        default:
            message = "Esperado tipo de variável do argumento, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_more_arguments:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::separator:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_arglist, -1, -1)));
            return true;
            break;
        case Token::TokenType::endargument:
            DeleteSelf();
            return true;
            break;
        default:
            message = "Esperado separador, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_code_block:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::begincode:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::endcode, Token::TokenSubtype::unidentified, -1, -1)));
            return true;
            break;
        default:
            message = "Esperado inicio de bloco de código \"{\", recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_code_block_return:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::begincode:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_return_statement, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::endcode, Token::TokenSubtype::unidentified, -1, -1)));
            return true;
            break;
        default:
            message = "Esperado inicio de bloco de código \"{\", recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_code:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::forevisky:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_loop_block, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
                return true;
                break;
            case Token::TokenSubtype::ikov:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_ifelsestatement, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
                return true;
                break;
            case Token::TokenSubtype::moscow:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_functioncall, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
                return true;
                break;
            case Token::TokenSubtype::intsky:
            case Token::TokenSubtype::charovsky:
            case Token::TokenSubtype::floatsky:
            case Token::TokenSubtype::bolichisky:
            case Token::TokenSubtype::palavrovka:
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_var_declaration, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
                return true;
            default:
                message = "Esperado tipo de variável, chamada de função, bloco de repetição ou ifelse, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        case Token::TokenType::identifier:
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_attribution, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code, -1, -1)));
            return true;
            break;
        case Token::TokenType::endcode:
            DeleteSelf();
            return true;
            break;
        default:
            message = "Esperado declaração, loop, ifelse, atribuição ou chamada de função, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_return_statement:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::yebat:
                childs.append(SyntaxTreeNode(this, streamtoken.first()));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_value, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::eol, Token::TokenSubtype::unidentified, -1, -1)));
                return true;
                break;
            default:
                message = "Esperado yebat, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        default:
            message = "Esperado declaração de retorno, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_var_declaration:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::intsky:
            case Token::TokenSubtype::charovsky:
            case Token::TokenSubtype::floatsky:
            case Token::TokenSubtype::bolichisky:
            case Token::TokenSubtype::palavrovka:
                childs.append(SyntaxTreeNode(this, streamtoken.first()));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::identifier, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_more_declaration, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::eol, Token::TokenSubtype::unidentified, -1, -1)));
                return true;
                break;
            default:
                message = "Esperado tipo de variável, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        default:
            message = "Esperado declaração de variável, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_more_declaration:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::separator:
            childs.append(SyntaxTreeNode(this, streamtoken.first()));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::identifier, Token::TokenSubtype::unidentified, -1, -1)));
            childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_more_declaration, -1, -1)));
            return true;
            break;
        case Token::TokenType::eol:
            DeleteSelf();
            return true;
            break;
        default:
            message = "Esperado separador ou \";\", recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }

        break;

    case Token::TokenSubtype::nont_loop_block:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::forevisky:
                childs.append(SyntaxTreeNode(this, streamtoken.first()));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::beginargument, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_value, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::endargument, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code_block, -1, -1)));
                return true;
                break;
            default:
                message = "Esperado forevisky, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        default:
            message = "Esperado bloco de repetição, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }

        break;

    case Token::TokenSubtype::nont_ifelsestatement:
        switch(streamtoken.first().GetTokenType()){
        case Token::TokenType::keyword:
            switch(streamtoken.first().GetTokenSubtype()){
            case Token::TokenSubtype::ikov:
                childs.append(SyntaxTreeNode(this, streamtoken.first()));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::beginargument, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_value, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::endargument, Token::TokenSubtype::unidentified, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_code_block, -1, -1)));
                childs.append(SyntaxTreeNode(this, Token(Token::TokenType::nonterminal, Token::TokenSubtype::nont_elsestatement, -1, -1)));
                return true;
                break;
            default:
                message = "Esperado ikov, recebeu " + Token::GetSubTokenString(streamtoken.first().GetTokenSubtype());
                break;
            }
            break;
        default:
            message = "Esperado bloco condicional, recebeu " + Token::GetTokenString(streamtoken.first().GetTokenType());
            break;
        }
        break;

    case Token::TokenSubtype::nont_elsestatement:

        break;

    case Token::TokenSubtype::nont_attribution:

        break;

    case Token::TokenSubtype::nont_value:

        break;

    case Token::TokenSubtype::nont_operation:

        break;

    case Token::TokenSubtype::nont_number:

        break;

    case Token::TokenSubtype::nont_functioncall:

        break;

    case Token::TokenSubtype::nont_function_definition:

        break;

    case Token::TokenSubtype::nont_function_return:

        break;

    case Token::TokenSubtype::nont_function_void:

        break;

    default:
        break;
    }

    return false;
}

void SyntaxTreeNode::ResetIndex(){

    lastchildindex = -1;

    for(int i=0; i<childs.size() ;i++)
        childs[i].ResetIndex();
}

//-----------------------------------
//--------------Getters--------------
//-----------------------------------
Token SyntaxTreeNode::GetNodeToken(){
    return nodetoken;
}

SyntaxTreeNode *SyntaxTreeNode::GetChild(int index){
    if(index < childs.size()){
        lastchildindex = index;
        return &childs[index];
    }

    return nullptr;
}

QString SyntaxTreeNode::GetTokenHashKey(){
    return nodetoken.GetHashKey();
}


//-----------------------------------
//--------------Setters--------------
//-----------------------------------
void SyntaxTreeNode::SetParent(SyntaxTreeNode *node){
    parent = node;
}

void SyntaxTreeNode::SetNodeToken(const Token &tk){
    nodetoken = tk;
}

void SyntaxTreeNode::SetTokenType(Token::TokenType type){
    nodetoken.SetTokenType(type);
}

void SyntaxTreeNode::SetTokenSubtype(Token::TokenSubtype type){
    nodetoken.SetTokenSubtype(type);
}

void SyntaxTreeNode::SetTokenHashKey(QString hashkey){
    nodetoken.SetHashKey(hashkey);
}
