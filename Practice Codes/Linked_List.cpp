#include <iostream>
using namespace std;

class Node *head = NULL;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void push_front()
{
    if (head != NULL)
    {
        int value;
        cout << "Enter an integer value: ";
        cin >> value;
        Node *temp = new Node(value);
        temp->next = head;
        head = temp;
    }
    else
    {
        int value;
        cout << "Enter integer value: ";
        cin >> value;
        Node *newnode = new Node(value);
        head = newnode;
    }
}

void push_back()
{
    int value;
    if(head==NULL)
    {
        cout << "Enter an integer: ";
        cin >> value;
        Node* newnode=new Node(value);
        head=newnode;
    }
    else
    {
        Node* move=head;
        while(move->next!=NULL)
        {
            move=move->next;
        }
        cout << "Enter an integer: ";
        cin >> value;
        Node* newnode=new Node(value);
        move->next=newnode;
        newnode->next=NULL;
    }
}

void show_list()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int n;
    while (true)
    {
        cout << "Creating a Linked List" << endl;
        cout << "1. Insert at first\n2. Insert at end\n3. Show list\n4. Exit" << endl;
        cout << "Select an option: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            push_front();
        }
        break;
        case 2:
        {
            push_back();
        }
        break;
        case 3:
        {
            show_list();
        }
        break;
        case 4:
        {
            return 0;
        }
        }
    }
}