#include <iostream>
#include <queue>
#include <stack>
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

void reverse_levelorder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<Node *> s;

    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        s.push(node);
        q.pop();

        if (node->right)
            q.push(node->right);
        if (node->left)
            q.push(node->left);
        }

    while (!s.empty())
    {
        Node *node = s.top();
        cout << node->data << " ";
        s.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    reverse_levelorder(root);

    return 0;
}