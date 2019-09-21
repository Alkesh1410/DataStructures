//  Delete the alternate nodes in a linked-list
//  Prepared by Alkesh Shah

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}N;

void insertNode(N**);
void deleteAlternateNode(N**,int);
int displayNodes(N*);

void insertNode(N **ptr)
{
    N *temp = (N *)malloc(sizeof(N));
    
    printf("Please enter the data into the node\t: ");
    scanf("%d",&temp->data);
    
    if(*ptr == 0)
    {
        temp->link = *ptr;
        *ptr = temp;
    }
    else
    {
        N *last = *ptr;
        while(last->link != 0)
            last = last->link;
        
        temp->link = last->link;
        last->link = temp;
    }
}

void deleteAlternateNode(N **ptr, int count)
{
    N *previous, *deleteNode;
    previous = deleteNode = *ptr;
    int c = 1;
    
    while(c < count-1)
    {
        previous = previous->link;
        c++;
    }
    deleteNode = previous->link;
    previous->link = previous->link->link;
    free(deleteNode);
    deleteNode = NULL;
}

int displayNodes(N *ptr)
{
    int numberOfNodes = 0;
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
        numberOfNodes++;
    }
    printf("\n");
    return numberOfNodes;
}

int main()
{
    N *hptr = 0;
    char c;
    do{
        insertNode(&hptr);
        printf("Do you want to add new node?\t");
        scanf(" %c",&c);
    }while(c == 'y');
    
    int nodeCount = displayNodes(hptr);
    nodeCount = nodeCount/2;
    int del = 2;
    while(nodeCount)
    {
        deleteAlternateNode(&hptr,del);
        del=del+1;
        nodeCount--;
    }
    displayNodes(hptr);
    
    return 0;
}
