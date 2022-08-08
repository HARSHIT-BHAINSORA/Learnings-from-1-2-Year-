#include<iostream>
using namespace std;

// void missing_number( int a[] , int n)
// {
//     int x1 = a[0];
//     int x2 = 0;

//     for(int i = 1 ; i < n ; i++)
//     {
//         x1 = x1 ^ a[i];
//     }

//     for(int i = 1 ; i <= n ; i++)
//     {
//         x2 = x2 ^ i;
//     }

//     cout<<(x1 ^ x2) ;
// }


void missing_number(int a[] , int n)
{
    int total = (n*(n+1))/2;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + a[i];
    }
    cout<<(total - sum);
}

int main()
{
    int a[4] = {1 , 2 , 4};

    missing_number(a,4);
    return 0;
}
