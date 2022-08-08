#include<iostream>
using namespace std;

void selection(int *ptr, int n)
{
    for(int i = 0 ; i <n-1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(ptr[i] > ptr[j])
            {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}


int main()
{
    int n;
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

    selection(a,n);

    for(int i = 0 ; i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}