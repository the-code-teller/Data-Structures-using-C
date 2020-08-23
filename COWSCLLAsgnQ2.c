//Q.2 Create a CLL take  input from users.

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

void viewList(struct node* Head, int n)
{
	printf("\nCircular Linked List : ");
	struct node* temp = Head;
	for(int i=0;i<n+2;i++)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("...");
}

void CircularLinkedList()
{
	struct node* Head = NULL;
	struct node* temp;

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
	temp->next = Head;
	viewList(Head, n);
}

int main()
{
	CircularLinkedList();
	return 0;
}
