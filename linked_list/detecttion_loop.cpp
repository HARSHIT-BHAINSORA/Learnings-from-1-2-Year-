// 
//  Loop in the linked list .



// i. detect of loop.
// ii. detect of node where the linked list began to from loop .
// iii. find the node at meet .
// iv. Removal of loop.

//   4 -> 6 ->  1  ->  7 -> 2        3 -> 2 -> 1-> 6 -> 9 -> 1->NULL 
//        |---5---12---3----|        

// fast                 |
// slow                 | 

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


void insert_at_end(node *&head, int num)
{
    node *temp, *last;
    temp = new node(num);

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

void make_cycle(node* head , int pos)
{
    node* temp = head;
    node* s = NULL;
    int count = 1;

    while(temp->next != NULL)
    {
        if(count == pos)
            s = temp;
        temp = temp->next;
        count++;    
    }

    temp->next = s;
}

bool detection_loop(node* head)
{
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        
        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

node* node_start(node* head)
{
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        
        slow = slow -> next;
        fast = fast->next->next;
        
        if(fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

node* meeting_node_loop(node* head)
{
    node* first = head;
    node* meet = node_start(head);
     

    while(first != meet)
    {
        meet = meet->next;
        first = first->next;
    }

    return first;

}

void removal_loop(node* head)
{
    node* first = head;
    node* meet = node_start(head);

    while(first->next != meet->next)
    {
        meet = meet->next;
        first = first->next;
    }

    meet->next = NULL;
}

int main()
{
    node *head = NULL;

    insert_at_end(head, 4);
    insert_at_end(head, 6);
    insert_at_end(head, 1);
    insert_at_end(head, 7);
    insert_at_end(head, 2);
    insert_at_end(head, 3);
    insert_at_end(head, 12);
    insert_at_end(head, 5);
    insert_at_end(head, 11);
    insert_at_end(head, 50);
    display(head);

    make_cycle(head , 4);
    // display(head);

    bool a = detection_loop(head);

    if(a == 1)
        cout<<"Loop is detected in linked list"<<endl;
    else if(a==0)
        cout<<"Loop is  not detected in linked list"<<endl ; 

    node* p = node_start(head);
    cout<<"loop starting node data   :- " <<p->data << endl;     
    
    node* t = meeting_node_loop(head);
    cout<<"loop meeting node data : -  "<< t->data << endl;    
    
    removal_loop(head);
    display(head);
    
    return 0 ;
}    