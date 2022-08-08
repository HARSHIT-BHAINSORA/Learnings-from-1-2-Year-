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

int maxdepth(node *root)
{
    if (root == NULL)
        return -1;
    int ld = maxdepth(root->left);
    int rd = maxdepth(root->right);

    if (ld > rd)
        return ld + 1;
    else
        return rd + 1;
}

int main()
{
    struct node *root;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "depth and height of tree is =" << maxdepth(root);
    return 0;
}