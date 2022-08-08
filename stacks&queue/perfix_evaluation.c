//      - + 7 * 4 5 + 2  0

// i                     |

// stack 0 2


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct stack{
    int top;
    int capacity;
    int *a;
}; 

struct stack* creation_stack(int cap)
{
    struct stack *stack = (struct stack*) malloc(sizeof(struct stack));
    if(!stack)
        return NULL;
    stack->capacity = cap;
    stack -> top = -1;
    stack -> a = (int*) malloc(stack->capacity * sizeof(int)) ;

    return stack;
}

int isempty(struct stack* stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void push (struct stack* stack  , char exp )
{
    stack->top++;
    stack->a[stack->top] = exp;
}

char peek (struct stack* stack )
{
    return stack->a[stack->top];
}

void pop(struct stack* stack )
{
    if(isempty(stack))
    {
        return;
    }
    stack->top--;
}

int infix_to_prefix(char* exp)
{
    struct stack * stack = creation_stack(strlen(exp)); 
    int i ;

    if(!stack)
        return -1;

   
    for(i = strlen(exp)-1 ; i>= 0 ; i--)
    {
        if(exp[i] >='0' && exp[i] <= '9' )
        {
            push(stack , exp[i]-'0');
        }

        else{
            int val1 = peek(stack);
            pop(stack);
            int val2 = peek(stack);
            
            pop(stack);
            

            switch(exp[i])
            {
                case '+':  push(stack , val1 + val2);
                            break;
                case '-':  push(stack , val1 - val2);
                            break;
                case '*':  push(stack , val1 * val2);
                            break;
                case '/':  push(stack , val1 / val2 );
                            break;                        
            }
        }
    }    
    int b = peek(stack);
    pop(stack);
    return b;
}

int main()
{
    char exp[] ="-+7*45+20";
    printf("%d is perfix evaluation " , infix_to_prefix(exp));
    return 0;
}