#include<iostream>
using namespace std;

struct node *kth_largest (struct node *root , int &k);
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

struct node *kth_largest (struct node *root , int &k)
{
    if(root == NULL)
        return NULL;

    struct node *right  = kth_largest(root->right , k);

    if(right != NULL)
        return right;
    
    k--;
    if(k == 0)
        return root; 

    return kth_largest(root->left , k);      
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
    struct node *root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    inorder(root);
    cout<<endl;
    int k =3;
    struct node *small = kth_largest(root,k);

    cout<<small->data;

    return 0;
}   
