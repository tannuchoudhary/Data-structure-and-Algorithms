#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

using namespace std;

class operatorStack
{
private:

    char item[SIZE];
    int top;

public:

/*Function prototype*/

void push (char);
char pop ();
int isEmpty();
int prcd(char, char);
void convert(char[], char[]);

operatorStack ()
{
    top = -1;
}

};
/*Function definition*/

void operatorStack :: push(char value)
{
    if (top == SIZE -1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
        top++;
        item[top] = value;

}


char operatorStack :: pop()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return 9;
    }

        int value;
        value = item[top];
        top--;
        return value;
}



int operatorStack :: isEmpty() /*It will return '1' if the stack is empty and will return '0' if not*/

{
    return (top == -1);
}


/*Prcd function to check the precedence of the operator present in the top of the stack and the next token*/
/*It will return 1 if the operator in top of the stack will have more priority then the next token else 0*/

int operatorStack :: prcd(char left, char right)
{
    if(left == '(' || right == '(')
        return 0;

        if (right == ')')
            return 1;

        if (left == '*' || left == '/')
        {

            if(right == '*' || right == '/' || right == '+' || right == '-')
                return 1;

            else
                return 0;

        }

        if(left == '+' || left == '-')

        {
            if (right == '+' || right == '-')
                return 1;

            else
                return 0;

        }

        if(left == '$' && right == '$')
        {
            return 0;
        }

        if(left == '$')
        {
            return 1;
        }

        else

            return 0;

}

/*This convert function will convert the infix expression into postfix expression*/

void operatorStack :: convert(char infix[], char postfix[])
{
   operatorStack stack;
   int i=0, j=0;

   while(infix[i] != '\0')
   {
       char token = infix[i];

       /*If the token is an operand it will be simply appended to the postfix expression*/
       if(token >= '0' && token <='9')
       {

        postfix[j++] = token;

       }

       /*If the token is an operator it will be checked that either the stack is empty or not*/
       else if(token == '+' || token == '-' || token == '*' || token == '/' || token == '$')

        {
            /*If the stack is empty and prcd function is returning 1 then operator will be appended to the postfix string*/
           while(stack.top !=-1 && prcd(stack.item[stack.top], token))
             {
               char top_opr = stack.pop();
               postfix[j++] = top_opr;
             }

           /*If we will have both opening and closing parenthesis in the stack top and toke then they will be discarded*/
           if(token == ')')
            stack.pop();

        /*And if the stack is empty or prcd function is returning 0 then the operator will be pushed into the stack*/
       else
        stack.push(token);
        }

       else
       {
        printf("Invalid symbol %c encountered\n", token);
        exit(1);
       }

       i++;
   }


/*When the stack will contain only one operator then it will be popped out and appended to the postfix string*/
  while(stack.top !=-1)
  {
     char top_opr = stack.pop();
     postfix[j++] = top_opr;
  }

  postfix[j] = '\0';

}


int main()
{
    operatorStack s1;
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix string : ");
    scanf("%s", &infix);

    s1.convert(infix, postfix);
    printf("\nThe converted postfix string is %s\n", postfix);
    return 0;
}

