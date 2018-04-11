#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

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
    }
    display(head1);
    cout<<"\n\nLIST 2\n"<<endl;
    display(head2);	
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
	/*else
	{
		Node *ptr,*n1;
		ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		n1 = newTerm(head);
		ptr->next = n1;
		ptr = n1;
		n1->next = NULL;
		return head;
	}*/
	else
	{
		Node *temp, *ptr, *previous;
		temp = head;
		ptr = newTerm(head);
		printf("temp= %d pow =%d\n",temp->pow,power);
		printf("why isn't it going into the loop?");
		if(head->next==NULL)
		{
			printf("It should come here only once\n");
			flag = 1;
			if(power>head->pow)
			{
				head = ptr;
				head->next = temp;
				temp->next = NULL;
				return head;
			}
			else if(head->pow == power)
			{
				head->coeff = head->coeff + coefficient;
				return head;
			}
			else
			{
				head->next = ptr;
				ptr->next = NULL;
				return head;
			}
		}
		if(power>head->pow)
		{
			printf("\n\n\nPow>head\n\n");
			head = ptr;
			ptr->next = temp;
			return head;
		}
		else
		{
			printf("\n\n\nELSE\n\n");
			while((power<=temp->pow)&&(temp->next!=NULL))
			{
				printf("LOOP %d",i);
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
				if(temp->next==NULL)
				{
					printf("NULL");
				}
				i++;
			}
			if(flag==0)
			{
				ptr->next = temp->next;
				temp->next = ptr;
				return head;
			}
		}
	}
}

void display(struct node *head)
{
	//system("cls");
	Node *ptr;
	ptr = head;
	printf("\n\n");
	printf("------------------------------------\n");
	while(ptr->next!=NULL)
	{
		printf("|%d %d| --> ",ptr->coeff,ptr->pow);
		ptr = ptr->next;
	}
	printf("|%d %d| --> NULL \n",ptr->coeff,ptr->pow);
	printf("------------------------------------\n");
	getche();
}
