#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* new_node(int val)
{
    struct node * new_node;
    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

void insert_at_beginning(struct node* *head , int val)
{
    struct node* temp = new_node(val);

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    temp->next = *head;
    *head = temp;
}

void insert_at_end(struct node**head , int val)
{
    struct node* temp = new_node(val);

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    struct node* t = *head;
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
}

void insert_at_key(struct node* *head , int val)
{
    struct node* temp = new_node(val);

    struct node* t = *head;
    while(t->data != val)
    {
        t = t->next;
    }
    struct node* s = t->next;
    t->next = temp;
    temp->next = s;
}   


void display(struct node* head)
{
    struct node *t = head;
    while (t != NULL)
    {
        printf("%d " ,t->data);
        printf("->");
        t = t->next;
    }
    printf( "NULL\n") ;
}

int main()
{
    struct node *head = NULL;

    insert_at_end(&head, 1);
    display(head);

    insert_at_end(&head, 2);
    display(head);

    insert_at_end(&head, 3);
    display(head);

    insert_at_beginning(&head, 7);
    display(head);

    return 0;
}    
