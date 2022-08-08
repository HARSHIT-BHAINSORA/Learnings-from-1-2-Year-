#include <stdio.h>
void printHeap(int arr[], int size);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < n && arr[smallest] > arr[lchild])
        smallest = lchild;
    if (rchild < n && arr[smallest] > arr[rchild])
        smallest = rchild;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{
    int lastNode = (n / 2) - 1;

    for (int i = lastNode; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    printHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        printHeap(arr, n);
        heapify(arr, i, 0);
        printHeap(arr, n);
    }
}

void printHeap(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    int arr[] = {30, 20, 10, 60, 80, 90, 50};

    n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printHeap(arr, n);

    return 0;
}