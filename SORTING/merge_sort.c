/*----------------MERGE SORT-----------------------------
---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

void merging(int[], int, int, int);
void merge_sort(int[], int, int);
void print_array(int[], int );


/*The process "merging" is for merging an array A  in which the array is sorted from p to q and then q+1 to r*/

void merging(int A[], int p, int q, int r)
{
  int n1 = q-p+1;
  int n2 = r-q;

/*Assigning all the sorted values into two  lists naming List1 and List2 and then we will compare all the values of
both the lists and the one which will be smaller will be assigned into the new array and in this way all the elements will get sorted*/

  int List1[n1];  /*First list will be from p to q*/
  int List2[n2];  /* and second list will be from q+1 to r*/
  int i, j, k;
  for (i=0; i<n1; i++)
  {
    List1[i] = A[p+i]; /*Assigning all the values from p to q into array A to list 1*/
  }

  for(j=0; j<n2; j++ )
  {
    List2[j] = A[q + 1 + j]; /*Assigning all the elements from q+1 to r into array A to list 2*/
  }

  i=0;
  j=0;
  k=p;


  while(i<n1 && j<n2)

  {
    /*After comparison assign the smallest value into the original array*/
    if(List1[i] <= List2[j])
    {
      A[k] = List1[i];
       i++;
    }

    else
    {
      A[k] = List2[j];
      j++;
    }
    k++;
  }

  /*If any one of the array ends and the second one is remaining then we will just print the second array as no elements are remained for comparisons*/ 
  while (i<n1)
  {
    A[k] = List1[i];
    i++;
    k++;
  }

  while (j<n2)
  {
    A[k] = List2[j];
    j++;
    k++;
  }
}

/*Before merging we need to divide the array into two parts and this process will be done by recursion by calling the function again and again*/

void merge_sort(int A[], int p, int r)
{
  if(p<r)
  {
    int q = (p+r)/2;

     merge_sort(A, p, q);
     merge_sort(A, q+1, r);
     merging(A, p, q, r);
  }
}

/*This function is for printing an array*/
void print_array(int A[], int size)
{
  int i;

  for(i=0; i<size; i++)
  {
    printf("%d\n", A[i]);
  }
}

int main()
{
  int count, i, A[100], j;

  printf("How many numbers you want to sort : ");
  scanf("%d", &count );

  printf("Enter all the numbers you want to sort :\n");
  for(i=0; i<count; i++)
  {
    scanf("%d",&A[i]);
  }
  printf("\n\nThe unsorted list is :\n");
  print_array(A, count);

  merge_sort(A, 0, count-1);

  printf("\n\nThe sorted list is :\n");
  print_array(A, count);

  return 0;

}
