#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *next; //its datatype is  node becuse it store the address node type
};

void insert_at_end(node *&head, int num)
{
    node *temp, *last;
    temp = new node();

    temp->info = num;
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

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode = NULL;

    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
            startnode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detect_cycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void remove(node *&head)
{
    node *fast = head;
    node *slow = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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

int main()
{
    node *head = NULL;

    insert_at_end(head, 1);
    insert_at_end(head, 2);
    insert_at_end(head, 3);
    insert_at_end(head, 4);
    insert_at_end(head, 5);
    insert_at_end(head, 6);
    display(head);
    makecycle(head, 3);
    cout << detect_cycle(head) << endl;
    remove(head);
    display(head);
    cout << detect_cycle(head) << endl;

    return 0;
}
