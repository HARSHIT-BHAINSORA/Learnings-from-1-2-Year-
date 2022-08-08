#include<iostream>
using namespace std;
void inorder (struct node* root);
int kth_smallest(struct node *root , int &k);
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

void inorder (struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right); 
    }
}       

 int kth_smallest(struct node *root , int &k)
{
    
    if(root == NULL){
        return 0;
    }
    int left = kth_smallest(root->left ,k);
    
    if(left != 0)
    {
        return left;
    }    
  
    k-=1;
 
    if(k == 0){
        return root->data;
    }    
    int right = kth_smallest(root->right,k);  
    return right;  
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
    int  small = kth_smallest(root,k);
    cout<<small;

    return 0;
}   
