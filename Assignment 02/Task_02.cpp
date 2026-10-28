#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data=value;
        next=NULL;
    }
};

class Stack 
{
private:
    Node* top;
    int count;

public:
    Stack() 
    {
        top=NULL;
        count=0;
    }

    ~Stack() 
    {
        while(top!=NULL) 
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    bool isEmpty() 
    {
        return top==NULL;
    }

    int size() 
    {
        return count;
    }

    void push(int value) 
    {
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        count++;
    }

    int pop() 
    {
        if(top==NULL) 
        {
            return 0;
        }
        Node* temp=top;
        int value=temp->data;
        top=top->next;
        delete temp;
        count--;
        return value;
    }

    int peek() 
    {
        if(top==NULL) 
        {
            return 0;
        }
        return top->data;
    }

    void display() 
    {
        Node* move=top;
        while(move!=NULL) 
        {
            cout << move->data << " ";
            move=move->next;
        }
        cout << endl;
    }
};

int main() 
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    while(n<1) 
    {
        cout << "Number of disks must be at least 1. Enter again: ";
        cin >> n;
    }

    Stack rods[3];

    for(int i=n;i>=1;i--) 
    {
        rods[0].push(i);
    }

    int minMoves=1;
    for(int i=0;i<n;i++) 
    {
        minMoves=minMoves*2;
    }
    minMoves=minMoves-1;

    cout << "Minimum moves required: " << minMoves << endl;

    int moves=0;

    while(rods[2].size()!=n) 
    {
        cout << endl;
        cout << "Rod A: ";
        rods[0].display();
        cout << "Rod B: ";
        rods[1].display();
        cout << "Rod C: ";
        rods[2].display();
        cout << endl;

        char from, to;

        cout << "Move disk from rod: ";
        cin >> from;
        while(from<'A' || from>'C' || rods[from-'A'].isEmpty()) 
        {
            cout << "Enter A, B or C (rod must have a disk): ";
            cin >> from;
        }

        cout << "To rod: ";
        cin >> to;
        while(to<'A' || to>'C' || to==from) 
        {
            cout << "Enter A, B or C (different from source): ";
            cin >> to;
        }

        int src=from-'A';
        int dst=to-'A';
        int disk=rods[src].peek();

        if (!rods[dst].isEmpty() && disk>rods[dst].peek()) 
        {
            cout << "Invalid move! A larger disk cannot go on a smaller one." << endl;
        }
        else 
        {
            rods[src].pop();
            rods[dst].push(disk);
            moves++;
        }
    }

    cout << endl;
    cout << "Rod A: ";
    rods[0].display();
    cout << "Rod B: ";
    rods[1].display();
    cout << "Rod C: ";
    rods[2].display();

    cout << endl << "You won!" << endl;
    cout << "Your moves: " << moves << endl;
    cout << "Minimum moves: " << minMoves << endl;

    if (moves == minMoves) 
    {
        cout << "Perfect! You solved it in the minimum number of moves." << endl;
    }

    return 0;
}