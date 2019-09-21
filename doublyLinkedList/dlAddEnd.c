//	Doublelinked list --> add End
//	Prepared by Alkesh ShahShah

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *flink;
	struct node *llink;
}NODE;

void print(NODE *);
void addEnd(NODE **);

int main()
{
	NODE *hptr = 0;
	char ch;

	do{
		addEnd(&hptr);
		printf("Please enter 'y' or 'Y' to add new node\t:");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));
	print(hptr);
}

void addEnd(NODE **ptr)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));

	printf("Enter Data\t:");
	scanf("%d",&temp->data);

	if(*ptr == 0)
	{
		temp->llink = *ptr;
		temp->flink = *ptr = temp;
	}
	else
	{
		NODE *last = *ptr;

		while(last->llink != 0)
			last = last->llink;

		temp->llink = last->llink;
		last->llink = temp;
		temp->flink = last;
	}
}

void print(NODE *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->llink;
	}
	printf("\n");
}
