#include<iostream>
using namespace std;

// void rotation(int a[] , int n , int d)
// {
//     for(int i = 0 ; i < d; i++)
//     {
//         int temp = a[0];
//         for(int j = 1 ; j < n ; j++)
//         {
//             a[j-1] = a[j];
//         }
//         a[n-1] = temp;
//     }
// }


  //      rev B           rev A
// a[] = { 6, 5, 4 , 3 , 2 , 1}

void reverse(int a[] , int st , int end)
{
    while(st <= end)
    {
        int temp = a[st];
        a[st] = a[end];
        a[end] = temp;
        st++;
        end--;
    }
}

void rotation(int a[] , int n , int d)
{
    if(d == 0)
        return;

    if(d > n)
    {
        d = d /n;    // n = 5 , d = 6  6 /5 = 1;
    } 

    reverse(a , 0 , d-1);
    reverse(a , d , n-1);
    reverse(a , 0 , n-1);   
}



int main()
{               // A     B        -->(rev)      B               A
    int a[6] = {1 , 2 , 3 , 4 , 5 , 6};   // {3 , 4 , 5 , 6, 1 , 2 }
    int d = 2;

    rotation(a,6,d);
    cout<<"AFTER rotation :- ";
    for(int i = 0 ; i < 6 ; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0; 
}