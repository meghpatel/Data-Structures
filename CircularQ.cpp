#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#define N 5	
using namespace std;

int insert_q(int);
int delete_q();
void display(int);

int q[N];
int front=-1,rear=-1;

int mainmenu()
{
	system("cls");
	cout<<"Enter your choice\n1.Insert\n2.Delete\n3.Exit "<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter the number to be inserted:"<<endl;
			int val,r;
			cin>>val;
			r=insert_q(val);
			display(r);
			break;
		}
		case 2:
		{
			int r;
			r=delete_q();
			display(r);
			break;
		}
		case 3:
		{
			return 0;
			break;
		}
		default:
		{
			cout<<"Enter a proper choice."<<endl;
			mainmenu();
		}
	}
}

int main()
{
	mainmenu();
	return 0;
}

int insert_q(int val)
{
	if((front==rear+1)||(front==0&&rear==N-1))
	{
		return -1;
	}
	if(rear==-1&&front==-1)
	{
		front++;
	}
	rear=rear+1;
	rear=rear%N;
	q[rear]=val;
	return 0;
}

int delete_q()
{
	if(front==-1)
	{
		return -2;
	}
	if(front==rear)
	{
		return -3;
	}
	front++;
	front=front%N;
	return 0;
}

void display(int r)
{
	system("cls");
	if(r==-1)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else if(r==-2)
	{
		cout<<"Queue Underflow"<<endl;
	}
	else if(r==-3)
	{
		cout<<"Queue is now empty"<<endl;
		for(int i=0;i<10;i++)
		{
			q[i]=0;
		}
		front=-1;
		rear=-1;
	}//I changed Hey LOL
	else
	{
		if(front>rear)
		{
			for(int i=0;i<rear+1;i++)
			{
				printf("%d ",q[i]);
			}
			for(int i=front;i<N;i++)
			{
				printf("%d ",q[i]);
			}
		}
		else
		{
			for(int i=front;i<rear+1;i++)
			{
				printf("%d ",q[i]);
			}
		}
		printf("\n");
	}
	cout<<"\nPress any key to continue to main menu."<<endl;
	char contl;
	scanf(" %c",&contl);
	mainmenu();
}
