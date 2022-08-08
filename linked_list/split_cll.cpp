//  Split a circular linked list into two halves.

//  head ->  2 -> 4 -> 5 ->  1 -> 6 -> 7 -> head

//  head1 ->  2 -> 4 -> 5 -> head1  |  head2 -> 1 -> 6 -> 7 -> head2

// i .  middle
// ii. middle -> next = head2;  -----  middle->next = head1
// iii. fix the last nodes next to head2.

//  head ->  2 -> 4 -> 5 ->  1 -> 6 -> 7 -> head    even
//fast -                               |  
 
//slow -               |




// head -   1 -> 4 -> 7 -> 5 -> 3 ->head    odd  
// fast -                       |

// slow -             |

#include<iostream>
using namespace std;

class node{
public:    
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void split(node* head , node* &head1  , node* &head2)
{
    head1 = head;

    node* fast = head;
    node* slow = head;

    while(fast -> next != head  && fast ->next ->next != head)
    {
        fast = fast->next->next ;
        slow = slow->next;
    }

    if(fast ->next ->next == head )
    {
        fast = fast ->next;
    }

    head2 = slow->next;
    slow->next = head1;

    fast->next = head2; 

}


void insert_element(node* &head , int val)
{
    node* temp = new node(val);
    if(head == NULL)
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

    insert_element(head, 7);
    insert_element(head, 6);
    insert_element(head, 1);
    insert_element(head, 5);
    insert_element(head, 4);
    //insert_element(head, 2);
    display(head);

    node* head1 = NULL;
    node* head2 = NULL;

    split(head , head1 , head2);

    display(head1);
    cout<<endl;
    display(head2);
    return 0;
}


