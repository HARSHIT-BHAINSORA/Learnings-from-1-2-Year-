#include<iostream>
using namespace std;

void max_subarray_sum(int a[] , int n)
{
    int maxsum = 0;
    int sum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + a[i];

        if(maxsum < sum)
            maxsum = sum;
        if(sum < 0)
            sum = 0;    
    }
    cout<<"Maximum Subarray sum is = " << maxsum ;
}


int main()
{
    int a[8] = {-2 , -3 , 4 , -1 ,-2 , 1 , 5 , -3};

    max_subarray_sum(a , 8);

    return 0;
}