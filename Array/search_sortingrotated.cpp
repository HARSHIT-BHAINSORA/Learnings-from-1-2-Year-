#include<iostream>
using namespace std;

int search (int arr[] , int st ,int end, int key)
{
    
    if(st <= end)
    {
        int mid = (st+end)/2;
        
        if(arr[mid] == key)
            return mid;

        if(arr[st] < arr[mid])
        {
            if(arr[st] <= key && arr[mid] >= key)
                return search(arr , st , mid - 1 , key);
            else
                return search(arr , mid+1 , end , key);    
        }

        else{
            if(arr[mid] <= key && arr[end] >= key)
                return search(arr , mid+1 , end , key);
            else
                return search(arr , st , mid-1 , key);    
        }    
    }
    return -1;
}



int main()
{
    int arr[6] = {3 , 4 , 5 ,6 , 1 , 2};

    int idx = search(arr , 0 , 5 , 5);
    (idx == -1) ? cout<<"Not found" : cout<<idx;
    return 0 ;
}