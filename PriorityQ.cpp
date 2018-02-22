#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#define N 5	
using namespace std;

int insert_q(int,int);
int delete_q();
void display(int);

int q[5][N];
int front=-1,rear=-1;

int mainmenu()
{
	//system("cls");
	cout<<"Enter your choice\n1.Insert\n2.Delete\n3.Exit "<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter the number and it's priority: "<<endl;
			int val,r,pri;
			cin>>val>>pri;
			r=insert_q(val,pri);
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

int insert_q(int val,int pri)
{
	if((front[pri]==rear[pri]+1)||(front[pri]==0&&rear[pri]==N-1))
	{
		return -1;
	}
	if(rear[pri]==-1&&front[pri]==-1)
	{
		front++;
	}
	rear[pri]=rear[pri]+1;
	rear[pri]=rear[pri]%N;
	q[rear[pri]]=val;
	return 0;
}

int delete_q()
{
	if(front[pri]==-1)
	{
		return -2;
	}
	if(front[pri]==rear[pri])
	{
		return -3;
	}
	front[pri]++;
	front[pri]=front[pri]%N;
	return 0;
}

void display(int r)
{
	//system("cls");
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
	}
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
