//Q.3 insert this array in a link list. int arr[]={9,0,4,5,6,7,0,0,6,4};

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

void LinkedList(int* arr, int n)
{
	struct node* Head = NULL;
	struct node* temp = Head;

	printf("Enter the %d values you want to insert : ",n);
	for(int i=0;i<n;i++)
	{
		if(Head == NULL)
		{
			temp = newNode(arr[i]);
			Head = temp;
		}
		else
		{
			temp->next = newNode(arr[i]);
			temp = temp->next;
		}
	}
	viewList(Head);
}

int main()
{
    int arr[]={9,0,4,5,6,7,0,0,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);
	LinkedList(arr, n);
	return 0;
}
