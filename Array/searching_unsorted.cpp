// Searching in Unsorted array.

#include<iostream>
using namespace std;


// int searching(int a[] , int n , int key)
// {
//     for (int i = 0 ; i < n ; i++)
//     {
//         if(a[i] == key)
//             return i;
//     }

//     return -1;
// }


// int main()
// {
//     int  a[5] = {2 , 3, 1 ,6, 8};

//     int idx = searching(a , 5 , 1);

//     if(idx != -1)
//         cout<<"The index is = "<<idx ;
//     else{
//         cout<<"Not found in array";
//     }  

//     return 0;      
// }


// Insertion in Unsorted array . 

// int insert_inarray(int a[] , int capicity , int n , int key)
// {
//     if(n >= capicity)
//         return -1;
//     else if(n < capicity)
//     {
//         a[n] = key;
//     } 

//     return n+1;   
// }



// int main()
// {
//     int a[10]  = {4,2,7,1,9};

//     int capicity= sizeof(a)/sizeof(int);
//     int n = 5;
//     int key = 5;

//     n = insert_inarray(a , capicity , n , key);

//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<< a[i] << " ";
//     }
//     return 0;
// }

// deletion in an array(Unsorted)


int search(int a[] , int n , int key)
 {
     for (int i = 0 ; i < n ; i++)
    {
         if(a[i] == key)
             return i;
    }

     return -1;
}


int deletion(int a[] ,int n ,int key)
{
    int idx = search(a , n ,key);

    if(idx == -1)
        return -1;
    else{

        for(int j = idx+1 ; j < n; j++)
        {
            a[j-1] = a[j] ;
        }
        return n-1;
    }    
}

int main()
{
    int a[] = {9 , 4, 2, 5 ,1};
    int n = sizeof(a) / sizeof(int);
    
    int key = 2;

    n = deletion(a , n , key);

    for(int i = 0 ; i < n ; i++)
    {
        cout<< a[i] << " ";
    }
    return 0;

}