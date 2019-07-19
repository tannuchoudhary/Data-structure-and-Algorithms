
#include<stdio.h>
void input(int *p)
{
    int i;
    for(i=0;i<=4;i++)
        scanf("%d",(p+i));
}
void display(int *p)
{
    int i;
    for(i=0;i<5;i++)
        printf("%d",*(p+i));
}
 void sort(int *p )
 {
    int i,j,crnt;
    for(i=1;i<=4;i++)
    {
       crnt = *(p+i);
       for(j=i;j>0;j--)
       {
           if(*(p+j-1)<crnt)
            break;
            *(p+j)=*(p+j-1);
       }
       *(p+j)=crnt;
    }
 }
int main()
{
    int a[5];
    printf("Enter five numbers:");
    input(a);
    display(a);
    printf("\n");
    sort(a);
    display(a);
    return 0;
}




/*************************************************************************************************************************************
**************************************************************************************************************************************/



/*Just another piece of code of insertion sort without using pointers*/

#include<stdio.h>
int main()
{
  int a[100], count, i, key, j=1, k=2;

  printf("How many numbers you want to sort: ");
  scanf("%d", &count);

  printf("Enter your numbers:\n");
  for(i=0; i<count; i++)
  {
    scanf("%d", &a[i]);
  }

  key = a[k]; /*Storing the second element into the variable*/
  /* As if it will not be done, we may overwrite th original number*/
   
  j = k-1; /*start k with one less than j*/

  while(j>0 && a[j]>key) /*If the element is greater than the key then they will be arranged
                          and loop will run for all previous elements*/
  {
    a[j +1] = a[j];
    j = j-1;
  }

  a[j+1] = key;
  printf("Here is the sorted list: \n");
  for(i=0; i<count; i++) /*Printing the sorted list*/
  {
    printf("%d\n", a[i]);
  }

  return 0;
}

