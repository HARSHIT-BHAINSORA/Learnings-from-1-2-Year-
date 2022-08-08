// Merge sort  : - Divide and Conquer.

// array =    4  3  9  1  7 
//                /  \
//           4 3 9    1 7
//            /  \     / \ 
//          4  3   9   1   7
//           / \
//          4   3
//           \  /
//            3 4  9   1 7
//               \      /
//              1 3 4 7 9    

// rules -    i . mid 
//            ii. divide
//            iii. recursion untill you will reache at one element
//            iv. merger them together.

//         4 -> 3 -> 9 -> null | 1 -> 7 ->NULL

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


void insert_at_head(Node* &head , int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head= temp;
        return;
    }
    temp->next = head;
    head = temp;
}



void display(Node *head)
{
    Node *t = head;
    while (t != NULL)
    {
        cout << t->data<< "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}


void middle_ll (Node* curr ,Node* &first  ,Node* &second)
{
    Node* slow = curr;
    Node* fast = curr->next;

    while(fast != NULL)
    {   fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }    
    }

    first = curr;
    second =  slow->next;
    slow->next = NULL;
}

Node* merge(Node* first , Node* second)
{
    Node* res = NULL; 
    
    if (first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }
    
    if(first->data < second->data)
    {
        res = first;
        res->next = merge(first->next , second);
    }
    else
    {
        res = second;
        res->next = merge(first , second->next);
    }

    return res;
}


void merge_sort(Node * &head)
{
    Node * curr = head;
    Node * first = NULL;
    Node * second = NULL;
    
  
    
    if( curr == NULL || curr->next == NULL)
    {
        return ;
    }

    middle_ll (curr , first ,second);
    
    merge_sort(first);
    
    merge_sort(second);
    
    
    head = merge(first , second);
  
}


int main()
{
    Node* head= NULL;
    
    insert_at_head(head, 7);
    insert_at_head(head, 1);
    insert_at_head(head, 9);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    

    display(head);

    merge_sort(head);

    display(head);

    return 0;
}    





