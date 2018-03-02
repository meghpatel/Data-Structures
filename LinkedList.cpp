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

int nullflag=0;
struct node *head = NULL;
//All the function definitions
int menu();
void display(struct node*); 
struct node *newNode(struct node*);
struct node *insertAtBeg(struct node*); 
struct node *insertAtEnd(struct node*); 
struct node *insertAfter(struct node*); 
struct node *insertBefore(struct node*); 
struct node *deleteAtBeg(struct node*); 
struct node *deleteAtEnd(struct node*); 
struct node *deleteAfter(struct node*); 
struct node *deleteAt(struct node*); 


int main()
{
	int r=menu();
	return r;
}

int menu()
{
	system("cls");
	fflush(stdin);
	printf("Select your operation\n");
	printf("1.Insertion at beginning\n2.Insertion at end\n3.Insertion after a value\n");
	printf("4.Insertion before a value\n5.Deletion at beginning\n6.Deletion at end\n");
	printf("7.Deletion after a value\n8.Deletion at a value\n9.Exit\n");
	int choice=0;
	scanf("%d",&choice);
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
			Node *temp1;
			temp1 = insertAfter(head);
			if(temp1 == NULL)
			{
				while(temp1 == NULL)
					temp1 = insertAfter(head);
				head = temp1;
				display(head);
				menu();
			}
			else
			{
				head = temp1;
				display(head);
				menu();
			}
			break;
		}
		case 4:
		{
			Node *temp1;
			temp1 = insertBefore(head);
			if(temp1 == NULL)
			{
				while(temp1 == NULL)
					temp1 = insertBefore(head);
				head = temp1;
				display(head);
				menu();
			}
			else
			{
				head = temp1;
				display(head);
				menu();
			}
			break;
		}
		case 5:
		{
			head = deleteAtBeg(head);
			if(head==NULL)
			{
				menu();
			}
			else
			{
				display(head);
				menu();
			}
			break;
		}
		case 6:
		{
			head = deleteAtEnd(head);
			if(head==NULL)
			{
				menu();
			}
			else
			{
				display(head);
				menu();
			}
			break;
		}
		case 7:
		{
			if(head==NULL)
			{
				cout<<"Empty Linked list.\nExiting to main menu."<<endl;
				getch();
				menu();
				break;
			}
			else
			{
				Node *temp1;
				temp1 = deleteAfter(head);
				if(temp1 == NULL)
				{
					while(temp1 == NULL)
						temp1 = deleteAfter(head);
					head = temp1;
					display(head);
					menu();
				}
				else
				{
					head = temp1;
					display(head);
					menu();
				}
				break;
			}
		}                 
		case 8:
		{
			if(head==NULL)
			{
				cout<<"Empty Linked list.\nExiting to main menu."<<endl;
				getch();
				menu();
				break;
			}
			else
			{
				Node *temp1;
				temp1 = deleteAt(head);
				if(temp1 == NULL)
				{
					while(temp1 == NULL)
					{
						printf("Bye");
						temp1 = deleteAt(head);	
					}
					head = temp1;
					display(head);
					menu();
				}
				else
				{
					head = temp1;
					display(head);
					menu();
				}
			}
			break;
		}
		case 9:
		{
			return 0;
			break;
		}
		default:
		{
			cout<<"\nEnter from the given choices"<<endl;
			getch();
			menu();		
		}
	}	
}

