// a1[] = {3, 5 , 9, 10 , 11}      

// a2[] = { 1 , 2 , 4 , 6}  

#include<iostream>
using namespace std;



void merge_two(int a1[] , int a2[] , int n , int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a1[i] > a2[0])
        {
            int temp = a1[i];
            a1[i] = a2[0];
            a2[0] = temp;
        }
        int first = a2[0];
        int k;
        
        for( k = 1 ; k < m && first > a2[k]; k++)
        {
            a2[k-1] = a2[k];
        }
        a2[k-1] = first;
    } 
    
   
}


int main()
{
    int a1[5] = {3, 5 , 9, 10 , 11};
    int a2[4] = {1 ,2 ,4 ,6};

    merge_two(a1 ,a2 , 5 , 4);
    
     for(int i = 0 ; i < 5; i++)
    {
        cout<<a1[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < 4 ; i++)
    {
        cout<<a2[i]<<" ";
    }
    return 0;
}


