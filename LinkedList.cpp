#include<iostream>
#include<stdio.h>
#include<stdlib.h>

//creating a structure for LinkedList

struct node
{
	int val;
	struct node *next;	
};

int main()
{
	struct node *newnode,*head;
	newnode = (struct node*)malloc(sizeof(node)); 
	head = newnode;
	newnode->val = 5;
	printf("%d",head->val);
	struct node *newnode1;
	newnode1 = (struct node*)malloc(sizeof(node));
	newnode1->val = 4;
	head->next = newnode1;
	printf("%d",head->next->val);
	printf("%d",newnode1->val);
}
