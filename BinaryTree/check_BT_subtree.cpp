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

bool check(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1 == root2) && check(root1->left, root2->left) && check(root1->right, root2->right);
}

bool subtree(struct node *T, struct node *S)
{
    if (T == NULL)
        return 0;
    if (S == NULL)
        return 0;
    if (check(T, S))
        return 1;
    return subtree(T->left, S) || (T->right, S);
}

int main()
{
    struct node *root1 = new node(26);
    root1->left = new node(10);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->right->right = new node(3);
    root1->left->left->right = new node(30);
    root1->left->right = new node(6);

    struct node *root2 = new node(10);
    root2->right = new node(6);
    root2->left = new node(4);
    root2->left->right = new node(30);

    if (subtree(root1, root2))
    {
        cout << "Subtree of BT";
    }
    else
        cout << "Not a Subtree of BT";
    return 0;
}