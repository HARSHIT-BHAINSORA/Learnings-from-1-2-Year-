#include <stdio.h>

// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// void bubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// void insertSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int key = arr[i];
//         int j = i - 1;

//         while (key < arr[j] && j >= 0)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// // merging of two array

// void Merge(int arr[], int st, int end, int mid)
// {
//     int n1 = mid - st + 1;
//     int n2 = end - mid;

//     int larr[n1], Rarr[n2];

//     for (int i = 0; i < n1; i++)
//     {
//         larr[i] = arr[st + i];
//     }

//     for (int j = 0; j < n2; j++)
//     {
//         Rarr[j] = arr[mid + 1 + j];
//     }

//     int i = 0, j = 0, k = st;

//     while (i < n1 && j < n2)
//     {
//         if (larr[i] <= Rarr[j])
//         {
//             arr[k] = larr[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = Rarr[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1)
//     {
//         arr[k] = larr[i];
//         i++;
//         k++;
//     }

//     while (j < n2)
//     {
//         arr[k] = Rarr[j];
//         j++;
//         k++;
//     }
// }

// void MergeSort(int arr[], int st, int end)
// {
//     if (st >= end)
//         return;

//     int mid = (st + end) / 2;

//     MergeSort(arr, st, mid);
//     MergeSort(arr, mid + 1, end);

//     Merge(arr, st, end, mid);
// }

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {1, 5, 4, 2, 8};

    // selectionSort(arr, 5);

    // bubbleSort(arr, 5);

    // insertSort(arr , 5);

    // MergeSort(arr, 0, 4);

    QuickSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}