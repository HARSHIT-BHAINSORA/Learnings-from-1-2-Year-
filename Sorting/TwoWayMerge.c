

#include <stdio.h>
#include <stdlib.h>
void mergeList(int arr[], int st, int end, int mid);

int min(int a, int b)
{
    return (a < b) ? a : b;
}

// iterative

void MergeSort(int arr[], int n)
{
    int curSize, leftStart;

    for (curSize = 1; curSize <= n - 1; curSize *= 2)
    {
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * curSize)
        {
            int mid = min(leftStart + curSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * curSize - 1, n - 1);

            mergeList(arr, leftStart, rightEnd, mid);
        }
    }
}

// merge Function...

void mergeList(int arr[], int st, int end, int mid)
{
    int i, j, k;
    int n1 = mid - st + 1;
    int n2 = end - mid;

    int larr[n1], rarr[n2];

    for (int i = 0; i < n1; i++)
    {
        larr[i] = arr[st + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rarr[j] = arr[mid + 1 + j];
    }

    i = 0, j = 0, k = st;

    while (i < n1 && j < n2)
    {
        if (larr[i] <= rarr[j])
        {
            arr[k] = larr[i];
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

int main()
{
    int arr[] = {1, 5, 4, 2, 8};

    MergeSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
