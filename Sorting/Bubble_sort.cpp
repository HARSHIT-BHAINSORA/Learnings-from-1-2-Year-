#include<iostream>
using namespace std;

void Bubble_sort(int * ptr , int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        for(int  j = 0 ;  j <n-i ; j++)
        {
            if(ptr[j] > ptr[j+1])
            {
            int temp = ptr[j];
            ptr[j] = ptr[j+1];
            ptr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;

    int a[n];

    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }

    for(int i = 0 ; i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    Bubble_sort(a,n);

    for(int i = 0 ; i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}