#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void insert_at_beginning(node *&head, int val)
{

    node *temp;
    temp = new node;
    temp->data = val;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }

    node *t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    t->next = temp;
    temp->next = head;
    head = temp;
}

void insertion_at_end(node *&head, int val)
{
    node *temp;
    temp = new node;
    temp->data = val;
    temp->next = NULL;

    if (head == NULL)
    {
        insert_at_beginning(head, val);
    }
    node *t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    t->next = temp;
    temp->next = head;
}

void deletion_at_beginning(node *&head)
{
    node *t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    node *temp = t->next;
    t->next = head->next;
    head = head->next;
    delete (temp);
}

void deletion_at_end(node *head)
{
    node *t = head;
    while (t->next->next != head)
    {
        t = t->next;
    }
    node *temp = t->next;
    t->next = head;
    delete (temp);
}

void display(node *head)
{
    node *t = head;
    do
    {
        cout << t->data << "->";
        t = t->next;
    } while (t != head);
    cout << "head" << endl;
}

int main()
{
    node *head = NULL;

    insert_at_beginning(head, 4);
    insert_at_beginning(head, 3);
    insert_at_beginning(head, 2);
    insert_at_beginning(head, 1);
    display(head);

    insertion_at_end(head, 5);
    insertion_at_end(head, 6);
    insertion_at_end(head, 7);
    display(head);

    deletion_at_beginning(head);
    deletion_at_beginning(head);
    display(head);

    deletion_at_end(head);
    deletion_at_end(head);
    display(head);
    return 0;
}