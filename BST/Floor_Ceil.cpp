#include<iostream>
using namespace std;

void floor_ceil(struct node *root , int input ,int &floor , int &ceil);
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

void floor_ceil(struct node *root , int input ,int &floor , int &ceil)
{
    while(root)
    {
        if(root->data == input)
        {
            floor = root->data;
            ceil = root->data;
        }

        if(root->data > input)
        {
            ceil = root->data;
            root = root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }

    return ;

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
    
    int floor = -1 , ceil = -1;
    int input = 11;
    floor_ceil(root ,input ,floor ,ceil);

    cout<<floor<<" "<<ceil;

    return 0;
}    