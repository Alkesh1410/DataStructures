//	Doublelinked list --> add End and delete the node
//	By Alkesh Shah

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *flink;
	struct node *llink;
}NODE;

int print(NODE *);
void addEnd(NODE **);
void delNode(NODE **,int);

int main()
{
	NODE *hptr = 0;
	char ch;

	do{
		addEnd(&hptr);
		printf("Please enter 'y' or 'Y' to add new node\t:");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));
	int c = print(hptr);

	ch = 0;
	printf("Do you want to delete any node(press 'y' to continue)\t:");
	scanf(" %c",&ch);

	if(ch == 'y')
	{
		delNode(&hptr,c);
		print(hptr);
	}
}

void delNode(NODE **ptr,int c)
{
	printf("Please enter the node you want to delete\t:");
	int del;
scan:	scanf("%d",&del);
	if(del>c)
	{
		printf("Plese enter valid entry:\t");
		goto scan;
	}
	else
	{
		if(del == 1)
		{
			NODE *temp = *ptr;
			temp = *ptr;
			free(*ptr); *ptr = 0;
			*ptr = temp->llink;
			temp->llink->flink = *ptr;
		}
		else
		{
			NODE *latest = *ptr;
			int dummy=1;

			while(dummy<del)
			{
				latest = latest->llink;
				dummy++;
			}
			if(del==c)
			{
				latest->flink->llink = latest->llink;
				free(latest);
				latest = 0;
			}
			else
			{
				latest->flink->llink = latest->llink;
				latest->llink->flink = latest->flink;
				free(latest);
				latest = 0;
			}
		}
	}
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

int print(NODE *ptr)
{
	static int cnt = 0;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->llink;
		cnt++;
	}
	printf("\n");
	return cnt;
}
