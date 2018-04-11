#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void heapsort(int*,int);
void heapify(int*,int,int);

int main()
{
	int n;
	cout<<"Enter number of elements: "<<endl;
	cin>>n;
	int* arr = (int *)malloc(n * sizeof(int));
	cout<<"Enter the elements of array."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n);
	cout<<"\nThe sorted Array is "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void heapsort(int* x,int n)
{
	int temp;
	for (int i=n/2-1;i>=0;i--)
	{
		heapify(x, n, i);
	}
	
	for (int i=n-1; i>=0; i--)
    {
    	temp = x[0];
    	x[0] = x[i];
    	x[i] = temp;
 
        heapify(x, i, 0);
    }
	
}

void heapify(int *x,int n,int t)
{
	int largest = t,temp; 
    int l = 2*t+1; 
    int r = 2*t+2;  
 
    if ((l<n)&&(x[l]>x[largest]))
    {
    	largest = l;
    }
 
    if ((r<n)&&(x[r]>x[largest]))
    {
    	largest = r;
    }
 
    if (largest!=t)
    {
        temp = x[t];
        x[t] = x[largest]; 
        x[largest] = temp;
 
        heapify(x, n, largest);
    }
}
