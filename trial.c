#include <stdio.h>
#include <stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *leftChild;
    struct BSTnode *rightChild;
}BST;

BST *insertChild (BST *,int);
void inOrderTransverse (BST *);
BST *createNode (int);
BST *findMinFromRightSubtree(BST *);		//	You can use findMaxFromLeftSubtree as well

BST *findMinFromRightSubtree(BST *par)
{
    if(par == NULL)
        return NULL;
    else if(par->leftChild != NULL)
        return findMinFromRightSubtree(par->leftChild);
        
    return par;
}

BST *createNode (int value)
{
    BST *newNode = (BST *) malloc (sizeof (BST));

    newNode->data = value;
    newNode->leftChild = newNode->rightChild = NULL;
        
    return newNode;
}

BST *insertChild (BST * par, int value)
{
    if (par == NULL)
        return createNode(value);
    
    if (value < par->data)
        par->leftChild = insertChild (par->leftChild,value);
    else if(value > par->data)
        par->rightChild = insertChild (par->rightChild,value);
        
        return par;
}

void inOrderTransverse (BST *par)
{
    if (par == NULL)
        return;

    inOrderTransverse(par->leftChild);
    printf ("%d\t", par->data);
    inOrderTransverse(par->rightChild);
}

int main ()
{
    BST *parent = NULL;
    char ch;
    int value,flag;

    parent = insertChild(parent,10);
    parent = insertChild(parent,20);
    parent = insertChild(parent,30);

    inOrderTransverse (parent);
    return 0;
}
