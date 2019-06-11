/*This is the program to evaluate the postfix expression, user will enter the postfix expression
 and the program will evaluate it and will give the result*/


 /*Header files*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Defining the size of stack*/
#define SIZE 100

using namespace std;

/*Structure for stack*/

class operand_stack
{
private:

    double item[SIZE];
    int top;

public:
/*Function prototype*/

void push (double);
double pop ();
int isEmpty();                 /*To check whether the stack is empty or not*/
double operate (double, double, char);/*For operation*/
double eval(char[]);                  /*For evaluation*/

operand_stack()
{
    top = -1;
}

};

void operand_stack :: push( double value)
{
    if (top == SIZE -1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    else
        top++;
        item[top] = value;

}

double operand_stack :: pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return -9999;
    }

        int value;
        value = item[top];
        top--;
        return value;
}



int operand_stack :: isEmpty() /*It will return '1' if the stack is empty and will return '0' if not*/

{
    return (top == -1);
}

/*This function will evaluate and return the value of the entered postfix string*/
double operand_stack :: eval(char postfix[])
{
    operand_stack s1;  /*declaring the variable of type stack*/

    int i=0;
    double result = 0.00;


    while (postfix[i]!= '\0')
    {

        char next_token = postfix[i];
        if (next_token >= '0' && next_token <= '9') /*If the next token will be an operand*/
           {

                int v = next_token- '0';           /*As we are dealing with ASCII values, so subtracting
                                                     it with the ASCII value of 0 will give the required integer*/
                s1.push((double) v);
           }


           /*If the next token is an operator , assign the last two operands in variable opnd1 and opnd2 and operate them*/
           /*and then push the result into the stack until and unless we will not reach the end of the expression*/

        else if(next_token == '+' || next_token == '-' || next_token == '*' || next_token == '/' || next_token == '$')
                {
                    double opnd1 = s1.pop();
                    double opnd2 = s1.pop();
                    result = operate(opnd2, opnd1, next_token);
                    s1.push(result);
                }

        else
                {
                    cout<<"Invalid symbol encountered"<<endl;   /*If the entered symbol is not among the mentioned above*/
                    exit(1);
                }

        i++;
    }
    /*When we will reach the end of the expression, just pop out the result from the stack*/
    return s1.pop();


}

/*This function is for operation when the next token will be operator and we will pop out the lat two operands*/

double operand_stack :: operate (double left_opnd, double right_opnd, char oprtr)
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
        default :  cout<<"Invalid operator encountered"<<endl;
                  exit(1);
    }
  return result;
}



int main()
{
    operand_stack s1;
    char postfix[SIZE];
    double result;

    cout<<"Enter postfix expression"<<endl;
    cin>>postfix;

    result = s1.eval(postfix);
    cout<<"result is "<<result<<endl;

    return 0;

}
