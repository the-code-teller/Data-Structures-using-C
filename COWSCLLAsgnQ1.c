//Q.1 Create a CLL of 6 nodes insert inputs in your code.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
	printf("\nCircular Linked List : ");
	struct node* temp = Head;
	for(int i=0;i<18;i++)
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
	for(int i=0;i<6;i++)
	{
		if(Head == NULL)
		{
			temp = newNode(rand() % 1000);
			Head = temp;
		}
		else
		{
			temp->next = newNode(rand() % 1000);
			temp = temp->next;
		}
	}
	temp->next = Head;
	viewList(Head);
}

int main()
{
	srand(time(NULL));
	CircularLinkedList();
	return 0;
}
