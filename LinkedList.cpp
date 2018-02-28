#include<iostream>
#include<stdio.h>
#include<stdlib.h>

//creating a structure for LinkedList

struct node
{
	int val;
	struct node *next;	
};

struct node *head = NULL;

struct node *newLL(struct node*); 
struct node *display(struct node*); 
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
	
}
