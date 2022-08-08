#include<iostream>
using namespace std;

void inorder (struct node* root);
int Cal_Ceil(struct node *root , int input);

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

int Cal_Ceil(struct node *root , int input)
{
    if(root == NULL)
        return -1;
    if(root->data == input)
        return root->data;
    
    if(root->data < input)
        return Cal_Ceil(root->right,input);
    
    int Ceil = Cal_Ceil(root->left , input);
    return Ceil >= input ? Ceil : root->data;             
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
    root->left = new node(4);
    root->right = new node(12);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->right->left = new node(9);
    root->right->right = new node(15);

    inorder(root);
    cout<<endl; 
    
    int input = 10;
    cout<< Cal_Ceil(root,input);

    return 0;
}    