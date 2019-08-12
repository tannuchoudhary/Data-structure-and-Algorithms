//-------------------------------------------------------------------
//----------------------LINEAR SEARCH--------------------------------

#include<stdio.h>
void linear_search(int[], int, int);

void linear_search(int array[], int target, int count)
{
  int i, success;
  for(i=1; i<=count; i++)
  {
    if(target == array[i]) //if we found the target
    {
      printf("The element %d is found and the position of the element is %d.", target, i);
      return;
    }
    else    // if target is not there in the array.
    success = 0;
  }
  if(success == 0)
  {
    printf("Element not found.");
  }

}

int main()
{
  int array[100], count, i, target;
  printf("How many elements do you want in your array : ");
  scanf("%d", &count);
  printf("Enter all your elements :");
  for(i=1; i<=count; i++)
  {
    scanf("%d", &array[i]);  //scanning the elements of an array.
  }
  printf("Your list is\n");
  for(i=1; i<=count; i++)
  {
    printf("| %d |", array[i]); //printing the array list.
  }

  printf("\nEnter the element you want to search : ");
  scanf("%d", &target);
  linear_search(array, target, count); //call linear search function.
  return 0;
}
