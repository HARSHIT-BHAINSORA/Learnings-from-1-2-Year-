#include<iostream>
using namespace std;
struct node* insertion(struct node* root , int item);
struct node* min_value(struct node* node);
void inorder (struct node* root);
struct node* deletion(struct node* root, int target);

struct node{
    int data;
    struct node*left;
    struct node*right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

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
struct node* min_value(struct node* node)
{
    struct node* curr = node;
    while(curr && curr->left != NULL)
        curr = curr->left;
    return curr;    
}
struct node* deletion(struct node* root, int target)
{
    if(root == NULL)
        return root;
    if(root->data > target)
        root->left = deletion(root->left , target);
    else if(root->data < target)
        root->right = deletion(root->right , target);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            struct node* temp = min_value(root->right);
            root->data = temp->data;
            root->right = deletion(root->right,temp->data);
        }
        
    } 
    return root;       

}

int main()
{
    struct node* root = NULL;
    root = insertion(root,50);
    root = insertion(root,30);
    root = insertion(root,70);
    root = insertion(root,20);
    root = insertion(root,60);
    root = insertion(root,80);
    root = insertion(root,60);
   
    inorder(root);
    cout<<endl;
    deletion(root , 70);
    inorder(root);
    return 0;
}    