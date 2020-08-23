//Q.3 Insert this array in CLL int arr[]={9,0,4,5,6,7,0,0,6,4};

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

void CircularLinkedList(int* arr, int n)
{
	struct node* Head = NULL;
	struct node* temp;
	for(int i=0;i<n;i++)
	{
		if(Head == NULL)
		{
			temp = newNode(arr[0]);
			Head = temp;
		}
		else
		{
			temp->next = newNode(arr[i]);
			temp = temp->next;
		}
	}
	temp->next = Head;
	viewList(Head, n);
}

int main()
{
    int arr[]={9,0,4,5,6,7,0,0,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);
	CircularLinkedList(arr, n);
	return 0;
}

