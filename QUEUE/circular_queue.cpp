//There was loophole in queue data structure due to which we were unable
// to access the space properly as there wasn't any method to come backward
// and use the space which were freed up by dequeue operation
//so we came up with the idea of circular queue.

#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;

class queue
{
private:

    int item[SIZE];
    int rear;
    int front;

public:

    void enqueue(int);
    int dequeue();
    void menu();

//In circular queue we will initialize the front and rear with size-1
//and at the beginning both rear and front will be at same index i.e size-1
    queue()
    {
        rear = SIZE - 1;
        front = SIZE -1;
    }
};

void queue :: enqueue(int value)
{
   if((rear + 1) % SIZE == front) //This is the overflow condition
    // if adding one index we will come to the index of the front then it will be overflow condition
   {
        cout<<"Queue overflow"<<endl;
        return;
   }

   rear = (rear + 1) % SIZE; //This is to move the rear to the next element
   // and when rear will be equal to size then it will move the rear to 0th index
   item[rear] = value;

}

int queue :: dequeue()
{
    if(rear == front)
    {
        cout<<"Queue underflow"<<endl;
        return -9999;
    }

    front = (front +1) % SIZE;//This is to move the front to the next element
   // and when front will be equal to size then it will move the front to 0th index

    int value = item[front];
    return value;

}
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







