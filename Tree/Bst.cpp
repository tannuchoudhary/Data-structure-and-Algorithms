#include<iostream>
#include<stdlib.h>

using namespace std;

class BstNode
{


    int data;
    BstNode * left;
    BstNode * right;

public :
    BstNode * GetNewNode(int);
    BstNode * Insert(BstNode * , int);
    bool Search(BstNode * ,int);

    BstNode()
    {
        left = NULL;
        right = NULL;
    }
};

BstNode * BstNode :: GetNewNode(int data)
{
    BstNode *newNode = new BstNode;
    newNode->data = data;
    return newNode;
}

BstNode * BstNode :: Insert(BstNode * root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool BstNode :: Search(BstNode * root, int data)
{
    if(root == NULL)
        return false;
    else if(data == root->data)
         return true;
    else if(data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);

}

int main()
{
    BstNode * root = NULL;
    BstNode node;
    int num;

  root =  node.Insert(root, 10);
  root = node.Insert(root, 25);
  root = node.Insert(root, 69);
  root = node.Insert(root, 12);
   root = node.Insert(root, 45);
  root =  node.Insert(root, 87);

   cout<<endl<<"Enter the number you want to search ";
   cin>>num;

   if(node.Search(root, num) == true)
    cout<<endl<<"FOUND";
   else
    cout<<endl<<"NOT FOUND";

    return 0;

}

