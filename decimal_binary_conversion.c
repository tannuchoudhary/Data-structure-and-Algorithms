/*Conversion of decimal numbers into binary using stack*/

/*The concept is that we will divide the entered number by base number i.e 2 until we will
 get zero and we will store all the remainders in stack until we will get remainder zero and then
 we will print all the remainders by popping them out of stack*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
   int * item ;
   int top;
   int size;
}stack;


/*Function prototype*/

void push(stack *, int);
int pop(stack *);
void init(stack *, int);
void deallocate(stack *);
int isUnderflow(stack *);   /*Just made shortcuts for underflow and overflow condition*/
int isOverflow(stack *);


/*Function definition*/

int isOverflow(stack *sp)
{
    return sp->top == sp->size-1;
}

int isUnderflow(stack *sp)
{
    return sp->top == -1;
}


void push(stack *sp, int value)
{
    if(isOverflow(sp))
    {
       int * temp, i;
       temp = (int *)malloc(sizeof(int) * sp->size * 2);

       if(temp == NULL)
       {
           printf("Stack overflow\n");
           return;
       }

       for(i=0; i<=sp->top; i++)
       {
           temp[i] = sp->item[i];
       }

       free (sp->item);
       sp->item = temp;
       sp->size *= 2;
    }
    sp->top++;
    sp->item[sp->top] = value;
}

int pop(stack *sp)
{
    if(isUnderflow(sp))
    {
        printf("Stack underflow\n");
        return -9999;
    }
    int value;
    value = sp->item[sp->top];
    sp->top--;
    return value;
}

void init(stack *sp, int size)
{
    sp->top = -1;
    sp->item = (int*)malloc(sizeof(int)*size);
    if(sp->item == NULL)
    {
        printf("Memory cannot be allocated\n");
        exit(1);
    }
    sp->size = size;
}

void deallocate(stack *sp)
{
    if (sp->item != NULL)
    {
        free(sp->item);
    }
}

int main()
{
    int num, rem, new_num, temp;
    const int BASE = 2;

    stack s1;
    init(&s1, 10);
    printf("Enter any number :");
    scanf("%d", &num);
    temp = num;

    while (num>0)          /*Loop will run until we will get zero after dividing it by 2*/
    {

        rem = num % BASE;  /*Remainder after dividing by 2 will be stored in rem var*/
        push(&s1, rem);    /*we will push the remainder into stack*/

        num /= BASE;       /*And the value of number will be changed into the number we will get after dividing it by 2*/

    }
    printf("Binary conversion of %d is ", temp);

    while(!isUnderflow(&s1))
    {
        printf("%d",pop(&s1));
    }
    deallocate(&s1);

    return 0;
}