struct node *newNode(struct node *head)
{
	Node *newnode, *ptr;
	newnode = (struct node*)malloc(sizeof(Node));
	printf("Enter the data to be inserted:\n");
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

struct node *insertAfter(struct node *head)
{
	cout<<"Enter the value after which you want to enter new node:"<<endl;
	int k;
	cin>>k;
	if(head==NULL)
	{
		cout<<"\nThe list is empty. Do you want to add at beginning?"<<endl;
		cout<<"Press y for yes"<<endl;
		char confirm;
		cin>>confirm;
		if(confirm=='y'||confirm=='Y')
		{
			head = newNode(head);
			head->next = NULL;
			return head;
		}
		/*else
		{
			cout<<"You pressed No. Going to main menu"<<endl;
			getch();
			return NULL;
		}*/
	}
	else
	{
		int flag = 0,foundflag=0;
		Node *ptr=NULL,*n1,*pred=NULL;
		ptr = head;
		while((ptr!=NULL)&&(ptr->val!=k))
		{
			if(ptr->val==k)
			{
				foundflag=1;
			}
			flag = 1;
			pred = ptr;
			ptr = ptr->next;
		}
		if(pred==NULL)
		{
			if(ptr->val==k)
			{
				
			}
			else
			{
				system("cls");
				cout<<"Search not found"<<endl;
				cout<<"1.Change your search\n2.MainMenu"<<endl;
				int c1;
				cin>>c1;
				if(c1==1)
				{
					return NULL;
				}
				else
				{
					cout<<"Press Enter to go to main menu."<<endl;
					return head;
				}	
			}
		}
		if(ptr==NULL&&flag==1&&foundflag!=1)
		{
			system("cls");
			cout<<"Search not found"<<endl;
			cout<<"1.Change your search\n2.MainMenu"<<endl;
			int c1;
			cin>>c1;
			if(c1==1)
			{
				return NULL;
			}
			else
			{
				cout<<"Press Enter to go to main menu."<<endl;
				return head;
			}
		}
		else
		{
			/*printf("Yes\n");
			getch();*/
			/*printf("%d\n",ptr->val);
			getch();*/
			n1 = newNode(head);
			n1->next = ptr->next;
			ptr->next = n1;
			return head;
		}
	}
}

struct node *insertBefore(struct node *head)
{
	cout<<"Enter the value after which you want to enter new node:"<<endl;
	int k;
	cin>>k;
	if(head==NULL)
	{
		cout<<"\nThe list is empty. Do you want to add at beginning?"<<endl;
		cout<<"Press y for yes"<<endl;
		char confirm;
		cin>>confirm;
		if(confirm=='y'||confirm=='Y')
		{
			head = newNode(head);
			head->next = NULL;
			return head;
		}
		/*else
		{
			cout<<"You pressed No. Going to main menu"<<endl;
			getch();
			return NULL;
		}*/
	}
	else
	{
		int flag = 0,foundflag=0;
		Node *ptr=NULL,*n1,*pred=NULL;
		ptr = head;
		while((ptr!=NULL)&&(ptr->val!=k))
		{
			if(ptr->val==k)
			{
				foundflag=1;
			}
			flag = 1;
			pred = ptr;
			ptr = ptr->next;
		}
		if(pred==NULL)
		{
			if(ptr->val==k)
			{
				
			}
			else
			{
				system("cls");
				cout<<"Search not found"<<endl;
				cout<<"1.Change your search\n2.MainMenu"<<endl;
				int c1;
				cin>>c1;
				if(c1==1)
				{
					return NULL;
				}
				else
				{
					cout<<"Press Enter to go to main menu."<<endl;
					return head;
				}	
			}
		}
		if(ptr==NULL&&flag==1&&foundflag!=1)
		{
			system("cls");
			cout<<"Search not found"<<endl;
			cout<<"1.Change your search\n2.MainMenu"<<endl;
			int c1;
			cin>>c1;
			if(c1==1)
			{
				return NULL;
			}
			else
			{
				cout<<"Press Enter to go to main menu."<<endl;
				return head;
			}
		}
		else
		{
			if(ptr==head)
			{
				head = insertAtBeg(head);
				return head;
			}
			else
			{
				n1 = newNode(head);
				n1->next = pred->next;
				pred->next = n1;
				return head;
			}	
		}
	}
}

struct node *deleteAtBeg(struct node *head)
{
	if(head==NULL)
	{
		cout<<"Oops! Already Empty!\nPress Enter for main menu.";
		getch();
		return NULL;
	}
	else
	{
		Node *ptr;
		ptr = head;
		head = ptr->next;
		free(ptr);
		if(head==NULL)
		{
			printf("Hello");
			system("cls");
			printf("\n\n------------------------------------\n");
			printf("NULL");
			printf("\n------------------------------------\n");
			getch();
		}
		return head;
	}
}

struct node *deleteAtEnd(struct node *head)
{
	if(head==NULL)
	{
		cout<<"Oops! Already Empty!\nPress Enter for main menu.";
		getch();
		return NULL;
	}
	else
	{
		/*Node *ptr;
		ptr = head;
		head = ptr->next;
		free(ptr);*/
		Node *ptr,*pred=NULL;
		ptr = head;
		if(head->next==NULL)
		{
			system("cls");
			printf("\n\n------------------------------------\n");
			printf("NULL");
			printf("\n------------------------------------\n");
			getch();
			return NULL;
		}
		while(ptr->next!=NULL)
		{
			pred = ptr;
			ptr = ptr->next;
		}
		pred->next=NULL;
		free(ptr);
		return head;
	}
}

struct node *deleteAfter(struct node *head)
{
	cout<<"Enter the value after which you want to delete:"<<endl;
	int k;
	cin>>k;
	
