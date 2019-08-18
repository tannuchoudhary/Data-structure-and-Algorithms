# GREEDY KNAPSACK

Though the problem was simple but it took little time for me to understand the whole concept

First of all, in this knapsack problem we have to fill the weight in the bag (having limited capacity) such that  the total profit obtained should be the maximum.

so there are two types of solution in this

1. **Knapsack** - In knapsack, the rule is  that you can't break the weight, so either add the whole weight in the bag or don't add it.
2. **Fractional knapsack** - In fractional knapsack , you can add any fraction of weight i.e by breaking it.

So, what would i recquire to code whole knapsack problem

step 1- Find profit by weight ratio

step 2 - sort the object in decreasing order of profit by weight ratio

step 3- fill the knapsack

* For sorting, i am going to use sort function using STL(standard template library) in c++, and it is used something like this

  * For sorting in ascending order
  
  `sort(array, array + n);`
  
  here n is the size of the array
  
  * For descending order
  
  `sort(array, array + n, greater<int>());`
  
  here greater() function does a comparison in a way that puts greater element before.
  
  In place of greater function, we can use this-
  
  

 

 

