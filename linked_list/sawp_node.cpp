//           ^-----         
//   5 -> 6  2 -> 4  1 -> 9 ->null
//         - - - ------^        
// 10   20   50   40   30   60 
 
//  1. x = 1  y = 2 pre , curr.
//  2. x = 5  y = 4 vice -versa.
//  3. x ,y is not in linked list.
//  4. x, y is same.

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



void swap(node* &head , int x , int y )
{
    
    if(x == y)
        return ;
    
    node * currx= head ;
    node*  curry = head;
    node* prevx= NULL ;
    node* prevy = NULL;

    while(currx->data != x)
    {
        prevx = currx;
        currx = currx->next;
    }

    while(curry->data != y)
    {
        prevy = curry;
        curry = curry->next;
    }

    
    if(currx == NULL || curry == NULL)
    {
        return ;
    }
    
    
    if(prevx != NULL)
    {
        prevx->next = curry;
    }
    else{
        head = curry;
    }

    if(prevy != NULL)
    {
        prevy->next = currx;
    }
    else{
        head = currx;
    }

    node* temp = currx->next;
    currx->next = curry->next;
    curry->next = temp;
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

    swap(head , 2 , 5);

    display(head);


    return 0;
}   