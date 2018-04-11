#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void quicksort(int*,int,int);
int partition(int*,int,int);

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
	quicksort(arr,0,n-1);
	cout<<"\nThe sorted Array is "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void quicksort(int *x,int start,int end)
{
	if(start<end)
	{
		int pivotIndex;
		pivotIndex = partition(x,start,end);
		quicksort(x,start,pivotIndex - 1);
		quicksort(x,pivotIndex + 1,end);
	}
}

int partition(int *x,int start,int end)
{
	int pivot = x[end],temp;
	int pIndex=start;
	for(int i=start;i<end;i++)
	{
		if(x[i]<=pivot)
		{
			temp = x[i];
			x[i] = x[pIndex];
			x[pIndex] = temp;
			pIndex++;
		}
	}
	temp = x[pIndex];
	x[pIndex] = x[end];
	x[end] = temp;
	return pIndex;
}
