
//  head -> 2 -> 4 -> 6 -> 8 ->  9 -> 11 -> 13 -> 14 -> 100
//         100   10   20   80    30   40    50    140
// temp -> 14

// i . Null  head->null
// ii. update head
//iii. insert at any place (middle and last)  cur->next->data < temp->data

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

void insert_sort(node *&head, node *temp)
{
    node *curr = head;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }

    else if (curr->data >= temp->data)
    {
        node *t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        while (curr->next != head && curr->next->data < temp->data)
        {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}

void display(node *head)
{
    node *t = head;

    do
    {
        cout << t->data << "->";
        t = t->next;
    } while (t != head);
    cout << "NODE1" << endl;
}

int main()
{
    node *head = NULL;

    node *temp = new node(4);
    insert_sort(head, temp);

    temp = new node(2);
    insert_sort(head, temp);

    temp = new node(1);
    insert_sort(head, temp);

    temp = new node(50);
    insert_sort(head, temp);

    temp = new node(5);
    insert_sort(head, temp);

    display(head);

    return 0;
}