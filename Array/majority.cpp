// Majority : repeated elements which is geater than the size of an array.

#include<iostream>
using namespace std;

void majority(int a[] , int n)
{
    int maxcount = 0; 
    int ind=-1;
    for(int i = 0 ; i< n ; i++)
    {
        int count = 0 ;
        for(int j = 0; j < n ; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        if(count>maxcount){
            maxcount = count;
            ind = i;
        }

    }
    
    if(maxcount > n/2)
        cout<<a[ind];
    else
        cout<<"no  Majority element";    


}




int main()
{
    int a[9] = {3,3,4,2,4,4,2,4,4};

    majority(a , 9);

    return 0;
}