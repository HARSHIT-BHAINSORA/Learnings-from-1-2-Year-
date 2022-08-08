// exp  =  A + (B * D - C) + E

// postfix = A B D * C -  + E +

// stack  

// res =  A  B  D  *  C  - + E  +


#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;


int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                    return 1;

        case '*':
        case '/': 
                    return 2;

        case '^' :
                    return 3;
    }
    return -1;
}

void infixtopostfix(string exp)
{
    stack<char>s;

    string res;

   for(int i = 0 ; i < exp.length() ; i++)
   {
       char c = exp[i];

        if(isalpha(c))
        {
            res += c;
        }

        else if(c == '(')
        {
            s.push(c);
        }

        else if(c == ')')
        {
            while(s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            
            s.pop();
        }

        else{
            while(!s.empty() && prec(c) <= prec(s.top()))
            {
                res += c;
                s.pop();
            }
            s.push(c);
        }

   }
   
   while(!s.empty())
   {
       res += s.top();
       s.pop();
   }

   cout<< res << endl;
    
}

int main()
{

    string exp = "A+(B*D-C)+E";
    printf("The postfix expression is : ");
    infixtopostfix(exp);
    return 0;
}