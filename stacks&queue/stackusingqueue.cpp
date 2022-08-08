// stack implementation using queue.

// stack -  push(int  val) , pop() , peek() , display()

// queue -  FIFO (First in first out)

// stack - 1 2 3 5     queue - 5 3 2 1   wrong
//         |                   |     |
//        top                  f     r

// push operation costly
//
// queue  q1 - 1 2 3 5
//        q2 -

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;
    int size;

public:
    Stack()
    {
        size = 0;
    }

    void push(int val)
    {
        size++;

        q2.push(val);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        q1.pop();
        size--;
    }

    void top()
    {
        if (q1.empty())
        {
            return;
        }

        cout << "Top of the stack is = " << q1.front() << endl;
    }

    void currSize()
    {
        cout << "The Size of the Stack is = " << size << endl;
    }

    void display()
    {
        queue<int> q = q1;

        while (!q.empty())
        {
            cout << q.front() << " " << endl;
            q.pop();
        }
    }
};

int main()
{
    Stack s;

    s.push(5);
    s.push(3);
    s.push(2);
    s.push(1);

    s.display();

    cout << endl;

    s.pop();

    s.display();

    s.top();

    s.currSize();

    s.push(8);
    s.display();

    cout << endl;

    s.pop();
    s.pop();
    s.pop();

    s.top();
}