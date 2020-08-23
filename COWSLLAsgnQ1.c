//Q.1 create link list of node 5 of integer insert data in code not by user.

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
	printf("Linked List : ");
	struct node* temp = Head;
	while(temp)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}

void LinkedList()
{
	struct node* Head = NULL;
	struct node* temp;
	for(int i=0;i<5;i++)
	{
		temp = newNode(rand() % 1000);
		temp->next = Head;
		Head = temp;
	}
	viewList(Head);
}

int main()
{
	srand(time(NULL));
	LinkedList();
	return 0;
}
