//iterative method
#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *next;
};

void insert_at_beginning(node *&head, int num)
{
    node *temp;
    temp = new node;
    temp->info = num;
    temp->next = head;

    head = temp;
}

void display(node *head)
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->info << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}

node *reverse(node *&head) // iteration
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextprt;

    while (currptr != NULL)
    {
        nextprt = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextprt;
    }
    return (prevptr);
}

node *reverse_recurrions(node *&head) //recursion
{
    if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }

    node *newhead = reverse_recurrions(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    node *head = NULL;

    insert_at_beginning(head, 1);
    insert_at_beginning(head, 2);
    insert_at_beginning(head, 3);
    insert_at_beginning(head, 4);
    display(head);

    node *new_node = reverse_recurrions(head);
    display(new_node);
    return 0;
}