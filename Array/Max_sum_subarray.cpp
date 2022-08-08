// a[] = { 2,-1, 6 ,-4 ,3 ,1}  o/p = 7
// i = element , j = ranging ,  k = print/ sum;

#include<iostream>
using namespace std;

void max_sumsubarray(int a[] , int n)
{ 
    int max =0;
    
    for(int i = 0 ; i < n ; i++)
    { 
        int sum = 0;
        for(int j = i ; j < n ; j++)
        {    
            sum = sum + a[j]; 

                if(max < sum)
                    max = sum;
            
        }
    }

    cout<<max;
}



int main()
{
    int a[6] = { 2,-1, 6 ,-4 ,3 ,1};

    max_sumsubarray(a , 6);
    return 0;

}