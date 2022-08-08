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

int length(Node* head)
{
   
   if(head == NULL)
   {
       return 0;
   }

   return 1+length(head->next);
   

   
   
   
   
    // int count = 1;
    
    // Node* temp = head;
    // while(temp->next != NULL)
    // {
    //     temp =temp->next;
    //     count++;
    // }

    // return count;
}

void insert_at_head(Node* &head , int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        return ;
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

int main()
{
    Node* head = NULL;
    insert_at_head(head , 1);
    insert_at_head(head , 2);
    insert_at_head(head , 3);
    insert_at_head(head , 4);
    display(head);
    
    int len = length(head);
    cout<<len;
    return 0;
}