// algorithm = divide and conqure

//i. mid
//ii.divide and compare
//iii.merge

// NULL <-5->1->9->3->6->7->4->NULL

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

node *merge(node *first, node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

void middle(node *head, node *&first, node *&second)
{
    node *fast = head;
    node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    second = slow->next;
    slow->next = NULL;
}

void merge_sort(node *&head)
{
    if (head == NULL && head->next == NULL)
    {
        return;
    }

    node *first = NULL;
    node *second = NULL;

    middle(head, first, second);

       merge_sort(first);
    merge_sort(second);

    head = merge(first, second);
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

    merge_sort(head);

    display(head);
    return 0;
}