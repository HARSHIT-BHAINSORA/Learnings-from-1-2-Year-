#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = calheight(root->left);
    int rheight = calheight(root->right);

    return max(lheight, rheight) + 1;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->right->right = new node(6);
    root->left->left->left = new node(4);

    cout << calheight(root);
    return 0;
}