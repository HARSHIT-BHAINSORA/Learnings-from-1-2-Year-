

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_element(node *&head, int val)
{
    node *temp = new node(val);

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

    insert_element(head, 3);
    insert_element(head, 2);
    display(head);
    return 0;
}