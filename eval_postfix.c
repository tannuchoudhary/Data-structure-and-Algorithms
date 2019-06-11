/*This is the program to evaluate the postfix expression, user will enter the postfix expression
 and the program will evaluate it and will give the result*/


 /*Header files*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Defining the size of stack*/
#define SIZE 100


/*Structure for stack*/

typedef struct
{
    double item[SIZE];
    int top;

}operand_stack;

/*Function prototype*/

void push (operand_stack *, double);
double pop (operand_stack *);
void init(operand_stack *);
int isEmpty(operand_stack *);                 /*To check whether the stack is empty or not*/
double operate (double, double, char);/*For operation*/
double eval(char[]);                  /*For evaluation*/


void push(operand_stack *sp, double value)
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

double pop(operand_stack *sp)
{
    if(isEmpty(sp))
    {
        printf("Stack underflow\n");
        return -9999;
    }

        int value;
        value = sp->item[sp->top];
        sp->top--;
        return value;
}


void init(operand_stack *sp) /*For initializing the stack*/
{
    sp->top = -1;
}


int isEmpty(operand_stack *sp) /*It will return '1' if the stack is empty and will return '0' if not*/

{
    return (sp->top == -1);
}

/*This function will evaluate and return the value of the entered postfix string*/
double eval(char postfix[])
{
    operand_stack s1;  /*declaring the variable of type stack*/
    init(&s1); /*Initializing the stack*/

    int i=0;
    double result = 0.00;


    while (postfix[i]!= '\0')
    {

        char next_token = postfix[i];
        if (next_token >= '0' && next_token <= '9') /*If the next token will be an operand*/
           {

                int v = next_token- '0';           /*As we are dealing with ASCII values, so subtracting
                                                     it with the ASCII value of 0 will give the required integer*/
                push(&s1, (double) v);
           }


           /*If the next token is an operator , assign the last two operands in variable opnd1 and opnd2 and operate them*/
           /*and then push the result into the stack until and unless we will not reach the end of the expression*/

        else if(next_token == '+' || next_token == '-' || next_token == '*' || next_token == '/' || next_token == '$')
                {
                    double opnd1 = pop(&s1);
                    double opnd2 = pop(&s1);
                    result = operate(opnd2, opnd1, next_token);
                    push(&s1, result);
                }

        else
                {
                    printf("Invalid symbol encountered\n");   /*If the entered symbol is not among the mentioned above*/
                    exit(1);
                }

        i++;
    }
    /*When we will reach the end of the expression, just pop out the result from the stack*/
    return pop(&s1);


}

/*This function is for operation when the next token will be operator and we will pop out the lat two operands*/

double operate (double left_opnd, double right_opnd, char oprtr)
{
    double result = 0.0;
    switch(oprtr)
    {
        case '+': result = left_opnd + right_opnd;
                  break;
        case '-': result = left_opnd - right_opnd;
                  break;
        case '*': result = left_opnd * right_opnd;
                  break;
        case '/': result = left_opnd / right_opnd;
                  break;
        case '$': result = pow(left_opnd, right_opnd);
                  break;
        default : printf("Invalid operator encountered\n");
                  exit(1);
    }
  return result;
}



int main()
{
    char postfix[SIZE];
    double result;

    printf("Enter postfix expression : ");
    scanf("%s", postfix);

    result = eval(postfix);
    printf("Result is %lf \n", result);

    return 0;

}
