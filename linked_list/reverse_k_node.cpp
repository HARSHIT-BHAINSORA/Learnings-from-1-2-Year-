//   head   ->  6 -> 2 -> 1 -> 9 -> 5 -> 3 -> NULL 

//   k = 2

//   o/p =  head -> 2 -> 6 -> 9 -> 1 -> 3 -> 5 -> NULL. 
//  c = 0
 
//            |<----------
//  head  ->  6 -> 40   2  - >  
//            10         20   30  
//                       | 
//     n=30 , p=20 , cur=30 , c =1      
//                                 ^  40
//                                 |

            
//             |<----------
//  head  ->  1 ->60      9  - >  
//            30         40   50  
//                        | 
//     n=50 , p=40 , cur=50 , c = 1      
//                                       ^   
//                                       |  60
//             |<----------
//  head  ->  5 ->NULL   3  - >  
//            50         60   NULL  
//                        | 
//     n=NULL , p=60 , cur=NULL , c = 1          

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

node*  Reverse( node * head , int k)
{
    node* next;
    node* curr = head;
    node* perv = NULL;
    int count = 0; 

    while(count < k && curr != NULL)
    {
        next = curr->next;
        curr->next = perv; 
        perv = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
    {
        head->next = Reverse( next , k );
    }

    return perv;

}

int main()
{
    node *head = NULL;

    insert_at_end(head, 6);
    insert_at_end(head, 2);
    insert_at_end(head, 1);
    insert_at_end(head, 9);
    insert_at_end(head, 5);
    insert_at_end(head, 3);
    display(head);

    node* new_head = Reverse( head  , 2);

    display(new_head);

    return 0 ;

}    