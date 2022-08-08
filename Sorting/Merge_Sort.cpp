#include<iostream>
using namespace std;

void merge(int arr[], int st ,int end , int mid);
void merge_sort(int arr[] , int st , int end);

void merge(int arr[], int st ,int end , int mid)
{
    int n1 = mid-st+1;
    int n2 = end-mid;

    int a[n1];
    int b[n2];

    for(int i = 0 ; i < n1 ; i++)
    {
        a[i] = arr[st+i];
    }

    for(int i = 0 ; i < n2 ; i++)
    {
        b[i] = arr[mid+1+i];
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int k = st; // imp ****

    while(ptr1 < n1 && ptr2 < n2)
    {
        if(a[ptr1] < b[ptr2] )
        {
            arr[k] = a[ptr1];
            k++ ;
            ptr1++;
        }
        else{
            arr[k] = b[ptr2];
            k++;
            ptr2++;
        }
    }

    while(ptr1 < n1)
    {
        arr[k] = a[ptr1];
        k++;
        ptr1++;
    }
     
    while(ptr2 < n2)
    {
        arr[k] = b[ptr2];
        k++;
        ptr2++;
    }
}

void merge_sort(int arr[] , int st , int end)
{
   if(st >= end)
    return ;

    int mid = (st + end)/2;

    merge_sort(arr,st,mid);
    merge_sort(arr,mid+1,end);
    
    merge(arr,st,end,mid);
}


int main()
{
    int arr[7] = {8,12,1,10,6,5,2};

    cout<<"Before Sorting"<<endl;
    for(int i = 0 ; i < 7 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    merge_sort(arr,0,6);

    cout<<"After Sorting"<<endl;
    for(int i = 0 ; i < 7 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}