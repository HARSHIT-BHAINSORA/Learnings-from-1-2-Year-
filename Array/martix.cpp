#include<iostream>
using namespace std;

int main()
{
    int n = 3;

    int arr[n][n] = {(1 , 2 , 3) , (3, 1 ,2) , (2 , 3 ,1)};
    
    for(int  i = 1 ; i <= n ; i++)
    {
        int j = 1;
        if(arr[i][i]  == j)
        {
            j++;
        }
    }
}