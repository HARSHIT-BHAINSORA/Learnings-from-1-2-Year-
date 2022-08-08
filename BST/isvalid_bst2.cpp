//Approach using range.

#include<iostream>
#include<stdlib.h>
using namespace std;

bool valid_bst(struct node *root , int min , int max);
bool bst(struct node *root);
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

bool valid_bst(struct node *root , int min , int max)
{
    if(root == NULL)
        return true;
    if(root->data >= min && root->data < max && valid_bst(root->left , min , root->data) && valid_bst(root->right , root->data , max))
    {
        return true;
    } 
    else{
        return false; 
    }    
}

bool bst(struct node *root)
{
    int min = INT_MIN;
    int max = INT_MAX;

     return valid_bst(root , min , max);
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
    struct node *root = new node(8);
    root->left = new node(5);
    root->right = new node(10);
    root->left->left = new node(4);
    root->right->left = new node(9);
    root->right->right = new node(11);

    inorder(root);
    cout<<endl;
    
    if(bst(root))
    {
        cout<<"Binary tress is BST";
    }
    else{
        cout<<"Not BST";
    }
    return 0;
}    

