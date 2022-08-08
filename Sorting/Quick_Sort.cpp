#include<iostream>
using namespace std;
int partition(int arr[] , int st , int end);
void quick_sort(int arr[] , int st , int end);
void swap(int arr[] , int a ,int b);

void swap(int arr[] ,int i ,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[] , int st , int end)
{
    int pivot = arr[end];
    int i = st-1;

    for(int j = st ; j < end ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr , i ,j);
        }
    }
    swap(arr , i+1,end);
    return i+1;
}

void quick_sort(int arr[] , int st , int end)
{
    if(st < end)
    {
        int pi = partition(arr , st , end);

        quick_sort(arr , st , pi-1);
        quick_sort(arr , pi+1 , end);

    }
}


int main()
{
    int arr[4] = {8,1,6,2};

    cout<<"Before Sorting"<<endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quick_sort(arr,0,3);

    cout<<"After Sorting"<<endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}