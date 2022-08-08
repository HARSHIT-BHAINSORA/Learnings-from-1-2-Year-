//  MAX  heap Creation

// i. Creation of heap
// ii. Deletion in heap

// Using array(indexing from  0 )
/* some points  i. In array ith representing node of heap
ii so to access left child - 2 * i + 1 
iii access right child - 2 * i + 2
iv access parent - [i / 2] - 1 */

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

void deletionHeap(int arr[], int key)
{
    int i;

    for (int i = 0; i < size; i++)
    {
        arr[i] == key;
        break;
    }

    swap(&arr[i], &arr[size - 1]);
    size -= 1;

    for (int i = size - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
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

    deletionHeap(arr, 40);

    printHeap(arr, size);
    return 0;
}
