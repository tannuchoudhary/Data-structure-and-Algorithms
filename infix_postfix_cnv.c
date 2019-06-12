#include<stdio.h>
#include<stdlib.h>

#define SIZE 100


typedef struct
{
    char item[SIZE];
    int top;

}operatorStack;


/*Function prototype*/

void push (operatorStack *, char);
char pop (operatorStack *);
int isEmpty(operatorStack *);
int prcd(char, char);
void convert(char[], char[]);


/*Function definition*/

void push(operatorStack *sp, char value)
{
    if (sp->top == SIZE -1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
        sp->top++;
        sp->item[sp->top] = value;

}


char pop(operatorStack *sp)
{
    if(isEmpty(sp))
    {
        printf("Stack underflow\n");
        return 9;
    }

        int value;
        value = sp->item[sp->top];
        sp->top--;
        return value;
}



int isEmpty(operatorStack *sp) /*It will return '1' if the stack is empty and will return '0' if not*/

{
    return (sp->top == -1);
}


/*Prcd function to check the precedence of the operator present in the top of the stack and the next token*/
/*It will return 1 if the operator in top of the stack will have more priority then the next token else 0*/

int prcd(char left, char right)
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

void convert(char infix[], char postfix[])
{
   operatorStack stack;
   stack.top = -1;
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
               char top_opr = pop(&stack);
               postfix[j++] = top_opr;
             }

           /*If we will have both opening and closing parenthesis in the stack top and toke then they will be discarded*/
           if(token == ')')
            pop(&stack);

        /*And if the stack is empty or prcd function is returning 0 then the operator will be pushed into the stack*/
       else
        push(&stack, token);
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
     char top_opr = pop(&stack);
     postfix[j++] = top_opr;
  }

  postfix[j] = '\0';

}


int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix string : ");
    scanf("%s", &infix);

    convert(infix, postfix);
    printf("\nThe converted postfix string is %s\n", postfix);
    return 0;
    
}

