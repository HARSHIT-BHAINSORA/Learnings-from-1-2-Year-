#include<iostream>
using namespace std;

void merge_sort(int a1[] , int a2[] , int n , int m)
{
    int a3[n+m] ;

    int i = 0;
    int j = 0;
    int k = 0;
    int count = -1 ;
    while(count != (n+m)/2) 
    {
        if(a1[i] <= a2[j])
        {
            a3[k] = a1[i];
            k++;
            i++;
            count++;
        }
        else{
            a3[k] = a2[j];
            k++;
            j++;
            count++;
        }
    }

    cout<<count<<endl;


    // while(i != n)
    // {
    //     a3[k] = a1[i];
    //     k++;
    //     i++;
    // }

    // while(j != m)
    // {
    //     a3[k] = a2[j];
    //     k++;
    //     j++;
    // }

    // a3[n+m] = {1 , 2, 3, 4, 5 ,6 , 9, 10}

    // for(int i = 0 ; i < m+n ; i++)
    // {
    //     cout<< a3[i] << " ";
    // }
    // cout<<endl;
    
    int median;

    if((n+m)%2 == 0)
    {
        median = (a3[count] + a3[count-1])/2;
    }
    else{
        median = a3[count];
    }
    cout<<"Median is = " << median ;
}



int main()
{
    int n = 5 , m = 3;
    int a1[n] = {1 ,4 ,6 ,9 ,10};
    int a2[m] = {2 ,3 ,5};

    merge_sort(a1 , a2 ,n , m);
    return 0;
}