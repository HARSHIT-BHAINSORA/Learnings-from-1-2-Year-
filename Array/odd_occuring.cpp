// a[] = {3,4,3,2,4,3,2,4,3}  o/p = 4


#include<iostream>
using namespace std;

// void odd_occuring(int a[] , int n)
// {
    
//     for(int i = 0 ; i < n ; i++)
//     {
//         int count =0 ;
//         for(int j = 0 ; j < n ; j++)
//         {
//             if(a[i] == a[j])
//                 count++;
//         }

//         if(count % 2 != 0)
//             {
//                 cout<<a[i];
//                 return ;
//             } 

//     }
// }

// EOX = ^ - 1. x ^ x = 0  2. x ^ 0 = x
//  a[] = {3,4,3,2,4,3,2,4,3}


void odd_occuring(int a[] , int n)
{
    int res = 0;
    for(int i = 0 ; i < n ; i++)
    {
        res = res ^ a[i];
    }

    cout<<res;
}


int main()
{
    int a[9] = {3,4,3,2,4,3,2,4,3};

    odd_occuring(a , 9);
    return 0; 
}