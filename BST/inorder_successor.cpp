#include<iostream>
using namespace std;

struct node * min(struct node *root);
struct node * inorder_sccu(struct node *root , struct node *temp);
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

struct node * min(struct node *root)
{
    struct node *curr = root->left;
    while(curr->left != NULL)
        curr = curr->left;

    return curr;
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


struct node * inorder_sccu(struct node *root , struct node *temp)
{
    if(temp->right != NULL)
    {
        return min(temp->right);
    }

    struct node* succ = NULL;

    while(root != NULL)
    {
        if(root->data > temp->data)
        {
            succ = root;
            root = root->left ;
        }
        else if(root->data < temp->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }   
return succ;
}

int main()
{
   struct node *root = new node(8);
    root->left = new node(5);
    root->right = new node(10);
    root->left->right = new node(6);
    root->left->left = new node(4);
    root->right->left = new node(9);
    root->right->right = new node(11);

    inorder (root);
    cout<<endl;

    struct node *temp = root->left->right;

    struct node *succ = inorder_sccu(root ,temp);

    if(succ != NULL)
        cout<<succ->data<<endl;
    else
        cout<<"NOT FOUND";
    return 0;         

}