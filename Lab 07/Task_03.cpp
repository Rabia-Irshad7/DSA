
#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
    public:
    int data;
    int priority;
    Node* next;

    Node(int value, int p)
    {
        data=value;
        priority=p;
        next=NULL;
    }
};

class Queue
{
    public:
    Node* front=NULL;

    void enqueue(int value, int p)
    {
        Node* newNode=new Node(value, p);

        if(front==NULL || p<front->priority)
        {
            newNode->next=front;
            front=newNode;
        }
        else
        {
            Node* move=front;

            while(move->next!=NULL && move->next->priority<=p)
            {
                move=move->next;
            }

            newNode->next=move->next;
            move->next=newNode;
        }

        cout << "Element added successfully" << endl;
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout << "Priority queue is empty" << endl;
            return;
        }

        Node* temp=front;
        cout << temp->data << " removed (Priority: " << temp->priority << ")" << endl;
        front=front->next;
        delete temp;
    }

    void display()
    {
        if(front==NULL)
        {
            cout << "Priority queue is empty" << endl;
            return;
        }

        Node* current=front;

        while(current!=NULL)
        {
            cout << "Element: " << current->data << endl; 
            cout << "Priority: " << current->priority << endl;
            current=current->next;
        }
    }

};

int main()
{
    Queue q;
    int choice, value, p;

    while (true)
    {
        cout << "Priority Queue" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Enter element: ";
                cin >> value;
                cout << "Enter priority (1=highest): ";
                cin >> p;
                q.enqueue(value, p);
                cout << "Press anykey to continue..." << endl;
                getch();
                break;
            }

            case 2:
            {
                q.dequeue();
                cout << "Press anykey to continue..." << endl;
                getch();
                break;
            }

            case 3:
            {
                q.display();
                cout << "Press anykey to continue..." << endl;
                getch();
                break;
            }

            case 4:
            {
                return 0;
            }

            default:
            {
                cout << "Invalid input" << endl;
                cout << "Press any key to continue: " << endl;
                getch();
            }
        }
    }
}
