#include<stdio.h>
#include<stdlib.h>
void print_list(int[], int);
void ins_sort(int[], int);

void print_list(int ins_st_el[], int count)
{
  int i;
  for(i=0; i<count; i++)
  {
    printf("| %d |", ins_st_el[i]);
  }
}

void ins_sort(int ins_st_el[], int count)
{
  int i,j;
  for (j=1; j<count; j++)
  {
    i = j-1;
    int key = ins_st_el[j];
    while(i>=0 && ins_st_el[i]>key)
    {
      ins_st_el[i+1] = ins_st_el[i];
      i = i-1;
    }
    ins_st_el[i+1] = key;
  }

}

int main()
{
  int count, i, ins_st_el[100];
  printf("How many numbers you want to sort : ");
  scanf("%d", &count);

  printf("Enter %d elements : ", count);
  for(i=0; i<count; i++)
  {
    scanf("%d", &ins_st_el[i]);
  }
  printf("Here is your unsorted list : \n");
  print_list(ins_st_el, count);

  ins_sort(ins_st_el, count);

  printf("\n\nand here is your sorted list :\n");
  print_list(ins_st_el, count);

  return 0;

}
