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
	printf("4.Before a value\n");
	printf("5.Exit to menu\n");
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
		printf("\n\n\nEnter the value after which you want to INSERT a Node\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1;
		ptr = head;
		if(ptr->next == head)//if only one node
		{
			if(ptr->val == search)//if the only node same as the query
			{
				n1 = newNode(head);
				ptr->next = n1;
				n1->next = head;
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
			while(ptr->next!=head&&ptr->val!=search)//traversing
			{
				ptr = ptr->next;	
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
			else if(flag == 1)//adding a node
			{
				n1 = newNode(head);
				n1->next = ptr->next;
				ptr->next = n1;
				return head;
			}
		}
	}
	else if(sel == 4)
	{
		printf("\n\n\nEnter the value before which you want to INSERT a Node\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1,*pred=NULL;
		ptr = head;
		if(ptr->next == head)//if only one node
		{
			if(ptr->val == search)//is the node same as we are searching
			{
				n1 = newNode(head);
				n1->next = head;
				ptr->next = n1;
				head = n1;
				return head;		
			}
			else//Node not found
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;	
			}
		}
		else//searching in multiple nodes
		{
			while(ptr->next!=head&&ptr->val!=search)//traversing 
			{
				pred = ptr;
				ptr = ptr->next;	
			}
			if(ptr->val == search)//checking once again
			{
				flag = 1;
			}
			if(flag == 0)
			{
				printf("\n\n\n\nSEARCH VALUE NOT FOUND\nPress Enter\n");
				getch();
				return head;
			}
			else if(flag == 1)//found the result and adding the node
			{
				n1 = newNode(head);
				n1->next = pred->next;
				pred->next = n1;
				return head;
			}
		}
	}
	else if(sel == 5)
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
	printf("3.After a value\n");
	printf("4.At a value\n");
	printf("5.Exit to main Menu\n");
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
		if(ptr->next == head)//if only one node
		{
			free(head);
			return NULL;
		}
		else//multiple nodes
		{
			temp = head;
			while(ptr->next!=head)//traversing
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
		if(ptr->next == head)//if only one node
		{
			free(ptr);
			return NULL;
		}
		else//multiple nodes
		{
			while(ptr->next!=head)//traversing
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
		printf("\n\n\nEnter the value after which you want to DELETE a Node\n\n\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1,*temp;
		ptr = head;
		if(ptr->next == head)//if only one node
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
			while(ptr->next!=head&&ptr->val!=search)//traversing
			{
				ptr = ptr->next;	
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
			else if(flag == 1)//deleting a node
			{
				if(ptr->next == head)//if search node is last then after last first node is deleted
				{
					temp = head;
					ptr->next = temp->next;
					head = temp->next;
					free(temp);
					return head;
				}
				else//search result not a last element
				{
					temp = ptr->next;
					ptr->next = temp->next;
					free(temp);
					return head;
				}
			}
		}
	}
	else if(sel == 4)
	{
		printf("\n\n\nEnter the value which you want to DELETE a Node\n\n\n");
		int search,flag = 0;
		scanf("%d",&search);
		Node *ptr,*n1,*temp,*pred=NULL;
		ptr = head;
		if(ptr->next == head)//if only one node
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
			while(ptr->next!=head&&ptr->val!=search)//traversing
			{
				pred = ptr;
				ptr = ptr->next;	
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
				if(ptr == head)//if the searched node is first
				{
					Node *temp = head;
					while(temp->next!=head)
					{
						temp = temp->next;
					}
					head = ptr->next;
					temp->next = head;
					free(ptr);
					return head;
				}
				else//search result not a last element
				{				
					pred->next = ptr->next;
					free(ptr);
					return head;
				}
			}
		}
	}
	else if(sel == 5)
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

