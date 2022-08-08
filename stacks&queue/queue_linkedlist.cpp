#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue{
    node *front;
    node * back;
    public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int val)
    {
        node * n = new node(val);
        if(front == NULL)
        {
            back = n ; 
            front = n;
            return ;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"Queue  is underflow";
            return ;
        }
        node * t = front;
        front = front->next;
        delete(t);
    }

    int peek()
    {
        if(front == NULL)
        {
            cout<<"Queue  is empty";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
        {
            return true;
        }
        return false;
    }    

};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
    
}