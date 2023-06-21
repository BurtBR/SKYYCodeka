#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include "syntaxtreenode.h"

class SyntaxTree{

private:
    SyntaxTreeNode root;
    SyntaxTreeNode *currentnode;

public:
    SyntaxTree();
    ~SyntaxTree();
};

#endif // SYNTAXTREE_H
