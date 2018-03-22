#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "LinkedListTemplate.cpp"
using namespace std;

Node *head1 = NULL;
Node *head2 = NULL;
Node *head3 = NULL;
Node *ptr123 = NULL;

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
        head1 = insertAtEnd(head1);
    }
    cout<<"\nEnter the values for equation 2"<<endl;
    for(int i=0;i<n2;i++)
    {
        head2 = insertAtEnd(head2);
    }
    display(head1);
    cout<<"\n\nLIST 2\n"<<endl;
    display(head2);
}



