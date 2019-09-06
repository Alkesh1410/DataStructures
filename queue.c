//  Prepared by Alkesh Shah

#include <stdio.h>
#include <stdlib.h>

typedef struct q
{
    int data;
    struct q *link;
}Q;

int front = 0,rare=-1;

void enQ(Q **);
void deQ(Q **);
void display(Q *);
int isFull(int,int);

void display(Q *ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int isFull(int f,int r)
{
    if(f == (r+1))
        return 1;
    else
        return 0;
}

void deQ(Q **ptr)
{
    Q *temp = *ptr;
    free(*ptr); *ptr = 0;
    *ptr = temp->link;
}

void enQ(Q **ptr)
{
    Q *temp = (Q*)malloc(sizeof(Q));

    printf("Enter data\t:");
    scanf("%d",&temp->data);

    if(*ptr == 0)
    {
        temp->link = *ptr;
        *ptr = temp;
    }
    else
    {
        Q *last = *ptr;

        while(last->link != 0)
            last = last->link;

        temp->link = last->link;
        last->link = temp;
    }
}

int main()
{
    Q *hptr = 0;
    printf("Please decide the max size of Queue\n");
    int max;
    scanf("%d",&max);

    char menu;
option:    printf("Please select the proper option from the menu\na.\tEn-queue Operation\nb.\tDe-queue Operation\n");
    printf("Please Choose your option\t:");
    scanf(" %c",&menu);

    if(menu == 'a')
    {
        if(front == max)
        {
            printf("Queue is full\n");
            goto option;
        }
        else
        {
            enQ(&hptr);
            display(hptr);
            front++;
            goto option;
        }
    }
    else if (menu == 'b')
    {
        if(isFull(front,rare))
        {
            printf("Queue is empty\n");
            goto option;
        }
        else
        {
            deQ(&hptr);
            display(hptr);
            rare++;
            goto option;
        }
    }
    else
    {
        printf("Please select proper options\n");
        goto option;
    }
    return 0;
}
