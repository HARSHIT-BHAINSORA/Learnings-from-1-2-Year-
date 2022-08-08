#include<iostream>
using namespace std;

int find_max_sum(int a[] , int n)
{
    int inclu = a[0];
    int excl = 0;
    int new_excl;

    for(int i = 1 ; i < n ; i++)
    {
        new_excl = inclu > excl ? inclu : excl;

        inclu = excl + a[i];
        excl = new_excl;
    }
    return inclu > excl ? inclu : excl;
}


int main()
{
    int a[6] = {5 , 5, 10 , 40 , 50, 35};

    int max = find_max_sum(a , 6);

    cout<< max ;
    return 0;
}