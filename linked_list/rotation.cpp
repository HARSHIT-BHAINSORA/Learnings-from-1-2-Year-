//           1  ->  2 ->NULL HEAD -> 3 -> 4 -> 5  -> 6
//           |---------------------------------------|         
// curr             |

// left rotation  k = 2

//  1  ->  2 ->NULL  head ->  3 ->  4  ->  5 ->  6 ->  NULL
//  |--------------------------------------------|
// cuur                                    |

// temp = 2 -> 

// right rotation 
//  k = l-k ;

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

void left_rotation(node* &head , int k)
{
    node* curr = head;
    int l = 1;

    while(curr->next != NULL)
    {
        l++;
        curr = curr->next;
    }
    if(k == l)
        return ;
    else if(k > l) 
    {
        k = k % l;
    }

    curr->next = head ;

    for(int  i = 0 ; i < k ; i++)
    {
        curr  = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

}

void right_rotation(node* &head , int k)
{
    node* curr = head;
    int l = 1;

    while(curr->next != NULL)
    {
        l++;
        curr = curr->next;
    }
    if(k == l)
        return ;
    else if(k > l) 
    {
        k = k % l;
    }
    k = l - k;
    curr->next = head ;

    for(int  i = 0 ; i < k ; i++)
    {
        curr  = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

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

    left_rotation(head , 8);
    cout<<"Left Rotation is  = ";
    display(head);

    right_rotation(head , 2);
    cout<<"Right Rotation is  = ";
    display(head);

    return 0;
}    


