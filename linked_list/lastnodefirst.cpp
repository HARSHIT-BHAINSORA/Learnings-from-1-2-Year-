#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void insert_at_end(node *&head, int num)
{
    node *temp, *last;
    temp = new node();

    temp->data = num;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
}

node *insert_at_first(node *&head, node *e)
{
    node *temp = new node;
    temp->data = e->data;
    temp->next = head;
    head = temp;
    return head;
}

void deletion_at_end(node *head)
{
    node *t = head;
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    node *temp = t->next;
    t->next = t->next->next;
    delete (temp);
}

node *lastnode_asfirst(node *&head)
{
    node *t = head;
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    node *newhead = insert_at_first(head, t->next);
    deletion_at_end(head);
    return newhead;
}

void display(node *head)
{
    node *t = head;
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

    insert_at_end(head, 1);
    insert_at_end(head, 2);
    insert_at_end(head, 3);
    insert_at_end(head, 4);
    display(head);

    node *newhead = lastnode_asfirst(head);
    display(newhead);

    return 0;
}
