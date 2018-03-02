#include<stdio.h>

typedef struct node 
{
	int val;
	struct node *next;
}Node;

Node *head = NULL;
void menu();
void display();
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
			head = insert(head);
			display();
			menu();
			break;
		}
		case 2:
		{
			
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
