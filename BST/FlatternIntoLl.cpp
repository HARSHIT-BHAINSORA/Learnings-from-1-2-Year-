#include <bits/stdc++.h>
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

void FlatterIntoLl(Node *root)
{
    Node *temp = root;

    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    if (temp->left != NULL)
    {
        if (temp->right != NULL)
        {
            Node *t = temp->right;
            temp->right = temp->left;
            temp->left = NULL;

            Node *cur = root;
            while (cur->right != NULL)
            {
                cur = cur->right;
            }
            cur->right = t;
        }
        else
        {
            temp->right = temp->left;
            temp->left = NULL;
        }
    }
    FlatterIntoLl(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // preOrder(root);
    // cout << endl;

    FlatterIntoLl(root);
    preOrder(root);
    cout << endl;
    return 0;
}