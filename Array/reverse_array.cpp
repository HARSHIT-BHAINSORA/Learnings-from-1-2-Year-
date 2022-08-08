#include<iostream>
using namespace std;

void reverse(int a[] , int n)
{
    for(int  i = 0 ; i <= n/2 ; i++)
    {
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}



int main()
{
    int a[5] = {3,2,7,0,8};

    reverse(a , 5);

    for(int i = 0 ; i < 5 ; i++)
    {
        cout<< a[i] << " ";
    }
    return 0;
}