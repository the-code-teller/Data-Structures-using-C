//Q.4 Create a link list by user and give him these following option
//(i)Delete head node.
//(ii)insert new node at head.
//(iii)delete lastnode
//(iv)insert new node at last.
//(v) delete random node as by user.
//(vi) insert new node at random by user.

#include<stdio.h>
#include<stdlib.h>

int nodes_count = 0;
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

struct node* deleteHeadNode(struct node* Head)
{
     struct node* temp = Head;
     Head = temp->next;
     printf("%d was deleted from the head node\n",temp->data);
     nodes_count--;
     return Head;
}

struct node* insertAtHead(struct node* Head)
{
    int val;
    printf("Enter the value you want to insert at Head position : ");
    scanf("%d",&val);
    struct node* temp = newNode(val);
    temp->next = Head;
    Head = temp;
    printf("%d was inserted at Head position\n",Head->data);
    nodes_count++;
    return Head;
}

struct node* deleteLastNode(struct node* Head)
{
    struct node* temp = Head;
    if(Head->next == NULL)
    {
        printf("%d was removed from the head node\n",Head->data);
        Head = NULL;
    }
    while(temp->next->next != NULL)
        temp = temp->next;
    printf("%d was removed from the last node\n",temp->next->data);
    temp->next = NULL;
    nodes_count--;
    return Head;
}

struct node* insertAtLast(struct node* Head)
{
    struct node* temp = Head;
    while(temp->next)
    {
        temp = temp->next;
    }
    int val;
    printf("Enter the value you want to insert at Last position : ");
    scanf("%d",&val);
    temp->next = newNode(val);
    nodes_count++;
    return Head;
}

struct node* deleteUserNode(struct node* Head)
{
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos == 1)
        deleteHeadNode(Head);
    else if(pos == nodes_count)
        deleteLastNode(Head);
    else
    {
        struct node* temp = Head;
        for(int i=1;i<pos-1;i++)
            temp = temp->next;
        printf("%d was deleted from %dth position\n",temp->next->data, pos);
        temp->next = temp->next->next;
    }
    return Head;
}

struct node* insertUserNode(struct node* Head)
{
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos == 1)
        insertAtHead(Head);
    else if(pos == nodes_count)
        insertAtLast(Head);
    else
    {
        struct node* pos_finder = Head;
        for(int i=1;i<pos-1;i++)
            pos_finder = pos_finder->next;

        int val;
        printf("Enter the value : ");
        scanf("%d",&val);
        struct node* temp = newNode(val);
        temp->next = pos_finder->next;
        pos_finder->next = temp;
    }
    return Head;
}

int menu()
{
    printf("\n\n(i)Delete head node\n(ii)insert new node at head\n(iii)delete lastnode\n(iv)insert new node at last\n(v) delete random node as by user\n(vi) insert new node at random by user\n(vii) View List\n(viii) Exit\n\n");
    printf("Enter your choice :  ");
    int choice;
    scanf("%d",&choice);
    return choice;
}

struct node* LinkedList()
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
	return Head;
}

int main()
{
    struct node* Head = LinkedList();
    while(1)
    {
        switch(menu())
        {
            case 1 : Head = deleteHeadNode(Head); break;
            case 2 : Head = insertAtHead(Head); break;
            case 3 : Head = deleteLastNode(Head); break;
            case 4 : Head = insertAtLast(Head); break;
            case 5 : Head = deleteUserNode(Head); break;
            case 6 : Head = insertUserNode(Head); break;
            case 7 : viewList(Head); break;
            default : exit(1);
        }

    }
	return 0;
}
