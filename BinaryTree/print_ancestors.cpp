// Q . Print all the ancetors of a given node.

#include <iostream>
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

bool print_ancestors(struct node *root, int target)
{
    if (root == NULL)
        return 0;
    if (root->data == target)
    {
        return 1;
    }

    if (print_ancestors(root->left, target) || print_ancestors(root->right, target))
    {
        cout << root->data << " ";
        return 1;
    }
    else
        return 0;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(7);

    print_ancestors(root, 3);
    return 0;
}