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

    return max(calheight(root->left), calheight(root->right)) + 1;
}

int caldiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    int currdiameter = lheight + rheight + 1;

    int ldiameter = caldiameter(root->left);
    int rdiameter = caldiameter(root->right);

    return max(currdiameter, max(ldiameter, rdiameter));
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->right->right = new node(7);
    root->left->left->left = new node(4);
    root->left->left->left->left = new node(5);

    cout << caldiameter(root);
    return 0;
}