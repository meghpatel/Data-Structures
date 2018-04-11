#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node 
{
	int val;
	struct node *right;
	struct node *left;
}Node;

Node *head = NULL;

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
	fflush(stdin);
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
			display(head);
			menu();
			break;
		}
		case 4:
		{
			
			break;
		}
		default:
		{
			printf("Enter from given choices only\nPress Enter to go to menu\n");
			getch();
			menu();	
		}
	}	
}

struct node *newNode(struct node *head)
{
	Node *newnode, *ptr;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\n\n\nEnter the data to be inserted:\n");
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
	printf("4.Exit to menu\n");
	int sel;
	scanf("%d",&sel);
	if(head==NULL)
	{
		Node *n1;
		n1 = newNode(head);
		head = n1;
		n1->right = NULL;
		n1->left = NULL;
		return head;
	}
	else if(sel == 1)
	{
		Node *n1,*ptr;
		n1 = newNode(head);
		ptr = head;
		ptr->left = n1;
		head = n1;
		n1->right = ptr;
		n1->left = NULL;
		return head;
	}
	else if(sel == 2)
	{
		Node *n1,*ptr;
		n1 = newNode(head);
		ptr = head;
		while(ptr->right!=NULL)
		{
			ptr = ptr->right;
		}
		ptr->right = n1;
		n1->left = ptr;
		n1->right = NULL;
		return head;
	}
	else if(sel == 3)
	{
		int search,flag = 0;
		printf("\n\n\nEnter the value after which you want to INSERT a Node\n");
		scanf("%d",&search);
		Node *ptr,*n1,*next;
		ptr = head;
		if(ptr->right == NULL)//if only one node
		{
			if(ptr->val == search)//if the only node same as the query
			{
				n1 = newNode(head);
				ptr->right = n1;
				n1->right = NULL;
				n1->left = ptr;
				return head;		
			}
			else//not found
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;	
			}
		}
		else
		{
			while(ptr->right!=NULL&&ptr->val!=search)//traversing
			{
				ptr = ptr->right;	
			}
			if(ptr->val == search)//double check
			{
				flag = 1;
			}
			if(flag == 0)//not found
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;
			}//found
			else if(flag == 1)//found and adding a node
			{
				n1 = newNode(head);
				n1->right = ptr->right;
				next = ptr->right;
				n1->left = ptr;
				ptr->right = n1;
				if(next!=NULL)
					next->left = n1;
				return head;
			}
		}
	}
	else if(sel == 4)
	{
		return head;
	}
	else
	{
		printf("Enter proper value.\nPress Enter to go back to main menu\n");
		getch();
		return head;
	}
}

struct node *deleteLL(struct node *head)
{
	system("cls");
	printf("Select your delete operation.\n");
	printf("1.Beginning\n");
	printf("2.End\n");
	printf("3.At a value\n");
	printf("4.Exit to main Menu\n");
	int sel;
	scanf("%d",&sel);
	if(head==NULL)
	{
		printf("Oops! The linked list is already empty\nPress Enter\n");
		getch();
		return NULL;
	}
	else if(sel == 1)
	{
		Node *n1,*ptr,*temp;
		ptr = head;
		if(ptr->right == NULL)//if only one node
		{
			free(head);
			return NULL;
		}
		else//multiple nodes
		{
			temp = head;
			head = temp->right;
			head->left = NULL;
			free(temp);
			return head;
		}
	}
	else if (sel == 2)
	{
		Node *n1,*ptr,*temp;
		ptr = head;
		if(ptr->right == NULL)//if only one node
		{
			free(ptr);
			return NULL;
		}
		else//multiple nodes
		{
			while(ptr->right!=NULL)//traversing
			{
				ptr = ptr->right;
			}
			temp = ptr->left;
			temp->right = NULL;
			free(ptr);
			return head;
		}
	}
	else if(sel == 3)
	{
		printf("\n\n\nEnter the value which you want to DELETE a Node\n\n\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1,*temp,*prev,*next;
		ptr = head;
		if(ptr->right == NULL)//if only one node
		{
			if(ptr->val == search)//if the only node same as the query
			{
				free(ptr);
				return NULL;		
			}
			else//not found
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;	
			}
		}
		else
		{
			while(ptr->right!=NULL&&ptr->val!=search)//traversing
			{
				ptr = ptr->right;	
			}
			if(ptr->val == search)//double check
			{		
				flag = 1;
			}
			if(flag == 0)//not found
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;
			}//found
			else if(flag == 1)//removing a node
			{
				if(ptr==head)
				{
					head = ptr->right;
					head->left = NULL;
					free(ptr);
				}
				else
				{
					prev = ptr->left;
					next = ptr->right;
					if(prev!=NULL)
						prev->right = next;
					if(next!=NULL)
						next->left = prev;
				}
			}
			return head;
		}
	}
	else if(sel == 4)
	{
		return head;
	}
	else
	{
		printf("Enter proper value.\nPress Enter to go back to main menu\n");
		getch();
		return head;
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
		while(ptr->right!=NULL)
		{
			printf("|%d| --> ",ptr->val);
			ptr = ptr->right;
		}
		printf("|%d| \n",ptr->val);
		printf("------------------------------------\n");
	}
	printf("\nPress any key to continue to main menu.\n");
	getch();
}


