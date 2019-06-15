#include<iostream>
#include<stdlib.h>

#define SIZE 5

using namespace std;

class queue
{
 //Class for queue
private:

    int item[SIZE];
    int rear, front;

public:
//Member functions
    void enqueue(int);
    int dequeue();
    void menu();

//Constructor for initialization of front and rear
queue()
    {
        front = 0;
        rear = 0;
    }

};

//Function definition
void queue :: enqueue(int value)
{
    if(rear == SIZE)
    {
        cout<<"Queue overflow"<<endl;
        return;
    }

    item[rear] = value;
    rear++;

}

int queue :: dequeue()
{
    if(front == rear)
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
    cout<<"1.Enqueue "<<endl;
    cout<<"2.Dequeue "<<endl;
    cout<<"3.Exit "<<endl;
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
           cout<<endl<<" Enter the number you want to insert : ";
           cin>>num;
           q1.enqueue(num);
           break;

        case 2:

            int value_;
            value_ = q1.dequeue();
            if(value_ == -9999)
            {
                cout<<endl<<"Can't perform dequeue operation."<<endl;
            }
            cout<<endl<<" "<<value_<<" is deleted."<<endl;
            break;

        case 3:

            exit(0);
            break;

        default :

            cout<<endl<<"Invalid choice";
        }
    }

    return 0;
}







