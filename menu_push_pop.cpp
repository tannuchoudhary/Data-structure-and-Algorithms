// Push and pop operation in C++ without sing poinetrs.

#include<iostream>
#include<stdlib.h>
#define SIZE 6

using namespace std;


class stack
{

private:

   int item[SIZE];
   int top;

public:

   stack()   // Making a constructor for initializing the top variable. 

   {
       top = -1;
   }

   void push(int value)  // For pushing the values into stack

   {
       if(top == SIZE -1) // If the stack will be full, it will not able to take more values

       {
           cout<<"Stack overflow"<<endl;
           return;
       }

       top ++;
       item[top] = value;  // Putting the value into top variable
   }


   int pop()              // For deleting the  values from stack 

   {
       if(top == -1)      // If the stack does not contain any element

       {

           cout<<"Stack underflow"<<endl;
           return -9999;  // Either if there is not any value in the stack, still it have to return an integer
                          // as the return type of the function pop is int, so we will return -9999.

       }

       int value;
       value = item[top];             // Putting the top element in the variable value
       top--;                         // And then decrementing the top by one to get the value of the below element
       return value;                  // Returning the value

   }


};

void push(int);
int pop();


int main()
{
    stack s1;                                                  // Creating an object s1 of type stack
    int choice, value;

    cout<<"1. push"<<endl<<"2. pop"<<endl<<"3. exit"<<endl;   // Display message for user to select option

    while(1)
    {

        cout<<"Enter your choice :"<<endl;
        cin>>choice;


          switch(choice)
        {
                case 1: cout<<"Enter value :"<<endl;
                        cin>>value;
                        s1.push(value);
                        break;

                case 2: value = s1.pop();
                        if(value != -9999)
                            {
                                 cout<<"The deleted element will be "<<value<<endl;

                            }
                        break;

                case 3:exit(0);                              // To exit the console

                default: cout<<"Invalid choice"<<endl;       // For invalid entries
        }
    }
    return 0;
}
