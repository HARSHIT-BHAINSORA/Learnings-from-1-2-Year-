#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *next_right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        next_right = NULL;
    }
};

void connect(struct node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        node *prev = NULL;

        while (size--)
        {
            node *node = q.front();
            q.pop();

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            if (prev != NULL)
                prev->next_right = node;
            prev = node;
        }
        prev->next_right = NULL;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    connect(root);

    cout << root->left->data << " " << root->left->next_right->data;

    return 0;
}