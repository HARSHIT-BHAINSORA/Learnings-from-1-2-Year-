#include<iostream>
using namespace std;
# define n 100
class queue{
    int * a;
    int front ,back ;

    public:
    queue(){
        a  = new int [n];
        front = -1;
        back = -1;
    }

    void push(int val)
    {
        if(back == n-1)
        {
            cout<<"Queue is overflow";
            return ;
        }
        back++;
        a[back] = val;
        if(front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if(front == -1 || front > back)
        {
            cout<<" Queue is empty ";
            return;
        }
        front++;
    }

    int peek()
    {
        if(front == -1 || front > back)
        {
            cout<<" Queue is empty ";
            return -1;
        }
        return a[front];
    }

    bool empty()
    {
        if(front == -1 || front > back)
             return true;
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
    cout << q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
}