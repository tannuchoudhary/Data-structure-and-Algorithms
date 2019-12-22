#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
}Node;

typedef struct{
  struct Node *head;
  struct Node *tail;
  int count;
}doublyLL;

void initlist(doublyLL *);
void insert_at_tail(doublyLL *, int);
void printdata(doublyLL *);
void rotate(doublyLL *);

void initlist(doublyLL *listptr){
  listptr->head = NULL;
  listptr->tail = NULL;
  listptr->count = 0;
}

void insert_at_tail(doublyLL *listptr, int data){
  Node *newnodeptr = (Node *)malloc(sizeof(Node));
  if(newnodeptr == NULL){
    printf("Can't insert at tail.\n");
  }
    newnodeptr->data = data;
    newnodeptr->left = NULL;
    newnodeptr->right = NULL;
    if(listptr->count ==0){
      listptr->head = newnodeptr;
      listptr->tail = newnodeptr;
    }
    else{
      listptr->tail->right = newnodeptr;
      newnodeptr->left = listptr->tail;
      listptr->tail = newnodeptr;
    }

  listptr->count++;
}

void printdata(doublyLL *listptr){
  if(listptr->count == 0)
  printf("Linked list is empty.\n");
  Node *current = listptr->head;
  while(current != NULL){
    printf("%d ", current->data);
    current = current->right;
  }
}
 void rotate(doublyLL * listptr){
   Node * temp;
   listptr->head->left = listptr->tail;
   listptr->head->right->left = NULL;
   temp = listptr->head->right;
   listptr->head->right = NULL;
   listptr->tail->right = listptr->head;
   listptr->tail = listptr->head;
   listptr->head = temp;
 }

int main(){
  doublyLL list;
  int n;
  initlist(&list);
  insert_at_tail(&list, 1);
  insert_at_tail(&list, 2);
  insert_at_tail(&list, 3);
  insert_at_tail(&list, 4);
  insert_at_tail(&list, 5);
  insert_at_tail(&list, 6);
  printf("This is your linked list.\n");
  printdata(&list);
  printf("\n");
  printf("Upto how many places do you want to rotate your linked list: ");
  scanf("%d", &n);
  for(int i=0; i<n; i++){
  rotate(&list);
}
  printdata(&list);

  return 0;
}
