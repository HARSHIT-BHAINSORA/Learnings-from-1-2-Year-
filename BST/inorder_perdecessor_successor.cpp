#include<iostream>
using namespace std;

void inoder_suc_pre(struct node * root , int *pre ,int *suc ,int key);
void inorder (struct node* root);
struct node* insertion(struct node* root , int item);

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

void inorder_suc_pre(struct node * root , node* &pre ,node* &suc ,int key)
{
    if (root == NULL)
        return ; 
    // 1 . possibality is key found  and root->right is not null (suc)/ root->left is not null(pre).
    if(root->data == key)
    {
        if(root->right != NULL) // successor
        {
            struct node *temp = root->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }

        if(root->left != NULL) // predecessor
        {
            struct node *temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp;
            }
            pre = temp;
        }

        return; 
    }

    if(root->data < key)
        {
            pre = root;
            inorder_suc_pre(root->right,pre,suc,key);
        }
    else if(root->data > key)
    {
        suc = root;
        inorder_suc_pre(root->left,pre ,suc,key);
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
    insertion(root,20);
    insertion(root,60);
    insertion(root,80);
    insertion(root,60);
   
    inorder(root);
    cout<<endl;

    struct node *suc = NULL, *pre = NULL ;

    inorder_suc_pre (root , suc , pre ,60);

    cout<<suc->data<<" "<<pre->data;

    return 0;
}    