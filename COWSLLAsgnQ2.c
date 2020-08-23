//Q.2 create link list insert data by user upto nodes user want.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int val)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	return ptr;
}

void viewList(struct node* Head)
{
	printf("\nLinked List : ");
	struct node* temp = Head;
	while(temp)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void LinkedList()
{
	struct node* Head = NULL;
	struct node* temp = Head;

	printf("How many nodes do want to insert ? ");
	int n;
	scanf("%d",&n);
	printf("Enter the %d values you want to insert : ",n);
	for(int i=0;i<n;i++)
	{
		int val;
		scanf("%d",&val);
		if(Head == NULL)
		{
			temp = newNode(val);
			Head = temp;
		}
		else
		{
			temp->next = newNode(val);
			temp = temp->next;
		}
	}
	viewList(Head);
}

int main()
{
	LinkedList();
	return 0;
}
