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

node *insertion(struct node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    if (root->data < key)
    {
        root->right = insertion(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = insertion(root->left, key);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insertion(root, 50);
    insertion(root, 30);
    insertion(root, 20);
    insertion(root, 40);
    insertion(root, 70);
    insertion(root, 60);
    insertion(root, 80);

    inorder(root);

    return 0;
}