#include<stdio.h>
#include<stdlib.h>
#include<time.h>

class Node
{
public:

    int data;
    struct Node * next;

};

class linkedList
{
public:

    struct Node * head;
    struct Node * tail;
    int nodeCount;


//Function prototype
void menu();
int loadFromFile(char *);
void createRandomList(int);
void insertAtHead(int);
void insertAtTail(int);
void printListDetails();
void printListData();
Node * find_(int, Node **);
int deleteAtHead();
int deleteAtTail();
int deleteTarget(int);
void reverse_();

 linkedList()
{
   head = NULL;
   tail = NULL;
   nodeCount = 0;
}

};
//Function definition

void linkedList :: menu()
{
    printf("1. Load from file\n");
    printf("2. Create random list\n");
    printf("3. Insert at tail\n");
    printf("4. Insert at head\n");
    printf("5. Print list (details)\n");
    printf("6. Print list (data only)\n");
    printf("7. Find\n");
    printf("8. Delete at head\n");
    printf("9. Delete at tail\n");
    printf("10. Delete target\n");
    printf("11. Reverse\n");
    printf("12. Quit\n");
}


void linkedList :: createRandomList(int num)
{
    int i, k;
    srand(time(NULL));
    for (i=0; i<num; i++)
    {
        k = rand() % 1000;
        insertAtTail(k);
    }

}

void linkedList :: insertAtTail(int data)
{
    Node *newNodePtr = (Node*)malloc(sizeof(Node));
    if(newNodePtr == NULL)
    {
        printf("Memory cannot be allocated\n");
        return;
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;

    if(nodeCount == 0)
    {
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
       tail->next = newNodePtr;
       tail = newNodePtr;

    }
    nodeCount++;
}


void linkedList :: insertAtHead(int data)
{
    Node * newNodePtr = (Node *)malloc(sizeof(Node));
    if(newNodePtr == NULL)
    {
        printf("Memory cannot be allocated for node");
        return;
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;

    if(nodeCount == 0)
    {
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        newNodePtr->next = head;
        head = newNodePtr;
    }

    nodeCount++;

}

void linkedList :: printListData()
{

    if(nodeCount == 0)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
         Node * current = head;
        while(current != NULL)
        {
            printf("%d \n", current->data);

            current = current->next;
        }
    }
}

void linkedList :: printListDetails()
{
    if(nodeCount == 0)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {

        Node *current = head;
        printf("\nHEAD : %p ", head);
        printf("\n\n");
        int count_ = 0;
        printf("Sl.no  | Node address | Node data | Next address  \n");
    while(current != NULL)
    {

        printf("%d      | %p     | %d         | %p \n", count_, current, current->data, current->next);
        current = current->next;
        count_++;
    }
    printf("\nTAIL : %p", tail);
    printf("\n\n");
    }
}

int linkedList :: loadFromFile(char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        return 0;
    }
    int data;
    fscanf(fp, "%d", &data);
    while(!feof(fp))
    {
      insertAtTail(data);
      fscanf(fp, "%d", &data);
    }
    fclose(fp);
    return 1;
}

Node * linkedList ::  find_(int target, Node ** prev)


{
        *prev = NULL;
        Node * current = head;
        while(current != NULL)
        {
            if(current->data == target)
            {

                break;
            }

                *prev  = current;
                current = current->next;

    }
    return current;
}

int linkedList :: deleteAtHead()
{
    if(nodeCount == 0)
    {
        return -9999;
    }
    Node *first = head; //keeping the address of head in first variable to free the memory later.
    int data = first->data;
    if (nodeCount == 1)
    {
        head == NULL;
        tail == NULL;
    }
    else
    {
        head = first->next;
    }
    free(first);
    nodeCount--;
    return data;

}

int linkedList :: deleteAtTail()
{
    if(nodeCount == 0)
    {
        return -9999;
    }
    Node *last = tail; //keeping the address of head in first variable to free the memory later.
    int data = last->data;
    if (nodeCount == 1)
    {
        head == NULL;
        tail == NULL;
    }
    else
    {

        Node *current = head;
        Node * prev = NULL;
        while(current != NULL)
        {
            prev = current;
            current = current ->next;
        }


        tail = prev;
        prev->next = NULL;
    }

    free(last);
    nodeCount--;
    return data;

}

int linkedList :: deleteTarget(int target)
{
    Node *current = NULL;
    Node * prev = NULL;

    current = find_(target, &prev);
    int data = current->data;
    if(current == NULL)
    return -9999;
    if(target == head->data)
        deleteAtHead();
    if(target == tail->data)
        deleteAtTail();
    else
    {
        prev->next = current->next;
        free(current);
        nodeCount--;
        return data;
    }

}

void linkedList :: reverse_()
{
    if (nodeCount <= 1)
        return;


    Node *p, *q, *r;
    q = NULL;
    p = head;
    r = p->next;

    while(1)
     {
        p->next = q;

        if(p == tail)
            break;

            q = p;
            p = r;
            r = r->next;
     }

        tail = head;
        head = p;

}




int main()
{
    linkedList list;

    list.menu();
    int data, choice, success;
    Node * current = NULL;
    Node * prev = NULL;

    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
                success = list.loadFromFile("num.txt");
                if (success == 1)
                {
                    printf("File has been loaded successfully.\n");
                }
                else
                    printf("Unable to load file\n");

                break;

        case 2:
                 printf("Enter number of integers to be generated : ");
                 scanf("%d",&data);
                 list.createRandomList(data);
                 break;

        case 3:
                 printf("Enter the number you want to insert : ");
                 scanf("%d",&data);
                 list.insertAtTail(data);
                 break;

        case 4:
                 printf("Enter the number you want to insert : ");
                 scanf("%d",&data);
                 list.insertAtHead(data);
                 break;

        case 5:
                 list.printListDetails();
                 break;

        case 6:
                 list.printListData();
                 break;

        case 7:
                 printf("Enter target to find :");
                 scanf("%d",&data);
                 current = list.find_(data, &prev);
                 if(current == NULL)
                 {
                     printf("Target not found\n");
                 }
                 else
                 {
                     printf("Target node exists, address of the target node :%p, previous : %p\n", current , prev);
                 }
                 break;

        case 8:
                 data = list.deleteAtHead();
                 if(data == -9999)
                 {
                     printf("Linked list is empty\n");
                 }
                 else
                 {
                    printf("First node is deleted, data : %d\n", data);
                 }
                 break;

        case 9:
                 data = list.deleteAtTail();
                 if(data == -9999)
                   {
                     printf("Linked list is empty\n");
                   }
                 else
                   {
                      printf("Last node is deleted, data : %d\n", data);
                   }
                 break;
        case 10:
                  printf("Enter the target you want to delete : ");
                  scanf("%d", &data);
                  success = list.deleteTarget(data);
                  if (success == -9999)
                    printf("Linked list is empty.\n");
                  else
                    printf("Target is deleted, data : %d\n", success);
                  break;

        case 11:
                 list.reverse_();
                 break;

        case 12:
                 exit(0);
                 break;

        default :
                   printf("Invalid choice\n");
                   //exit(0);



        }
    }
}


