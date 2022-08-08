#include <iostream>
#include <algorithm>
using namespace std;
int cal_width(struct node *root, int level);
int height(struct node *root);

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

int max_width(struct node *root)
{
    int maxwidth = 0;
    int level = height(root);
    int width, i;
    for (i = 1; i <= level; i++)
    {
        width = cal_width(root, i);
        if (maxwidth < width)
        {
            maxwidth = width;
        }
    }
    return maxwidth;
}

int cal_width(struct node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
        return cal_width(root->left, level - 1) + cal_width(root->right, level - 1);
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        return max(lheight, rheight) + 1;
    }
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(8);
    root->right->right->left = new node(6);
    root->right->right->right = new node(7);

    int width = max_width(root);
    cout << width;
    return 0;
}