#include "syntaxtree.h"

SyntaxTree::SyntaxTree(){
    root.SetTokenType(Token::TokenType::nonterminal);
    root.SetTokenSubtype(Token::TokenSubtype::nont_program);
    currentnode = &root;
}

SyntaxTree::~SyntaxTree(){

}