		int flag = 0,foundflag=0;
		Node *ptr=NULL,*n1,*pred=NULL;
		ptr = head;
		//pred = ptr;
		while((ptr!=NULL)&&(ptr->val!=k))
		{
			if(ptr->val==k)
			{
				foundflag=1;
			}
			flag = 1;
			pred = ptr;
			ptr = ptr->next;
		}
		if(pred==NULL)
		{
			if(ptr->val==k)
			{
				
			}
			else
			{
				system("cls");
				cout<<"Search not found"<<endl;
				cout<<"1.Change your search\n2.MainMenu"<<endl;
				int c1;
				cin>>c1;
				if(c1==1)
				{
					return NULL;
				}
				else
				{
					cout<<"Press Enter to go to main menu."<<endl;
					return head;
				}	
			}
		}
		if(ptr==NULL&&flag==1&&foundflag!=1)
		{
			system("cls");
			cout<<"Search not found"<<endl;
			cout<<"1.Change your search\n2.MainMenu"<<endl;
			int c1;
			cin>>c1;
			if(c1==1)
			{
				return NULL;
			}
			else
			{
				cout<<"Press Enter to go to main menu."<<endl;
				return head;
			}
		}
		else
		{
			if(ptr->next==NULL)
			{
				printf("\nThere is no Node After that\n");
				cout<<"1.Change your search\n2.MainMenu"<<endl;
				int c1;
				cin>>c1;
				if(c1==1)
				{
					return NULL;
				}
				else
				{
					cout<<"Press Enter to go to main menu."<<endl;
					return head;
				}
			}
			else
			{
				n1 = ptr->next;
				ptr->next = ptr->next->next;
				ptr = n1;
				free(ptr);
				if(head==NULL)
				{
					system("cls");
					printf("\n\n------------------------------------\n");
					printf("NULL");
					printf("\n------------------------------------\n");
					getch();
				}
				return head;
			}
		}
}

struct node *deleteAt(struct node *head)
{
	cout<<"Enter the value at which you want to delete:"<<endl;
	int k;
	cin>>k;
	
		int flag = 0,foundflag=0;
		Node *ptr=NULL,*n1,*pred=NULL;
		ptr = head;
		//pred = ptr;
		while((ptr!=NULL)&&(ptr->val!=k))
		{
			if(ptr->val==k)
				foundflag=1;
			flag = 1;
			pred = ptr;
			ptr = ptr->next;
		}
		if(pred==NULL)
		{
			if(ptr->val==k)
			{
				//printf("Hi");
				//nullflag = 1;
				if(ptr->next==NULL)
				{
					printf("Hi");
					getch();
					head = deleteAtBeg(head);
					return head;
				}
				head = deleteAtBeg(head);
				return head;
			}
			else
			{
				system("cls");
				cout<<"Search not found"<<endl;
				cout<<"1.Change your search\n2.MainMenu"<<endl;
				int c1;
				cin>>c1;
				if(c1==1)
				{
					return NULL;
				}
				else
				{
					cout<<"Press Enter to go to main menu."<<endl;
					return head;
				}	
			}
		}
		if(ptr==NULL&&flag==1&&foundflag!=1)
		{
			system("cls");
			cout<<"Search not found"<<endl;
			cout<<"1.Change your search\n2.MainMenu"<<endl;
			int c1;
			cin>>c1;
			if(c1==1)
			{
				return NULL;
			}
			else
			{
				cout<<"Press Enter to go to main menu."<<endl;
				return head;
			}
		}
		else
		{
			/*printf("%d %d",pred->val,ptr->val);
			getch();*/
			pred->next = ptr->next;
			free(ptr);
			if(head==NULL)
				{
					//nullflag=1;
					/*printf("Good");
					getch();*/
					system("cls");
					printf("\n\n------------------------------------\n");
					printf("NULL");
					printf("\n------------------------------------\n");
					getch();
				}
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
