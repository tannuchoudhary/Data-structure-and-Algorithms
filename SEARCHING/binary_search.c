//------------------------------------------------------------------------------
//-------------------------BINARY SEARCH----------------------------------------

#include<stdio.h>
int binary_search(int[], int, int, int);

int binary_search(int a[], int lb, int ub, int target)
{
    int success=0, mid = (lb + ub)/2;
    if(mid >0)
  {
    if(a[mid] == target)//if element is found.
   {
     printf("Element %d  found at position no. = %d", target, mid+1);
     success = 1;
   }
  if(a[mid]>target)//if target is at left side of the middle element.
  {
    binary_search(a, lb, mid, target); //resursion for checking all the numbers.
  }
  if(a[mid]<target)//if target is at right side of the middle element.
   {
     binary_search(a, mid, ub, target);
   }

  }
  return success;
}
int main()
{
  int a[5] = {11,32,63,74,95};
  int i, target, n = sizeof(a)/sizeof(a[0]), success;
  printf("Here is the array list:\n");
  for(i=0; i<n; i++)
  {
    printf("| %d |", a[i]);
  }
  printf("\nEnter the number you want to search in the array :");
  scanf("%d", &target);
  success = binary_search(a, 0, n, target);
  if(success != 1)
  printf("Element not found.");

  return 0;
}

