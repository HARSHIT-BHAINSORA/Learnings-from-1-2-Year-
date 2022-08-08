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

void inserting_at_end(node *head, int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    node *t = head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = temp;
    temp->prev = t;
}

void inserting_at_kth(node *head, int val, int pos)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    int count = 1;
    node *t = head;

    while (count < pos)
    {
        t = t->next;
        count++;
    }
    temp->prev = t->prev;
    t->prev = temp;
    temp->next = temp->prev->next;
    temp->prev->next = temp;
}

void deletion_at_beginning(node *&head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty";
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}

void deletion_at_end(node *head)
{
    node *t = head;

    while (t->next->next != NULL)
    {
        t = t->next;
    }
    t->next = NULL;
}

void deletion_at_end(node *head, int pos)
{
    node *t = head;
    int count = 1;

    while (count != pos)
    {
        t = t->next;
        count++;
    }
    t->prev->next = t->next;
    if (t->next != NULL)
    {
        t->next->prev = t->prev;
    }
    delete (t);
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

int main()
{
    node *head = NULL;

    inserting_at_beginning(head, 4);
    inserting_at_beginning(head, 3);
    inserting_at_beginning(head, 2);
    inserting_at_beginning(head, 1);
    display(head);

    inserting_at_end(head, 5);
    inserting_at_end(head, 6);
    display(head);

    inserting_at_kth(head, 7, 2);
    inserting_at_kth(head, 8, 4);
    display(head);

    deletion_at_beginning(head);
    display(head);

    deletion_at_end(head);
    display(head);

    deletion_at_end(head, 2);
    display(head);
    deletion_at_end(head, 4);
    display(head);

    return 0;
}
