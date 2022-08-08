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


// insertion in linked list

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

void insert_at_end(struct node** head , int val)
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

void insert_at_key(struct node*head , int val , int item )
{
    struct node* temp = new_node(item);

    struct node* t = head;
    while(t->data != val)
    {
        t = t->next;
    }
    struct node* s = t->next;
    t->next = temp;
    temp->next = s;
}   


// deletion in linked list

void deletion_at_beginning(struct node** head)
{
    if(*head == NULL)
        return ;
    struct node* d = *head;

    *head = d->next;
    free(d);    
}


void deletion_at_end(struct node** head)
{
    if(*head == NULL)
        return ;
    struct node* tem = *head ;
    if(tem->next == NULL)
        {
            *head = NULL;
            free(tem);
        }

    struct node* temp = *head;

    while(temp->next->next != NULL)
    {
        temp  = temp->next; 
    }
    struct node* d = temp->next ;
    temp->next = NULL;
    free(d);
}

void deletion_of_any_node(struct node** head ,int val)
{
    struct node* temp = *head;
    if(temp->data == val)
    {
        *head = temp->next;
        free(temp);
        return ;
    }

    while(temp->next->data != val)
    {
        temp = temp->next; 
    }
    struct node* d = temp->next;
    temp->next = d->next;
    free(d); 

}

// display
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

    insert_at_key(head,2 ,5);
    display(head);

    deletion_of_any_node(&head, 5);
    display(head);

    deletion_at_beginning(&head);
    display(head);

    deletion_at_end(&head);
    display(head);
    return 0;
}
