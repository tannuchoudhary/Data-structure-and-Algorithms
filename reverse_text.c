/*This is a code where i am going to reverse the characters of a text file using stack and will save them in the other text file*/

/*The basic idea is that we will save all the characters of a file into the stack using push operation and will pop out from the stack 
and we will print them in another file, this needs the basic knowledge of file handling and stack operations*/

/*I have created one file named text_file.txt and have written some content in it and created an empty fle called rev_text_file.txt in 
which the reversed content will be saved*/

/*note: Your text file should be saved in the same folder in which you are going to save your c code*/


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



/*Function definition*/


int isOverflow(stack *sp)
{
    return sp->top == sp->size-1;
}


int isUnderflow(stack *sp)
{
    return sp->top == -1;
}


void push(stack *sp, char value)   /*For pushing an element into a stack*/
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



char pop(stack *sp)     /*For popping an element out of stack*/
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



void init(stack *sp, int size)   /*For initialising the stack and passing the size of the stack*/
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



void deallocate(stack *sp)   /*For deallocation of memory after the whole process*/
{
    if (sp->item != NULL)
    {
        free(sp->item);
    }
    sp->top = -1;
    sp->size =0;
}



int reverse(char source_file[], char dest_file[])  /* This is a function for reversing the characters present in a text file*/
   
{
   
    FILE *fps, *fpd;            /*we will declare two pointer variables of file type, one for the address of source file and the 
                                   other for destination file*/
   
    const int SIZE = 50;         /*We will declare the size of the stack and later it would be increased in case of stack overflow as
                                  we have already made the stack dynamic*/
   
    fps = fopen(source_file,"r"); /*Opening the source file and storing its adress in fps, we will open it in read mode as we have
                                   to read characters from source file only*/  

    if(fps == NULL)               /*In case if there will be any problem in opening the file*/
       
    {
        printf("Source file %d cannot be opened.\n", source_file);
        return 0;
    }

    fpd = fopen(dest_file, "w"); /*Opening the destination file in write mode as we want to write reversed characters in it and if you 
                                  have not created any file for destination then it will be automatically created as it is in write mode*/

    if(fpd == NULL)              /*In case if there will be any problem in opening the file*/
       
    {
         printf("Destination file %d cannot be opened.\n", dest_file);
        return 0;
    }

    stack s;
    init(&s, SIZE);

    char buff;          /*A buff variable is to store characters of the text file*/
   
    buff = fgetc(fps);  /*fgetc is used to take the character from text file and it automatically moves to the next character of
                          text file*/

    while(!feof(fps))  /*we will iterate through the loop until the end of file*/
       
    {
        push(&s, buff); /*and will push the characters into the stack*/
        buff = fgetc(fps); /*and move to the next character*/
    }

    while(!isUnderflow(&s)) 
       
    {
       fputc(pop(&s), fpd); /*we will pop out all characters from the stack after pushing all characters into stack until the
                              stack will underflow*/ 

    }

    fclose(fps);            /*closing the files*/
    fclose(fpd);
    deallocate(&s);         /*deallocating memory*/
    return 1;


}

int main()
{
   int f;

   f = reverse("ds_tannu.txt", "reverse_ds_tannu.txt"); /*passing the name of the file into the function and also remember that
                                                          your text file should be saved in the same folder in which your code is saved*/
   
   /*This f will return either 1 or 0 if it will return 1 then file will be copied succcessfully */
   
   if(f)
      
      printf("File copied successfully.\n");
   else
      
    printf("Error in copying file.\n");

   return 0;

}
