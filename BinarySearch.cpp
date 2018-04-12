#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int n,temp,min,start,end,mid,search;
	cout<<"Enter the number of elements in array"<<endl;
	cin>>n;
	int* arr = (int *)malloc(n * sizeof(int));
	cout<<"Enter the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	//sorting
	for(int i=0;i<n-1;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	
	cout<<"The sorted array is: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<"Enter search term:"<<endl;
	cin>>search;
	
	start = 0;
	end = n-1;
	for(int i=0;i<n;i++)
	{
		mid = (start+end)/2
		if()
	}
}
