// i . iterative

// head 1 ->   1 -> 3 -> 6 -> 8 ->NULL
//  ptr1                            |      

// head 2 -> 2 -> 5 -> 7 -> NULL
// ptr2                       |

//       _ _ _ _ _ _ _ _ _ _
// dummy |_-1_|_ address 1_| -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 8 -> NULL
// ptr3                                                             |


// ii . Recursive

// head 1 ->   1 _   3 _   6 _  8 ->NULL                                
//             ^  |  |  |  |    |
//    r- -- -- |  |  |  |  |    |
//                |  |  |  |    |
// head 2 ->      2 --  5 -- -> 7 -> NULL
                       



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


// Node* merge_linkedlist(Node* head1 , Node* head2)
// {
//     Node* dummy = new Node(-1); 
//     Node* ptr1 = head1;
//     Node* ptr2 = head2;
//     Node* ptr3 = dummy;

//     while(ptr1 != NULL && ptr2 != NULL)
//     {
//         if(ptr1->data < ptr2->data)
//         {
//             ptr3->next =  ptr1;
//             ptr1 = ptr1->next;
//         }
//         else{
//             ptr3->next = ptr2;
//             ptr2 = ptr2->next;
//         }

//         ptr3 = ptr3->next;
//     }

//     while(ptr1 != NULL)
//     {
//         ptr3->next = ptr1;
//         ptr1 = ptr1->next;
//         ptr3 = ptr3->next;
//     }

//     while(ptr2 != NULL)
//     {
//         ptr3->next = ptr2;
//         ptr2 = ptr2->next;
//         ptr3 = ptr3->next;
//     }

//     return dummy->next;

// }

Node* merge_linkedlist(Node* head1 , Node* head2)
{
    Node* res = NULL;

    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
         return head1;    
    
    if(head1 ->data < head2->data)
    {
        res = head1;
        res->next = merge_linkedlist(head1->next , head2);
    }
    else{
        res = head2;
        res->next = merge_linkedlist(head1 , head2->next);
    }

    return res;
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


int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    head1 = insert_at_head(head1 , 8);
    head1 =insert_at_head(head1 , 6);
    head1 =insert_at_head(head1 , 3);
    head1 =insert_at_head(head1 , 1);

    display(head1);

    head2 =insert_at_head(head2 , 7);
    head2 =insert_at_head(head2 , 5);
    head2 =insert_at_head(head2 , 2);
    
    display(head2);
    
    Node* new_head =  merge_linkedlist(head1 ,head2);

    display(new_head);
    
    return 0;
}
