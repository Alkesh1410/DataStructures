#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack* link;
}STACK;

int TOP=0,max;

void PUSH(STACK **);
void POP(STACK **);
void display(STACK *);

int main()
{
   printf("Please decide the max. size of stack\n");
    scanf("%d",&max);

    STACK *hptr = 0;

    while(1)
    {
    int select;
options:    printf("Please select the options as below:\n1.\tPUSH the data\n2.\tPOP the data\n\n");
    scanf("%d",&select);

    if(select == 1)
    {
            if(TOP < max)
            {
                PUSH(&hptr);
                display(hptr);
                TOP++;
            }
            else
            {
                printf("Stack Overflow!\n");
                goto options;
            }
    }
    else if(select == 2)
    {
        if(TOP > 0)
            {
                POP(&hptr);
                display(hptr);
                TOP--;
            }
        else
            {
                printf("Stack Underflow!\n");
                goto options;
            }
    }

    else
        continue;

}
    return 0;
}
void POP(STACK **ptr)
{
    STACK *last = *ptr;
    if(last->link != NULL)
    {
        while(last->link->link != 0)
            last = last->link;
        free(last->link);
        last->link = 0;
    }
    else
    {
        free(*ptr);
        *ptr=NULL;

    }
}

void PUSH(STACK **ptr)
{
    STACK *temp = (STACK*)malloc(sizeof(STACK));

    printf("Please enter the data:\t");
    scanf("%d",&temp->data);

    if(*ptr == 0)
    {
        temp->link = *ptr;
        *ptr = temp;
    }
    else
    {
        STACK *last = *ptr;

        while(last->link != 0)
            last = last->link;

        temp->link = last ->link;
        last->link = temp;
    }
}

void display(STACK *ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}