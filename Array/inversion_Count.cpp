#include<iostream>
using namespace std;
int merge(int a[] , int temp[] , int left , int right  , int mid);
int merge_sort(int a[] ,int temp[] ,int left , int right);

int merge(int a[] , int temp[] , int left , int right  , int mid)
{
   
    int inver_count = 0;
    
    int i = left;
    int j = mid;
    int k = left;

    while((i <= mid-1) && (j <=right))
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
         
        }
        else
        {
            temp[k++] = a[j++];

            inver_count = inver_count + (mid-i);
           

        } 
    }
    
    while(i <= mid-1)
    {
        temp[k++] = a[i++];
    }
    while(j<=right)
    {
        temp[k++] = a[j++];
    }

    for(i = left ; i <= right ; i++)
    {
        a[i] = temp[i];
    }

    return inver_count;
}


int merge_sort(int a[] ,int temp[] ,int left , int right)
{
    int mid , inver = 0 ;
    

    if( right > left)
    {
        mid = (left + right)/2;
                                                             
        inver += merge_sort(a , temp , left, mid);  // left subarray 
        inver += merge_sort(a , temp , mid+1 ,right); // right subarray

        inver += merge(a , temp , left , right ,mid+1); // **** mid + 1 
    }
   
    return inver;
}




int main()
{
    int a[] = { 1, 20, 6, 4, 5 };
    int size = sizeof(a) / sizeof(a[0]);
  

    int temp[size];

    int ans =  merge_sort(a , temp , 0 ,size-1);

    cout<< ans;
    return 0;
}