#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insert_at_starting(node *&head, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void reverse_dll(node *&head)
{
    node *temp = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
}

void display(node *head)
{
    node *t = head;

    while (t != NULL)
    {
        cout << t->data << "<->";
        t = t->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    insert_at_starting(head, 5);
    insert_at_starting(head, 3);
    insert_at_starting(head, 6);
    insert_at_starting(head, 7);
    insert_at_starting(head, 8);

    display(head);

    reverse_dll(head);

    display(head);

    return 0;
}