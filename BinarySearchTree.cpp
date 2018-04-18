#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

typedef struct node 
{
	int val;
	struct node *right;
	struct node *left;
}Node;

Node *root = NULL;

void menu();
struct node *newNode(int);
struct node *insertNode(struct node*,int);
struct node *deleteNode(struct node*,int);
void display();
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

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
			printf("\n\n\nEnter the data to be inserted:\n");
			int data;
			scanf("%d",&data);
			root = insertNode(root,data);
			menu();
			break;
		}
		case 2:
		{
			printf("\n\n\nEnter the data to be deleted:\n");
			int data;
			scanf("%d",&data);
			root = deleteNode(root,data);
			menu();
			break;
		}
		case 3:
		{
			display();			
			getch();
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

struct node *newNode(int data)
{
	Node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct node *insertNode(struct node* root,int data)
{
	if(root==NULL)
	{
		return newNode(data);
	}
	
	if(data<root->val)
	{
		root->left = insertNode(root->left,data);
	}
	else
	{
		root->right = insertNode(root->right,data);
	}
	
	return root;
}

struct node *deleteNode(struct node* root,int data)
{
	Node *ptr;
	if(root==NULL)
	{
		return root;
	}
	
	if(data<root->val)
	{
		root->left = deleteNode(root->left,data);
	}
	else if(data>root->val)
	{
		root->right = deleteNode(root->right,data);
	}
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
            free(root);
            return temp;
		}
		else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        while(ptr->left!=NULL)
		{
			ptr = ptr->left;
		}
		
		root->val = ptr->val;
		root->right = deleteNode(root->right, ptr->val);
	}
	
	return root;
}

void display()
{
	cout<<"Enter your choice for traversal:"<<endl;
	cout<<"1.Preorder\n2.Inorder\n3.Postorder\n";
	int res;
	cin>>res;
	switch(res)
	{
		case 1:
			{
				preorder(root);
				break;
			}
		case 2:
			{
				inorder(root);
				break;
			}
		case 3:
			{
				postorder(root);
			}
	}
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->val);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
    	printf("%d \n", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->val);
    }
}
