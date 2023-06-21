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

void SyntaxTreeNode::DeleteSelf(){
    if(parent){
        parent->DeleteNode(this);
    }
}

bool SyntaxTreeNode::HasChilds(){
    if(childs.size())
        return true;
    return false;
}

//-----------------------------------
//--------------Getters--------------
//-----------------------------------
SyntaxTreeNode *SyntaxTreeNode::GetParent(){
    return parent;
}

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
