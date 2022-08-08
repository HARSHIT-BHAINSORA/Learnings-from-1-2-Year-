#include<iostream>
using namespace std;

void inorder (struct node* root);
bool isvalid_bst(struct node *root);

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

bool isvalid_bst(struct node *root)
{
    static struct node *prev = NULL;

    if(root == NULL)
        return true;
    
    if(isvalid_bst(root->left) == false) // return false when prev is greater then equal to the root.
    {
        return false;
    }

    if(prev != NULL && prev->data >= root->data)
        {
            return false;
        }
    prev = root;
    return isvalid_bst(root->right) ;   

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

     
    if(isvalid_bst(root))
    {
        cout<<"Binary tress is BST";
    }
    else{
        cout<<"Not BST";
    }
    return 0;
}    

