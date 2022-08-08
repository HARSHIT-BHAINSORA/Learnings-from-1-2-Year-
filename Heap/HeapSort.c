#include <stdio.h>
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int size, int i)
{
    int largest = i; // intial assume as largest node index.
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < size && arr[lchild] > arr[largest])
        largest = lchild;
    if (rchild < size && arr[rchild] > arr[largest])
        largest = rchild;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        Heapify(arr, size, largest);
    }
}

void createHeap(int arr[], int key)
{
    if (size == 0)
    {
        arr[size++] = key;
    }
    else
    {

        arr[size++] = key;

        int lastNode = (size / 2) - 1; // acessing parent of last node's Parents or last Not leaf node.

        for (int i = lastNode; i >= 0; i--)
        {
            Heapify(arr, size, i);
        }
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
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
    int arr[10];

    createHeap(arr, 10);
    createHeap(arr, 20);
    createHeap(arr, 15);
    createHeap(arr, 30);
    createHeap(arr, 40);

    printHeap(arr, size);

    heapSort(arr, size);

    printHeap(arr, size);

    return 0;
}
