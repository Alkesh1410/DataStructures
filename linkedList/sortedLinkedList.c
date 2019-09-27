#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}N;

void addNode(N **);
void displayNodes(N *);

void addNode(N **ptr)
{
	N *temp = (N *)malloc(sizeof(N));

	printf("Please enter the data into the node\t:");
	scanf("%d",&temp->data);

	if((*ptr == 0) || (temp->data <= (*ptr)->data))
	{
		temp->link = *ptr;
		*ptr = temp;
	}
	else
	{
		N *last = *ptr;
		while( (last->link != 0) && (temp->data>last->link->data) )
			last = last->link;

		temp->link = last->link;
		last->link = temp;
	}
}

void displayNodes(N *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int main()
{
	N *hptr = 0;
	char ch;
	do{
		addNode(&hptr);
		printf("Do you want to add nodes further\t(y/n): ");
		scanf(" %c",&ch);
	}while(ch == 'y');

	displayNodes(hptr);
}
