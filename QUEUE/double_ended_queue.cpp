//This is the operation for double ended queue in which we can do the following operations :
//1. Insertion at rear.
//2. Deletion from rear.
//3. Insertion at front.
//4. Deletion from front

//i.e we can do insertion and deletion from both sides unlike normal queue or circular queue

#include<iostream>
#include<stdlib.h>

#define SIZE 5

using namespace std;

//Class for queue

class queue
{

private:

    int item[SIZE];
    int rear, front;

public:
//Member functions

    void INS_AT_REAR(int);
    int DEL_FROM_REAR();
    void INS_AT_FRONT(int);
    int DEL_FROM_FRONT();
    void menu();

//Constructor for initialization of front and rear
//We will initialize front from zero and rear from one

queue()
    {
        front = 0;
        rear = -1;
    }

};

//Function definition

void queue :: INS_AT_REAR(int value)
{
    if(rear == SIZE-1)
    {
        cout<<"Unable to add at rear"<<endl;
        return;
    }

    rear++;
    item[rear] = value;


}

int queue :: DEL_FROM_REAR()
{
    if(front>rear)
    {
        cout<<"Queue underflow"<<endl;
        return -9999;
    }
     int value;
     value = item[rear];
     rear--;
     return value;

}

void queue :: INS_AT_FRONT(int value)
{
    if(front == 0)
    {
        cout<<"Unable to add at front"<<endl;
        return;
    }
    front --;
    item[front] = value;

}

int queue :: DEL_FROM_FRONT()
{
    if(front > rear)
    {
        cout<<"Queue underflow"<<endl;
        return -9999;
    }

    int value = item[front];
    front++;
    return value;
}

//Menu for displaying
void queue :: menu()
{
    cout<<"---------------QUEUE MENU----------------"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"1.Insertion at rear "<<endl;
    cout<<"2.deletion from rear "<<endl;
    cout<<"3.Insertion at front "<<endl;
    cout<<"4.Deletion from front "<<endl;
    cout<<"5.Exit"<<endl;
}

int main()
{
    queue q1;
    int choice;

    q1.menu();

    while(1)
    {
        cout<<endl<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:

           int num;
           cout<<endl<<" Enter the number you want to insert at rear : ";
           cin>>num;
           q1.INS_AT_REAR(num);
           break;

        case 2:

            int value_;
            value_ = q1.DEL_FROM_REAR();
            if(value_ == -9999)
            {
                cout<<endl<<"Can't perform dequeue operation."<<endl;
            }
            cout<<endl<<" "<<value_<<" is deleted."<<endl;
            break;
        case 3:

            int num2;
            cout<<endl<<"Enter the number you want to insert at front : ";
            cin>>num2;
            q1.INS_AT_FRONT(num2);
            break;

        case 4:

            int value2;
            value2 = q1.DEL_FROM_FRONT();
            if(value2 == -9999)
            {
                cout<<endl<<"Can't perform dequeue operation."<<endl;
            }
            cout<<endl<<" "<<value2<<" is deleted."<<endl;
            break;

        case 5:

            exit(0);
            break;

        default :

            cout<<endl<<"Invalid choice"<<endl;
        }
    }

    return 0;
}






