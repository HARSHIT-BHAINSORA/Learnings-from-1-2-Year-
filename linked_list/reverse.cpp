
 //  null <- 6  <- 3 <- 8 <- 1 <- 2 <-head
//           |    |    |    |    |
 //          10   20   30   40   50 . 

 // 2 -> 1 -> 8 ->3 ->6 -> NULL

// i. iteration .

// ii . Recursion . 

//                         
//   NULL<-6 <- 3 <- 8  
//   ---   |    |    |
 //        10  20    30 <-head   . 


 // R(10) -> R(head->next = 20 ) -> R (head->next = 30) -> R(head->next = null) -> R(null).
//    30<----------|    30 <----------|         30 <-------|  nhead = 30  <-------|


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




// void Reverse (node* &head )
// {
//     if(head == NULL)
//     {
//         return;
//     }

//     node* curr = head;
//     node* next ;
//     node* prev = NULL;

//     while(curr != NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     head = prev;
    
// }


node* Reverse(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* new_head = Reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return new_head;   
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

    node* new_head = Reverse( head );

    display(new_head);

    return 0 ;

}    