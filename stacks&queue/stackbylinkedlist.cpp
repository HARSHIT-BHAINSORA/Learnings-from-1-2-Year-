#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *top = NULL; // global variable

void push(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
        top->next = NULL;
        return;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL)
    {
        cout << "stack is underflow";
        return;
    }
    node *t = top;
    top = top->next;
    delete (t);
}

void peek()
{
    if (top == NULL)
    {
        cout << "no elment at top";
        return;
    }
    else
    {
        cout << top->data << endl;
    }
}

bool empty()
{
    return top == NULL;
}

void display()
{
    if (top == NULL)
    {
        cout << "stack is underflow";
        return;
    }
    else
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            cout << "|" << endl;
            cout << "*" << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    peek();
    pop();
    pop();
    peek();

    return 0;
}