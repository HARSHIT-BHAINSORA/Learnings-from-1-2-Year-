#include<iostream>
#include<stdlib.h>
using namespace std;
int cal_floor(struct node *root , int input);
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


int cal_floor(struct node *root , int input)
{
    if(root == NULL)
        return INT_MAX;

    if(root->data == input)
        return root->data;

    if(root->data > input)
        return cal_floor(root->left,input);
    int floor  =  cal_floor(root->right,input);
    return (floor <= input) ? floor : root->data ;         
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
    
    int input = 14;
    cout<< cal_floor(root,input);

    return 0;
}    