#include <iostream>
using namespace std;

// int check_x(int a[] , int n ,int x)
// {
//     for(int i = 0 ; i < n ; i++)
//     {
//         for(int j = 0 ; j <n ; j++)
//         {
//             if(a[i]+a[j] == x){
//                 cout<<a[i]<<a[j];
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int a[5] = {0 , -1 , 2 , 3 , 1};
//     int x = -2;

//     if(check_x(a,5,x))
//         cout<< " founded.";
//     else{
//         cout<<"Not founded.";
//     }

//     return 0;
// }

// two pointer approach.(sorted array).

int check(int a[], int n, int x);
void sort(int a[], int n);

int check(int a[], int n, int x)
{

    int st = 0, end = n - 1;

    while (st < end)
    {
        cout << a[st] << "  " << a[end] << endl;

        if (a[st] + a[end] == x)
            return 1;
        else if (a[st] + a[end] < x)
            st++;
        else
            end--;
    }

    return 0;
}

void sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int cur = a[i];

        while (a[j] > cur && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}
int main()
{
    int a[9] = {10, 15, 20, 35, 40, 67, 83, 89, 94};
    int x = 107;

    sort(a, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }

    if (check(a, 9, x))
        cout << "Founded .";
    else
        cout << "Not Founded.";
    return 0;
}