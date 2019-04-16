#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
   char * item ;
   int top;
   int size;
}stack;


/*Function prototype*/

void push(stack *, char);
char pop(stack *);
void init(stack *, int);
void deallocate(stack *);
int isUnderflow(stack *);   /*Just made shortcuts for underflow and overflow condition*/
int isOverflow(stack *);
//int reverse(char, char);


/*Function definition*/

int isOverflow(stack *sp)
{
    return sp->top == sp->size-1;
}

int isUnderflow(stack *sp)
{
    return sp->top == -1;
}


void push(stack *sp, char value)
{
    if(isOverflow(sp))
    {
       char * temp;
       int i;
       temp = (char *)malloc(sizeof(char) * sp->size * 2);

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

char pop(stack *sp)
{
    if(isUnderflow(sp))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    char value;
    value = sp->item[sp->top];
    sp->top--;
    return value;
}

void init(stack *sp, int size)
{
    sp->top = -1;
    sp->item = (char*)malloc(sizeof(char)*size);
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
    sp->top = -1;
    sp->size =0;
}

int reverse(char source_file[], char dest_file[])
{
    FILE *fps, *fpd;
    const int SIZE = 50;
    fps = fopen(source_file,"r");

    if(fps == NULL)
    {
        printf("Source file %d cannot be opened.\n", source_file);
        return 0;
    }

    fpd = fopen(dest_file, "w");

    if(fpd == NULL)
    {
        printf("Destination file %d cannot be opened.\n", dest_file);
        return 0;
    }

    stack s;
    init(&s, SIZE);

    char buff;
    buff = fgetc(fps);

    while(!feof(fps))
    {
        push(&s, buff);
        buff = fgetc(fps);
    }

    while(!isUnderflow(&s))
    {
       fputc(pop(&s), fpd);

    }

    fclose(fps);
    fclose(fpd);
    deallocate(&s);
    return 1;


}

int main()
{
   int f;

   f = reverse("ds_tannu.txt", "reverse_ds_tannu.txt");
   if(f)
      printf("File copied successfully.\n");
   else
    printf("Error in copying file.\n");

   return 0;

}
