// Min heap.

#include <stdio.h>
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i)
{
    int smallest = i;

    int lchild = (2 * i) + 1;
    int rchild = (2 * i) + 2;

    if (lchild < size && arr[smallest] > arr[lchild])
        smallest = lchild;
    if (rchild < size && arr[smallest] > arr[rchild])
        smallest = rchild;
    if (smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        heapify(arr, size, smallest);
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

        int lastNode = (size / 2) - 1;

        for (int i = lastNode; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
    }
}

void deleteHeap(int arr[], int key)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
            break;
    }

    swap(&arr[i], &arr[size - 1]);
    size -= 1;

    for (int i = size - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
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

    createHeap(arr, 30);
    createHeap(arr, 20);
    createHeap(arr, 10);
    createHeap(arr, 60);
    createHeap(arr, 80);
    createHeap(arr, 90);
    createHeap(arr, 50);

    printHeap(arr, size);

    deleteHeap(arr, 60);

    printHeap(arr, size);

    return 0;
}