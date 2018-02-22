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
int front[5]={-1,-1,-1,-1,-1},rear[5]={-1,-1,-1,-1,-1};

int mainmenu()
{
	//system("cls");
	cout<<"Enter your choice\n1.Insert\n2.Delete\n3.Exit\n"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter the number and it's priority: \n"<<endl;
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
		front[pri]++;
	}
	rear[pri]=rear[pri]+1;
	rear[pri]=rear[pri]%N;
	int temp = rear[pri];
	q[pri][temp]=val;
	return 0;
}

int delete_q()
{
	/*if(front[pri]==-1)
	{
		return -2;
	}
	if(front[pri]==rear[pri])
	{
		return -3;
	}
	front[pri]++;
	front[pri]=front[pri]%N;
	return 0;*/
	int ctr=0;
	for(int i=0;i<5;i++)
	{
		if(front[i]==rear[i]&&front[i]!=-1)
		{
			front[i]=-1;
			rear[i]=-1;
			break;
		}
		else if((rear[i]!=-1)&&(front[i]!=-1))
		{
			ctr++;
			front[i]++;
			front[i]=front[i]%N;
			break;
		}
	}
	return 0;
	/*if(ctr==5)
	{
		return -2;
	}*/
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
		//cout<<"Queue Underflow"<<endl;
		cout<<"Queue is now empty/Underflow"<<endl;
	}
	else if(r==-3)
	{
		//cout<<"Queue is now empty"<<endl;
		/*for(int i=0;i<10;i++)
		{
			q[i]=0;
		}*/
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			if (front[i]==rear[i]&&front[i]==-1)
			{
				printf("******\n");
			}
			else if(front[i]>rear[i])
			{
				for(int j=0;j<rear[i]+1;j++)
				{
					printf("%d ",q[i][j]);
				}
				for(int j=front[i];j<N;j++)
				{
					printf("%d ",q[i][j]);
				}
			}
			else
			{
				for(int j=front[i];j<rear[i]+1;j++)
				{
					printf("%d ",q[i][j]);
				}
			}
			printf("\n");
		}
		/*for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				printf("%d ",q[i][j]);
			}
			printf("\n");
		}*/
	}
	cout<<"\nPress any key to continue to main menu."<<endl;
	char contl;
	scanf(" %c",&contl);
	mainmenu();
}
