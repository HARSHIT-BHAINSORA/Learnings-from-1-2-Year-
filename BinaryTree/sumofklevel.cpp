#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int sum_of_klevel(Node * root , int k)
{
    if(root == NULL)
    {
        return -1 ;
    }

    queue<Node *>q;
    q.push(root);

    int sum = 0 , flag = 0 , level = 0; 
    while(!q.empty())
    {   
       int size = q.size();
        while(size--)
        {   
            Node * ptr = q.front();
            q.pop();
            if(level == k)
            {
                flag = 1;
                sum += ptr->data;
            }
            else{
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);    
            }
        }
        level++;
        if(flag == 1)
            break;
    }
    return sum;
}

int main()
{
    int k;
    cout<<"Enter the level = ";
    cin>>k;
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int sum = sum_of_klevel(root ,k);
    cout<<sum;
    return 0;    

}