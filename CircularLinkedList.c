#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int val;
	struct node *next;
}Node;

Node *head = NULL;
Node *ptr123 = NULL;
void menu();
void display(struct node*);
struct node *newNode(struct node*);
struct node *insertLL(struct node*);
struct node *deleteLL(struct node*);

int main()
{
	menu();
}

void menu()
{
	system("cls");
	printf("Select your operation\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	int sel;
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:
		{
			head = insertLL(head);
			display(head);
			menu();
			break;
		}
		case 2:
		{
			head = deleteLL(head);
			display(head);
			menu();
			break;
		}
		case 3:
		{
			
			break;
		}
		case 4:
		{
			
			break;
		}
		default:
		{
					
		}
	}	
}

struct node *newNode(struct node *head)
{
	Node *newnode, *ptr;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted:\n");
	int data;
	scanf("%d",&data);
	newnode->val = data;
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	else
	{
		//printf("else");
		ptr = newnode;
		return ptr;
	}
}

struct node *insertLL(struct node *head)
{
	system("cls");
	printf("Select your insert operation.\n");
	printf("1.Beginning\n");
	printf("2.End\n");
	printf("3.After a value\n");
	printf("4.Before a value\n");
	int sel;
	scanf("%d",&sel);
	if(head==NULL)
	{
		Node *n1;
		n1 = newNode(head);
		head = n1;
		n1->next = head;
		return head;
	}
	else if(sel == 1)
	{
		Node *n1,*ptr;
		n1 = newNode(head);
		ptr = head;
		while(ptr->next!=head)
		{
			ptr = ptr->next;
		}
		ptr->next = n1;
		n1->next = head;
		head = n1;
		return head;
	}
	else if(sel == 2)
	{
		Node *n1,*ptr;
		n1 = newNode(head);
		ptr = head;
		while(ptr->next!=head)
		{
			ptr = ptr->next;
		}
		ptr->next = n1;
		n1->next = head;
		return head;
	}
	else if(sel == 3)
	{
		printf("Enter the value after which you want to INSERT a Node\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1;
		ptr = head;
		if(ptr->next == head)
		{
			if(ptr->val == search)
			{
				n1 = newNode(head);
				ptr->next = n1;
				n1->next = head;
				return head;		
			}
			else
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\n");
				getch();
				return head;	
			}
		}
		else
		{
			while(ptr->next!=head&&ptr->val!=search)
			{
				ptr = ptr->next;	
			}
			if(ptr->val == search)
			{
				flag = 1;
			}
			if(flag == 0)
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\n");
				getch();
				return head;
			}
			else if(flag == 1)
			{
				n1 = newNode(head);
				n1->next = ptr->next;
				ptr->next = n1;
				return head;
			}
		}
	}
}


struct node *deleteLL(struct node *head)
{
	system("cls");
	printf("Select your delete operation.\n");
	printf("1.Beginning\n");
	printf("2.End\n");
	printf("3.After a value\n");
	printf("4.At a value\n");
	int sel;
	scanf("%d",&sel);
	if(head==NULL)
	{
		printf("Oops! The linked list is already empty\n");
		getch();
		return NULL;
	}
	else if(sel == 1)
	{
		Node *n1,*ptr,*temp;
		ptr = head;
		if(ptr->next == head)
		{
			free(head);
			return NULL;
		}
		else
		{
			temp = head;
			while(ptr->next!=head)
			{
				ptr = ptr->next;
			}
			ptr->next = temp->next;
			head = temp->next;
			free(temp);
			return head;
		}
	}
	else if (sel == 2)
	{
		Node *n1,*ptr,*pred=NULL;
		ptr = head;
		if(ptr->next == head)
		{
			free(head);
			return NULL;
		}
		else
		{
			while(ptr->next!=head)
			{
				pred = ptr;
				ptr = ptr->next;
			}
			pred->next = head;
			free(ptr);
			return head;
		}
	}
	else if(sel == 3)
	{
		
	}
}

void display(struct node *head)
{
	system("cls");
	if(head==NULL)
	{
		printf("\n\n");
		printf("------------------------------------\n");
		printf("     N       U       L       L    \n");
		printf("------------------------------------\n");
	}
	else
	{
		Node *ptr;
		ptr = head;
		printf("\n\n");
		printf("------------------------------------\n");
		while(ptr->next!=head)
		{
			printf("|%d| --> ",ptr->val);
			ptr = ptr->next;
		}
		printf("|%d| \n",ptr->val);
		printf("------------------------------------\n");
	}
	getch();
}

