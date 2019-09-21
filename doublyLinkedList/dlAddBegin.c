//	Double linked list --> Add Begin

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *flink;
	struct node *llink;
}NODE;

void print(NODE *);
void addBegin(NODE **);

int main()
{
	NODE *hptr = 0;
	char ch;
	do{
		addBegin(&hptr);
		printf("Please enter 'y' or 'Y' to add new node\t:");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));
	print(hptr);
}

void addBegin(NODE **ptr)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));

	printf("Enter data\t:");
	scanf("%d",&temp->data);

	temp->llink = *ptr;
	temp->flink = *ptr = temp;
}

void print(NODE *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->llink;
	}
	printf("\n");
}
