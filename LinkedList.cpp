#include<iostream>
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
	Node *n1,*n2,*n3,*n4,*ptr;
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
	//cout<<ptr->next->next;
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

void display(struct node *head)
{
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
}
