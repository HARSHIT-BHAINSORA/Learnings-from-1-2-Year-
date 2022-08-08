#include<iostream>
using namespace std;

void Insertion(int *ptr , int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int curr = ptr[i];
       
        int j = i-1;

        while(curr < ptr[j] && j >=0)
        {
            ptr[j+1] = ptr[j];
            j--;
        }
        ptr[j+1] = curr;
    }

}
    
int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }

    for(int i = 0 ; i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    Insertion(a,n);

    for(int i = 0 ; i < n ;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}