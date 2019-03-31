/*Allocating memory dynamically for the stack and if stack will overflow then automatically the size of the array will be doubled*/
#include<stdio.h>
#include<stdlib.h>


typedef struct

{

     int * item;      /*creating a pointer to contain an address of different object*/
     int top;         /* A "top" variable for containing the values of top element */
     int size;        /*Different object will be of different size*/

}stack;

/*Function definition*/

void push (stack *sp, int value)  /* For pushing an element into stack, first argument i.e pointer is to receive address to point the variable for that particular data type. */
{
    if(sp->top == sp->size-1)         /* If the stack will be full, it will not able to take more values */

      {
         int *temp;
         temp =((int *)malloc(sizeof(int) * sp->size*2));  /*We are assigning the return value, the base address of the allocated space to the temp.*/

        /* Now double sized array has been allocated.*/

         if(temp == NULL)
         {
              printf("STACK OVERFLOW");
              return;
         }
         int i;
         for(i=0; i<=sp->top; i++)  /*We will copy the existing content to the temp array*/
         {
              temp[i] = sp->item[i];
         }
         free (sp->item);      /*Deallocating the existing item array*/
         sp->item = temp;     /* and assigning the temp to the item again*/

         /*Now the item pointer will point to the newly allocated location that contains the existing element as well*/
         sp->size *= 2;       /*Now double the size of the array*/
      }

    sp->top++;                           /* sp->top does means that the pointer sp is pointing to the element in the top variable */
    sp->item[sp->top] = value;           /* Assigning the value in the array */
}

int pop(stack *sp)                       /* For popping an element out of stack*/
   {
      if(sp->top == -1)                  /* If the stack will be empty, it will not able to delete values*/

      {
          printf("STACK UNDERFLOW\n");   /* Either if there is not any value in the stack, still it have to return an integer*/

          return -9999;                  /* As the return type of the function pop is int, so we will return -9999.*/
      }

      int value;
      value = sp->item[sp->top];         /* Putting the top element in the variable value */
      sp->top--;                         /* And then decrementing the top by one to get the value of the below element */
      return value;                      /* Returning the value*/

   }

void init(stack *sp, int size)                    /* For initializing the top variable */
  {
      sp->top = -1;
      sp->item = (int *)malloc(sizeof(int) * size);  /* Allocating the recquired memory using malloc function*/
      if (sp->item == NULL)                          /* Condition if memory can't be allocated*/
      {
          printf("Execution failed\n");
          exit(1);
      }
      sp->size = size;                             /* Assigning the size into the size variable*/
  }
void deallocate(stack *sp)                        /* A function for deallocating memory i.e for freeing up space which is necessary*/
{
    if(sp->item != NULL)
    {
        free(sp->item);
         sp->top = -1;
         sp->size = 0;
    }
}

int getSize(stack *sp)
{
     return sp->size;
}

/* Function prototype or function declaration */
/* we have passed an asterisk symbol (dereferencing operator) in argument to receive the address i.e pointer variable */

void push(stack *, int);
int pop(stack *);
void init(stack *, int);
void deallocate(stack *);
int getSize(stack*);


int main()
{
   stack s1;    /* Creating variable s1 and s2 of data type stack */

   init(&s1, 3);       /* We will do initialization first to avoid garbage values */


int choice, value;

printf("1. Push\n2. Pop\n3. Exit");  /* A display message for users */

while(1)

    {
          printf("\nEnter choice");
          scanf("%d",&choice);
          printf("Size of stack : %d\n",getSize(&s1));

              switch (choice)
                {
                    case 1: printf("\nEnter value:");
                             scanf("%d", &value);
                             push(&s1, value);
                             break;

                    case 2: value = pop(&s1);

                            if(value !=-9999)
                               {
                                   printf("Popped data will be %d",value);
                               }
                            break;


                    case 3: deallocate(&s1);                 /* Deallocating memory before exit*/
                            exit(0);                         /* To exit the console */

                     default : printf("Invalid choice\n");   /* For invalid choices */

                }



    }

    return 0;

}
