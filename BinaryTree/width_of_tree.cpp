// Q . Max width of a binary tree .

/*        1      1 
         /  \
        2    3      2
       / \    \
      4   5    8     3
              / \
             6   7    2   OUTPUT - 3*/

#include <iostream>
#include <queue>
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

int max_width(struct node *root)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int max_width = 0;
    while (!q.empty())
    {
        int width = q.size();
        max_width = max(max_width, width);
        while (width--)
        {
            node *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return max_width;
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