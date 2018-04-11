#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct node
{
	int pow;
	int coeff;
	struct node *next;
}Node;

int power = 0,coefficient = 0;

//declaring heads of all 3 linked lists
Node *head1 = NULL;
Node *head2 = NULL;
Node *head3 = NULL;
Node *ptr123 = NULL;
//declaring functions
struct node *newTerm(struct node*);
struct node *insertAndSort(struct node*);
struct node *AddPoly(struct node*,struct node*,struct node*);
void display(struct node*);

int main()
{
	int n1,n2;
    cout<<"Enter the number of terms in equation 1"<<endl;
    cin>>n1;
    cout<<"Enter the number of terms in equation 2"<<endl;
    cin>>n2;
    cout<<"Enter the values for equation 1"<<endl;
    for(int i=0;i<n1;i++)
    {
        head1 = insertAndSort(head1);
        display(head1);
    }
    cout<<"\nEnter the values for equation 2"<<endl;
    for(int i=0;i<n2;i++)
    {
        head2 = insertAndSort(head2);
        display(head2);
    }
    display(head1);
    cout<<"\n\nLIST 2\n"<<endl;
    display(head2);

	cout<<"The added polynomial is :-"<<endl;
	head3 = AddPoly(head1,head2,head3);
	display(head3);
}

struct node *newTerm(struct node *head)
{
	Node *newnode, *ptr, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\n\n\nEnter the coefficient and power of a term to be inserted:\n");
	scanf("%d %d",&coefficient,&power);
	newnode->coeff = coefficient;
	newnode->pow = power;
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	else
	{
		ptr = newnode;
		return ptr;
	}
}

struct node *insertAndSort(struct node *head)
{
	int flag = 0,i=0;
	if(head==NULL)
	{
		head = newTerm(head);
		head->next = NULL;
		return head;
	}
	else
	{
		Node *temp, *ptr, *previous;
		temp = head;
		ptr = newTerm(head);
		if(power>temp->pow)
		{
			head = ptr;
			ptr->next = temp;
			return head;
		}
		else
		{
			do
			{
				if(temp->pow == power)
	            {
	                temp->coeff = temp->coeff + coefficient;
	                flag = 1;
	                return head;
	            }
				else
				{
					previous = temp;
					temp = temp->next;
				}
			}while((temp!=NULL)&&(power<=temp->pow));
			if(flag==0)
			{
				ptr->next = previous->next;
	            previous->next = ptr;
	            return head;
			}
		}
	}
}

struct node* AddPoly(struct node* head1,struct node* head2,struct node* head3)
{
	Node *temp1, *temp2, *newnode, *temp3;
	temp1 = head1;
	temp2 = head2;
	temp3 = head3;
	int i=0;
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->pow==temp2->pow)
		{
			if(head3==NULL)
			{
				newnode = (struct node*)malloc(sizeof(struct node));
				head3 = newnode;
				newnode->pow = temp1->pow;
				newnode->coeff = temp1->coeff + temp2->coeff;
				newnode->next = NULL;
				temp3 = newnode;
			}
			else
			{
				newnode = (struct node*)malloc(sizeof(struct node));
				newnode->next = NULL;
				newnode->pow = temp1->pow;
				newnode->coeff = temp1->coeff + temp2->coeff;
				temp3->next = newnode;
				temp3 = temp3->next;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
		{
			if(temp1->pow>temp2->pow)
			{
				newnode = (struct node*)malloc(sizeof(struct node));
				if(head3==NULL)
				{
					head3 = newnode;
					temp3 = head3;
				}
				newnode->next = NULL;
				newnode->pow = temp1->pow;
				newnode->coeff = temp1->coeff;
				temp3->next = newnode;
				temp3 = temp3->next;
				temp1 = temp1->next;				
			}
			else
			{
				newnode = (struct node*)malloc(sizeof(struct node));
				if(head3==NULL)
				{
					head3 = newnode;
					temp3 = head3;
				}
				newnode->next = NULL;
				newnode->pow = temp2->pow;
				newnode->coeff = temp2->coeff;
				temp3->next = newnode;
				temp3 = temp3->next;
				temp2 = temp2->next;
			}
		}
	}
	
	while(temp1!=NULL)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->pow = temp1->pow;
		newnode->coeff = temp1->coeff;
		temp3->next = newnode;
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	
	while(temp2!=NULL)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->pow = temp2->pow;
		newnode->coeff = temp2->coeff;
		temp3->next = newnode;
		temp3 = temp3->next;
		temp2 = temp2->next;
	}
	return head3;
}

void display(struct node *head)
{
	//system("cls");
	Node *ptr;
	ptr = head;
	printf("\n\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	while(ptr->next!=NULL)
	{
		printf("|%d %d| --> ",ptr->coeff,ptr->pow);
		ptr = ptr->next;
	}
	printf("|%d %d| --> NULL \n",ptr->coeff,ptr->pow);
	printf("-------------------------------------------------------------------------------------------------------\n");
}
