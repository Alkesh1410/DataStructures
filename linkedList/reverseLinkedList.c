//	Prepared By Alkesh Shah

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;

int printNode(NODE *);
void addNode(NODE **);
void reverseNodes(NODE **,int);

void reverseNodes(NODE **ptr,int count)		//	Using single pointer
{
	int i;
	NODE **p = (NODE **)malloc((sizeof(NODE))*count);
	NODE *temp = *ptr;

	for(i=0;i<count;i++,temp=temp->link)
		p[i] = temp;

	p[0]->link = 0;

	for(i=1;i<count;i++)
		p[i]->link = p[i-1];

	*ptr = p[count-1];
}

void addNode(NODE **ptr)
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	printf("Please Enter the data\t:");
	scanf("%d",&temp->data);

	if(*ptr == 0)
	{
		temp->link = *ptr;
		*ptr = temp;
	}
	else
	{
		NODE *last = *ptr;
		
		while(last->link != 0)
			last = last->link;

		temp->link = last->link;
		last->link = temp;
	}
}

int printNode(NODE *ptr)
{
	static int cnt;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
		cnt++;
	}
	printf("\n");
	return cnt;
}

int main()
{
	NODE *hptr = 0;
	char ch;int numberOfNodes;

	do{
		addNode(&hptr);
		printf("Do you want to add nodes?\t:(y/n)");
		scanf(" %c",&ch);
	}while(ch == 'y');

	numberOfNodes = printNode(hptr);
	reverseNodes(&hptr,numberOfNodes);
	printNode(hptr);
	return 0;
}
