#include<iostream>
using namespace std;
# define NA -1

void place_atend(int a1[] , int size)
{
    cout<<size<<endl;
    int j = size-1;
    for(int i = size-1 ; i >= 0 ; i--)
    {
       if(a1[i] != NA)
        {
            a1[j] = a1[i];
            j--;
        }
    }

}



void merge (int a1[] , int a2[] , int m ,int n)
{
   
    int i = n; // {NA , NA , NA  ,NA , 2 , 7 ,10 };
    int j = 0 ;  
    int k = 0;

    while(k < (m+n))
    {
        if( (j == n) || (a1[i] <= a2[j] && i < m+n))
        {
            a1[k] = a1[i];
            k++;
            i++;
        }
        else
        {
            a1[k] = a2[j];
            j++;
            k++; 
        }
    }

}


int main()
{
    int n = 4;
    int m = 3;
    
    int a1[m] = {2 ,NA , 7 , NA , NA ,10 , NA};
    int a2[n] = {5 , 8 , 12 ,14};

    place_atend(a1 , (m+n));
    
    merge (a1 ,a2 , m ,n);

    for(int i = 0 ; i < (m+n) ; i++)
    {
        cout<< a1[i] << " ";
    }
    return 0 ;
}