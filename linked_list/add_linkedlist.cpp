 
 
//  NULL <-  1   <-   3  <- 4  <-  2 <- h1
//   h1                     |
 
//  NULL <-  7   <-  8  <-  3 <-  h2
//  h2               |


//  Nh -> 5 -> 2 -> 1 -> 2 -> NULL
// prev                  |

//       1 1           1 1
// n1 =  1 3 4 2         9  9
// n2 =  + 7 8 3         +  1 
// ans = 2 1 2 5      1  0  0

// Nh ->  2 -> 1 - > 2 - > 5 -> NULL

// sum = sum % 10
// carry = sum / 10;


#include<iostream>
using namespace std;

class Node{   
public:        
        int data;
        Node* next;
        Node(int val)
            {
                data = val;
                next = NULL;  
            }
};

Node* insert_at_head(Node* head , int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head= temp;
        return head ;
    }
    temp->next = head;
    head = temp;

    return head;
}

void display(Node *head1)
{
    Node *t = head1;
    while (t != NULL)
    {
        cout << t->data<< "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}

Node* reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
 }


Node* add (Node* h1  , Node* h2)
{
    Node* new_head = NULL;
    Node* temp ;
    Node* prev =  NULL;
    int sum  = 0  , carry = 0 ;

    h1 = reverse(h1);
    h2 = reverse(h2);

    while(h1 != NULL || h2 != NULL)
    {
        sum = carry + (h1 ? h1->data : 0) + (h2 ? h2->data : 0);

        carry =  sum / 10;

        sum = sum % 10;

        temp = new Node(sum);

        if(new_head == NULL)
        {
            new_head = temp;
        }
        else{
            prev->next = temp;
        }
        prev = temp;

        if(h1)
        {
            h1 = h1 ->next;
        }
        if(h2)
        {
            h2 = h2 ->next;
        }
    }

    if(carry > 0)
    {
        prev->next = new Node(carry);
    }

    new_head = reverse(new_head);

    return new_head;


}


int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    head1 =insert_at_head(head1 , 2);
    head1 =insert_at_head(head1 , 4);
    head1 =insert_at_head(head1 , 3);
    head1 =insert_at_head(head1 , 1);

    display(head1);

    head2 =insert_at_head(head2 , 3);
    head2 =insert_at_head(head2 , 8);
    head2 =insert_at_head(head2 , 7);
    
    display(head2);

    Node* new_head = add(head1 , head2);
    cout<<"The two added numbers respresented by  linked list is :-  ";
    display(new_head);

    return 0;
}  
    