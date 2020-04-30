//  Prepared by Alkesh Shah

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
void preOrderTransverse (BST *);
void postOrderTransverse (BST *);
BST *createNode (int);
BST *deleteNode(BST *,int);
BST *findMinFromRightSubtree(BST *);		//	You can use findMaxFromLeftSubtree as well

BST *findMinFromRightSubtree(BST *par)
{
    if(par == NULL)
        return NULL;
    else if(par->leftChild != NULL)
        return findMinFromRightSubtree(par->leftChild);
        
    return par;
}

BST *deleteNode(BST *par, int value)
{
    if(par == NULL) return par;
    else if (value < par->data) par->leftChild = deleteNode(par->leftChild,value);
    else if (value > par->data) par->rightChild = deleteNode(par->rightChild,value);
    
    else
    {
//  case-1: No Child
        if(par->leftChild == NULL && par->rightChild == NULL)
        {
            free(par);
            par = NULL;
            return par;
        }
//  case-2: One Child
        else if(par->leftChild == NULL || par->rightChild == NULL)
        {
            BST *temp;
            if(par->rightChild == NULL)
                temp = par->leftChild;
            else
                temp = par->rightChild;
            
            free(par);
            return temp;
        }
//  case-3: Two Child
        else
        {
            BST *temp = findMinFromRightSubtree(par->rightChild);
            par->data = temp->data;
            par->rightChild = deleteNode(par->rightChild,temp->data);
        }
        return par;
    }
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
void preOrderTransverse (BST *par)
{
    if (par == NULL)
        return;

    printf ("%d\t", par->data);
    preOrderTransverse(par->leftChild);
    preOrderTransverse(par->rightChild);
}
void postOrderTransverse (BST *par)
{
    if (par == NULL)
        return;

    postOrderTransverse(par->leftChild);
    postOrderTransverse(par->rightChild);
    printf ("%d\t", par->data);
}


int main ()
{
    BST *parent = NULL;
    char ch;
    int value,flag;

    printf ("Please enter the data\t:");
    scanf ("%d", &value);
    parent = insertChild (parent,value);

    flag = 1;
    while(flag)
    {
        printf ("Do you want to add data in Tree\t:");
        scanf (" %c", &ch);
        
        if(ch != 'y')
            flag = 0;
        else
        {
            printf ("Please enter the data\t:");
            scanf ("%d", &value);
            insertChild(parent,value);
        }
    }

    inOrderTransverse (parent);
    deleteNode(parent,0);			//	Enter value as per your input
    inOrderTransverse (parent);
    deleteNode(parent,15);			//	Enter value as per your input
    inOrderTransverse (parent);

    return 0;
}
