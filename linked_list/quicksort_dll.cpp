// quick sort :-  divide and conqur.
//               s         e
//             { 4 3 1 5 9 7 }
//         s   e            s e
//        {1 3 4}         { 7 9 }

//     {}    {3 4}       {}     {9}

// i   -1

// j   1
// int partition(int a[] , int st, int end)
// {
//     pivot = a[end]
//     int i = st-1;

//     for(int j = st ; j < end-1 ; j++)
//     {
//         while(a[j] < pivot)
//         {
//             i++;
//             swap(a[i] ,a[j]);
//         }

//     }

//     swap(a[i+1] , pivot);
//     return

// }

// quicksort(int a , st , end)

// while(st < end) || if(st >= end) return ;
// p = paritition(a ,  st , end);
// quicksort(a , st , p-1);
// quicksort(a , p+1 , end);

// i . partition() (insert the pivot at its correct pos. ) pivot - last

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void inserting_at_beginning(node *&head, int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void display(node *head)
{
    node *t = head;
    cout << "NULL <-";
    while (t != NULL)
    {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

node *partition(node *st, node *last)
{
    int pivot = last->data;

    node *i = st->prev;

    for (node *j = st; j != last; j = j->next)
    {
        if (j->data <= pivot)
        {
            i = (i == NULL) ? st : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? st : i->next;
    swap(&(i->data), &(last->data));
    return i;
}

void _quicksort(node *st, node *last)
{
    if (st != NULL && st != last && st != last->next)
    {
        node *p = partition(st, last);
        _quicksort(st, p->prev);
        _quicksort(p->next, last);
    }
}

node *last_node(node *head)
{
    node *t = head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    return t;
}

void quicksort(node *head)
{
    node *start = head;
    node *end = last_node(head);

    _quicksort(start, end);
}

int main()
{
    node *head = NULL;

    inserting_at_beginning(head, 4);
    inserting_at_beginning(head, 7);
    inserting_at_beginning(head, 6);
    inserting_at_beginning(head, 3);
    inserting_at_beginning(head, 9);
    inserting_at_beginning(head, 1);
    inserting_at_beginning(head, 5);

    display(head);

    quicksort(head);

    display(head);
}
