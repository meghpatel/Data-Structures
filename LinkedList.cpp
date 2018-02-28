#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//creating a structure for LinkedList

typedef struct node
{
	int val;
	struct node *next;	
}Node;


struct node *head = NULL;
//All the function definitions
int menu();
void display(struct node*); 
struct node *newNode(struct node*);
struct node *insertAtBeg(struct node*); 
struct node *insertAtEnd(struct node*); 
struct node *insertAfter(struct node*,int); 
struct node *insertBefore(struct node*,int); 
struct node *deleteAtBeg(struct node*); 
struct node *deleteAtEnd(struct node*); 
struct node *deleteAfter(struct node*,int); 
struct node *deleteBefore(struct node*,int); 


int main()
{
	int r=menu();
	return r;
}

int menu()
{
	system("cls");
	printf("Select your operation\n");
	printf("1.Insertion at beginning\n2.Insertion at end\n3.Insertion after a value\n");
	printf("4.Insertion before a value\n5.Deletion at beginning\n6.Deletion at end\n");
	printf("7.Deletion after a value\n8.Deletion before a value\n9.Exit\n");
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			head = insertAtBeg(head);
			display(head);
			menu();
			break;
		}
		case 2:
		{
			head = insertAtEnd(head);
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
		case 5:
		{
			
			break;
		}
		case 6:
		{
			
			break;
		}
		case 7:
		{
			
			break;
		}
		case 8:
		{
			
			break;
		}
		case 9:
		{
			return 0;
			break;
		}
		default:
		{
			cout<<"/nEnter from the given choices\n"<<endl;
			menu();		
		}
	}	
}

struct node *newNode(struct node *head)
{
	Node *newnode, *ptr;
	newnode = (struct node*)malloc(sizeof(Node));
	printf("Enter the data to be inserted:");
	int data;
	scanf("%d",&data);
	newnode->val = data;
	if(head==NULL)
	{
		head = newnode;
		newnode->next = NULL;
		return head;
	}
	else
	{
		//printf("else");
		ptr = newnode;
		return ptr;
	}
}

struct node *insertAtBeg(struct node *head)
{
	if(head==NULL)
	{
		head = newNode(head);
		head->next = NULL;
		return head;
	}
	else
	{
		Node *ptr,*n1;
		n1 = newNode(head);
		n1->next = head;
		head = n1;
		return head;
	}
}

struct node *insertAtEnd(struct node *head)
{
	if(head==NULL)
	{
		head = newNode(head);
		head->next = NULL;
		return head;
	}
	else
	{
		Node *ptr,*n1;
		ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		n1 = newNode(head);
		ptr->next = n1;
		ptr = n1;
		n1->next = NULL;
		return head;
	}
}

void display(struct node *head)
{
	system("cls");
	Node *ptr;
	ptr = head;
	printf("\n\n");
	printf("------------------------------------\n");
	while(ptr->next!=NULL)
	{
		printf("|%d| --> ",ptr->val);
		ptr = ptr->next;
	}
	printf("|%d| --> NULL \n",ptr->val);
	printf("------------------------------------\n");
	getch();
}







	/*Node *n1,*n2,*n3,*n4,*ptr;
	n1 = newNode(head);
	head = n1;
	ptr = head;
	n2 = newNode(head);
	//ptr->next = n2;
	n1->next = n2;
	//display(head);
	n3 = newNode(head);
	//ptr->next->next = NULL;
	n2->next = n3;
	n3->next = NULL;
	display(head);
	return ptr->next->val;
	//cout<<ptr->next->next;*/
