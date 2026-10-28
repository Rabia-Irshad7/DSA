#include <iostream>
#include <conio.h>
using namespace std;

int queue[5];
int front=-1, rear=-1;
int SIZE=5;

void enqueue(int value)
{
    if((rear+1)%SIZE==front)
    {
        cout << "Queue is full" << endl;
        return;
    }

    if(front==-1)
    {
        front=0;
    }

    rear=(rear+1)%SIZE;
    queue[rear]=value;

    cout << "Value added to queue" << endl;
}

void dequeue()
{
    if(front==-1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << queue[front] << " removed" << endl;

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%SIZE;
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
        cout << "Front element: " << queue[front] << endl;
    }
}

void display()
{
    if(front==-1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int i=front;

    while(true)
    {
        cout << queue[i] << " ";

        if(i==rear)
        {
            break;
        }

        i=(i+1)%SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "Circular Queue" << endl;
        cout << "1. Add an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Display front element" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                cout << "Press any key to continue..." << endl;
                getch();
                break;
            }

            case 2:
            {
                dequeue();
                cout << "Press any key to continue..." << endl;
                getch();
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
                cout << "Press any key to continue..." << endl;
                getch();
            }
        }
    }
}