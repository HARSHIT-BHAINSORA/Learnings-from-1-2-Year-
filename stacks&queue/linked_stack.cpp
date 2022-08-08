//  3 -> 4 -> 1 -> 7 -> 2 -> NULL  

#include<iostream>
using namespace std;

class stacknode{
public :  
    int data;
    stacknode* next;

    stacknode(int val)
    {
        data = val;
        next = NULL;
    }
};

bool isempty(stacknode* root)
{
    return !root;
}


void push(stacknode* &root , int val)
{
    stacknode* temp = new stacknode(val);
    temp -> next = root;
    root = temp;

    cout<<"Pushed data onto in stack is : - "<< root->data <<endl; 
}

void pop(stacknode* &root)
{
    if(isempty(root))
    {
        return ;
    }

    stacknode* t = root;
    root = root ->next;
    cout<<"The poped data from stack is :-"<< t->data<<endl;
    delete(t);
}

void peek(stacknode* root)
{
    if(isempty(root))
        return;
    cout<<"The element in the peek is :- " << root->data<<endl;;    
}

void display(stacknode* root)
{
    stacknode* t = root;
    while(t != NULL)
    {
        cout<< t->data << " "; 
        t = t->next;
    }

    cout<<endl;
}


int main()
{
    stacknode* root = NULL;

    push(root , 1 );
    push(root , 7);
    push(root , 3);

    display(root);

    pop(root);

    display(root);

    push(root , 8);
    peek(root);

    push(root , 1);
    display(root);

    return 0;
    
}