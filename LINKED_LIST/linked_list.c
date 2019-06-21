#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
    int data;
    struct Node * next;

}Node;

typedef struct
{
    struct Node * head;
    struct Node * tail;
    int nodeCount;
}linkedList;

//Function prototype
void menu();
void init(linkedList *);
int loadFromFile(linkedList *, char *);
void createRandomList(linkedList *, int);
void insertAtHead(linkedList *, int);
void insertAtTail(linkedList *, int);
void printListDetails(linkedList *);
void printListData(linkedList *);
Node * find(linkedList *, int, Node **);
int deleteAtHead(linkedList *);
int deleteAtTail(linkedList *);
int deleteTarget(linkedList *, int);
void reverse(linkedList *);

//Function definition

void menu()
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

void init(linkedList * lstPtr)
{
    lstPtr->head = NULL;
    lstPtr->tail = NULL;
    lstPtr->nodeCount = 0;
}

void createRandomList(linkedList *lstPtr, int num)
{
    int i, k;
    srand(time(NULL));
    for (i=0; i<num; i++)
    {
        k = rand() % 1000;
        insertAtTail(lstPtr, k);
    }

}

void insertAtTail(linkedList *lstPtr, int data)
{
    Node *newNodePtr = (Node*)malloc(sizeof(Node));
    if(newNodePtr == NULL)
    {
        printf("Memory cannot be allocated\n");
        return;
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;

    if(lstPtr->nodeCount == 0)
    {
        lstPtr->head = newNodePtr;
        lstPtr->tail = newNodePtr;
    }
    else
    {
       lstPtr->tail->next = newNodePtr;
       lstPtr->tail = newNodePtr;

    }
    lstPtr->nodeCount++;
}


void insertAtHead(linkedList * lstPtr, int data)
{
    Node * newNodePtr = (Node *)malloc(sizeof(Node));
    if(newNodePtr == NULL)
    {
        printf("Memory cannot be allocated for node");
        return;
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;

    if(lstPtr->nodeCount == 0)
    {
        lstPtr->head = newNodePtr;
        lstPtr->tail = newNodePtr;
    }
    else
    {
        newNodePtr->next = lstPtr->head;
        lstPtr->head = newNodePtr;
    }

    lstPtr->nodeCount++;

}

void printListData(linkedList * lstPtr)
{

    if(lstPtr->nodeCount == 0)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
         Node * current = lstPtr->head;
        while(current != NULL)
        {
            printf("%d \n", current->data);

            current = current->next;
        }
    }
}

void printListDetails(linkedList * lstPtr)
{
    if(lstPtr->nodeCount == 0)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {

        Node *current = lstPtr->head;
        printf("\nHEAD : %p ", lstPtr->head);
        printf("\n\n");
        int count = 0;
        printf("Sl.no  | Node address | Node data | Next address  \n");
    while(current != NULL)
    {

        printf("%d      | %p     | %d         | %p \n", count, current, current->data, current->next);
        current = current->next;
        count++;
    }
    printf("\nTAIL : %p", lstPtr->tail);
    printf("\n\n");
    }
}

int loadFromFile(linkedList *lstPtr, char *fileName)
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
      insertAtTail(lstPtr, data);
      fscanf(fp, "%d", &data);
    }
    fclose(fp);
    return 1;
}

Node * find(linkedList * lstPtr, int target, Node ** prev)


{
        *prev = NULL;
        Node * current = lstPtr->head;
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

int deleteAtHead(linkedList * lstPtr)
{
    if(lstPtr->nodeCount == 0)
    {
        return -9999;
    }
    Node *first = lstPtr->head; //keeping the address of head in first variable to free the memory later.
    int data = first->data;
    if (lstPtr->nodeCount == 1)
    {
        lstPtr->head == NULL;
        lstPtr->tail == NULL;
    }
    else
    {
        lstPtr->head = first->next;
    }
    free(first);
    lstPtr->nodeCount--;
    return data;

}

int deleteAtTail(linkedList * lstPtr)
{
    if(lstPtr->nodeCount == 0)
    {
        return -9999;
    }
    Node *last = lstPtr->tail; //keeping the address of head in first variable to free the memory later.
    int data = last->data;
    if (lstPtr->nodeCount == 1)
    {
        lstPtr->head == NULL;
        lstPtr->tail == NULL;
    }
    else
    {

        Node *current = lstPtr->head;
        Node * prev = NULL;
        while(current != NULL)
        {
            prev = current;
            current = current ->next;
        }


        lstPtr->tail = prev;
        prev->next = NULL;
    }

    free(last);
    lstPtr->nodeCount--;
    return data;

}

int deleteTarget(linkedList * lstPtr, int target)
{
    Node *current = NULL;
    Node * prev = NULL;

    current = find (lstPtr, target, &prev);
    int data = current->data;
    if(current == NULL)
    return -9999;
    if(target == lstPtr->head->data)
        deleteAtHead(lstPtr);
    if(target == lstPtr->tail->data)
        deleteAtTail(lstPtr);
    else
    {
        prev->next = current->next;
        free(current);
        lstPtr->nodeCount--;
        return data;
    }

}

void reverse(linkedList * lstPtr)
{
    if (lstPtr->nodeCount <= 1)
        return;


    Node *p, *q, *r;
    q = NULL;
    p = lstPtr->head;
    r = p->next;

    while(1)
     {
        p->next = q;

        if(p == lstPtr->tail)
            break;

            q = p;
            p = r;
            r = r->next;
     }

        lstPtr->tail = lstPtr->head;
        lstPtr->head = p;

}




int main()
{
    linkedList list;
    init(&list);
    menu();
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
                success = loadFromFile(&list, "num.txt");
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
                 createRandomList(&list, data);
                 break;

        case 3:
                 printf("Enter the number you want to insert : ");
                 scanf("%d",&data);
                 insertAtTail(&list, data);
                 break;

        case 4:
                 printf("Enter the number you want to insert : ");
                 scanf("%d",&data);
                 insertAtHead(&list, data);
                 break;

        case 5:
                 printListDetails(&list);
                 break;

        case 6:
                 printListData(&list);
                 break;

        case 7:
                 printf("Enter target to find :");
                 scanf("%d",&data);
                 current = find(&list, data, &prev);
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
                 data = deleteAtHead(&list);
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
                 data = deleteAtTail(&list);
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
                  success = deleteTarget(&list, data);
                  if (success == -9999)
                    printf("Linked list is empty.\n");
                  else
                    printf("Target is deleted, data : %d\n", success);
                  break;

        case 11:
                 reverse(&list);
                 break;

        case 12:
                 exit(0);
                 break;

        deafult :
                   printf("Invalid choice\n");




        }
    }
}

