// height Balanced tree ... (avl)

#include <stdio.h>
#include <stdlib.h>

// struct

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height; // height at every Node.
} treeNode;

// create NewNode

treeNode *createNode(int val)
{
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // newNode height is 1

    return newNode;
}

// max fun

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// height Calculate

int height(treeNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// check node is balanced aur not...

int getBalance(treeNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Right Rotation Function

treeNode *rotateRight(treeNode *y)
{
    treeNode *x = y->left;
    treeNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left Rotation Fumction

treeNode *rotateLeft(treeNode *x)
{
    treeNode *y = x->right;
    treeNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// insert Node same as Bst

treeNode *insert(treeNode *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (root->data < key)
        root->right = insert(root->right, key);
    else if (root->data > key)
        root->left = insert(root->left, key);
    else
        return root;

    // Let 's update height

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = getBalance(root);

    // left - left imbalance

    if (bf > 1 && key < root->left->data)
        return rotateRight(root);

    // right - right imbalance

    if (bf < -1 && key > root->right->data)
        return rotateLeft(root);

    // left-right Imbalance
    if (bf > 1 && key > root->left->data)
    {

        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // right-left imbalance
    if (bf < -1 && key < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    treeNode *root = NULL;

    root = insert(root, 40);

    root = insert(root, 20);

    root = insert(root, 10);

    root = insert(root, 25);

    root = insert(root, 30);

    root = insert(root, 22);
    root = insert(root, 50);

    preOrder(root);

    return 0;
}