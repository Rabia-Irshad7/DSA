#include <iostream>
#include <conio.h>
using namespace std;

int queue[5];
int front=-1, rear=-1;

void enqueue(int value)
{
    if(rear==4)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=value; 
    cout << "Value added in queue" << endl;
    cout << "Press any key to continue..." << endl;
    getch();
}

void dequeue()
{
    if(front==-1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        cout << queue[front] << " removed" << endl;

        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }

}

void display_front()
{
    if(front==-1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << queue[front] << endl;
    }
}

void display()
{
    if(front==-1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    while(true)
    {
        cout << "Queue" << endl;
        cout << "1. Add an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Display first elment" << endl;
        cout << "4. Display array" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display_front();
                cout << "Press any key to continue..." << endl;
                getch();
                break;
            }
            case 4:
            {
                display();
                cout << "Press any key to continue..." << endl;
                getch();
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                cout << "Invalid input" << endl;
            }
        }
    }
}