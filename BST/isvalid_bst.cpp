// Approach 1. visit every node and check it to every node.

#include<iostream>
using namespace std;
bool islesser(struct node *root , int key);
bool isgreater (struct node *root , int key);
bool isvalid_bst(struct node *root);
struct node* insertion(struct node* root , int item);
void inorder (struct node* root);

struct node{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool islesser(struct node *root , int key)
{
    if(root == NULL)
        return true;
    if(root->data <= key && islesser(root->left , key) && islesser(root->right , key))
    {
        return true;
    }
    else{
        return false;
    }   
}

bool isgreater (struct node *root , int key)
{
    if(root == NULL)
        return true;
    if(root->data > key && isgreater(root->left , key) && isgreater(root->right , key))
    {
        return true;
    }
    else{
        return false;
    }   
}

bool isvalid_bst(struct node *root)
{
    if(root == NULL) // base condition
    {
        return true;
    }

    if(islesser(root->left , root->data) && isgreater(root->right , root->data) && isvalid_bst(root->left) && isvalid_bst(root->right))
    {
        return true;
    }
    else{
        return false;
    }
}


struct node* insertion(struct node* root , int item)
{
    if(root == NULL) // base condition
    {
        root = new node(item);
        return root ;
    }    
    if(root->data > item)
        root->left = insertion(root->left , item);
    else if(root->data < item)
        root->right = insertion(root->right , item);

    return root;        
}

void inorder (struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right); 
    }
}       

int main()
{
    struct node* root = NULL;
    root = insertion(root,50);
    insertion(root,30);
    insertion(root,70);
    insertion(root,40);
    insertion(root,60);
    insertion(root,80);
    insertion(root,60);
   
    inorder(root);
    cout<<endl;

    if(isvalid_bst(root))
    {
        cout<<"Binary tress is BST";
    }
    else{
        cout<<"Not BST";
    }
    return 0;
}    