#include<iostream>
#include<stdlib.h>

using namespace std;

int binarysearch(int*,int);

int main()
{
	int r,result;	
	
	int n,temp,min,start,end,mid,search,flag=0,index;
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

	
	do{
		result = binarysearch(arr,n);
	
		if(result==-1)
		{
			cout<<"value not found"<<endl;
		}
		else
		{
			cout<<"The value found at index: "<<result<<endl;
		}
		
		cout<<"/nDo you want to continue?"<<endl;
		cin>>r;
	}while(r!=0);
	
	
}

int binarysearch(int* arr,int n)
{
	int search;
	cout<<"\nEnter search term:"<<endl;
	cin>>search;


	int start = 0;
	int end = n-1;
	int mid,flag=0,index;
	
	while(start<=end)
	{
		
		mid = (start+end)/2;
		
		if(arr[mid] == search)
		{
			flag = 1;
			index = mid;
			return index;
		}
		else if(search>arr[mid])
		{
			start = mid + 1;
		}
		else 
		{
			end = mid - 1;
		}
	}
	return -1;
}
