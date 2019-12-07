/*--------------CREATING AN EMPTY TREE---------------------------*/
#include<iostream>
using namespace std;
/*Below is the structure for node of a tree, any node of a tree will
 contain data, left pointer(for containing the address of left subtree)
  and right pointer(for containing the address of a right subtree.)
 */
struct treeNode{ 
  int data;
  treeNode *right;
  treeNode *left;  
}
int main(){
  /*For creating a tree you need a root pointer just like head pointer in linked list*/
  
  /*Initially your tree is empty so  root pointer will not contain any address i.e it will contain NULL*/
  
  treeNode *root = NULL;
  return 0;
}
