#include <iostream>
using namespace std;
#define n 100

class stack
{
    int *a;
    int top;

public:
    stack() //constructor
    {
        a = new int[n]; //array
        top = -1;       //****
    }

    int Top()
    {
        if (empty())
        {
            cout << " No element is a stack" << endl;
            return -1;
        }
        return a[top];
    }

    bool empty()
    {
        return top == -1; //return 0 or 1
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "stack is overflow" << endl;
            return;
        }

        top++;
        a[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
};

int main()
{
    stack st; // object
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    return 0;
}
