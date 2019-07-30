
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




