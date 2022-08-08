// Leader in array those element whos right element is smaller than that.

#include<iostream>
using namespace std;

// int main()
// {
//     int a[5] = {11 , 4, 9 ,2 ,7};
//     int j;
    
//     for(int i = 0 ; i < 5 ; i++)
//     {
//         for( j = i+1; j < 5 ; j++)
//         {
//             if(a[i] <= a[j])
//                 break;
//         }
//         if(j == 5)
//             cout<<a[i]<<" ";
//     }

//     return 0;
// }

int main()
{
    int a[5] = { 11 , 4, 9 , 2, 7};
    int max = a[4];

    cout<< max <<" ";

    for(int i = 4; i >= 0 ; i--)
    {
        if(max < a[i])
        {
            max = a[i] ;
            cout<< max<< " ";
        }
    }

    return 0;
}