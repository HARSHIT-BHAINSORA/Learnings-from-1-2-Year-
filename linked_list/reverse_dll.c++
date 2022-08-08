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
node *revdlinkedlist(node *head)
{
    node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    node *newhead = t;
    node *temp = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
    }
    return newhead;
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

    node *newhead = revdlinkedlist(head);
    display(newhead);

    return 0;
}