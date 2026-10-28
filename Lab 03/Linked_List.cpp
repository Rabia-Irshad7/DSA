#include <iostream>
#include <conio.h>
using namespace std;

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

class LinkedList
{
public:
    Node *head = NULL;
    int NodeCount = 0;
    void Insert_at_First()
    {
        int value;
        if (head == NULL)
        {
            cout << "Enter value: ";
            cin >> value;
            Node *newnode = new Node(value);
            head = newnode;
            newnode->next = NULL;
            NodeCount++;
        }
        else
        {
            cout << "Enter value: ";
            cin >> value;
            Node *newnode = new Node(value);
            newnode->next = head;
            head = newnode;
            NodeCount++;
        }
    }
    void Insert_at_End()
    {
        int value;
        if (head == NULL)
        {
            cout << "Enter value: ";
            cin >> value;
            Node *newnode = new Node(value);
            head = newnode;
            NodeCount++;
        }
        else
        {
            Node *move = head;
            while (move->next != NULL)
            {
                move = move->next;
            }
            cout << "Enter value: ";
            cin >> value;
            Node *newnode = new Node(value);
            move->next = newnode;
            newnode->next = NULL;
            NodeCount++;
        }
    }
    void Insert_at_Node()
    {
        int value, position;
        if (head == NULL)
        {
            cout << "List is empty\nEnter a value to create head: ";
            cin >> value;
            Node *newnode = new Node(value);
            head = newnode;
            NodeCount++;
        }
        else
        {
            cout << "No.of nodes in the list: " << NodeCount << endl;
            cout << "Enter the position where you want to insert the new node: ";
            cin >> position;
            while (position < 0 || position > NodeCount + 1)
            {
                cout << "Invalid number. Enter again: ";
                cin >> position;
            }
            if (position == 1)
            {
                Insert_at_First();
                return;
            }
            else
            {
                Node *move = head;
                Node *previous = head; // This will point to the node that is before the new node.
                for (int i = 1; i < position; i++)
                {
                    move = move->next;
                }
                for (int i = 1; i < position - 1; i++)
                {
                    previous = previous->next;
                }
                cout << "Enter value: ";
                cin >> value;
                Node *newnode = new Node(value);
                newnode->next = move;
                previous->next = newnode;
                NodeCount++;
            }
        }
        
    }
    void Delete_head()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            NodeCount--;
        }
    }
    void Delete_end()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            Node *move = head;
            Node *secondlast = head;
            while (move->next != NULL)
            {
                move = move->next;
            }
            while (secondlast->next->next != NULL)
            {
                secondlast = secondlast->next;
            }
            secondlast->next = NULL;
            delete move;
            NodeCount--;
        }
    }

    void Delete_at_Node()
    {
        int position;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "Enter the position of the node that you want to delete: ";
            cin >> position;
            while (position < 0 || position > NodeCount)
            {
                cout << "Invalid number. Enter again: ";
                cin >> position;
            }
            Node *move = head;
            Node *previous = head;
            if (position == 1)
            {
                head = head->next;
                delete move;
                NodeCount--;
            }
            else
            {
                for (int i = 1; i < position; i++)
                {
                    move = move->next;
                }
                for (int i = 1; i < position - 1; i++)
                {
                    previous = previous->next;
                }
                previous->next = move->next;
                delete move;
                NodeCount--;
            }
        }
    }     

    void Display_List()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "Total no. of nodes: " << NodeCount << endl;
            cout << "Values: " << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    void Search()
    {
        int value;
        int position = 1;
        cout << "Enter vaue to search: ";
        cin >> value;
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
        }
        Node *move = head;
        while (move != NULL)
        {
            if (move->data == value)
            {
                cout << value << " exists at node " << position << endl;
                return;
            }
            else
            {
                move = move->next;
            }
            position++;
        }
        cout << "Value not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }
    void Update()
    {
        int position;
        int value;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "No. of nodes in the list: " << NodeCount << endl;
            cout << "Enter the number of node you want to update: ";
            cin >> position;
            while (position < 0 || position > NodeCount)
            {
                cout << "Invalid number. Enter again: ";
                cin >> position;
            }
            cout << "Enter the updated value: ";
            cin >> value;
            Node *move = head;
            for (int i = 1; i < position; i++)
            {
                move = move->next;
            }
            move->data = value;
            cout << "Value updated" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
};

int main()
{
    int choice;
    LinkedList List;
    while (true)
    {
        cout << "Creating a Linked List" << endl;
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Update\n6. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "1. Insert at First\n2. Insert at End\n3. Insert in a specific Node" << endl;
            cout << "Select an option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                List.Insert_at_First();
            }
            break;
            case 2:
            {
                List.Insert_at_End();
            }
            break;
            case 3:
            {
                List.Insert_at_Node();
            }
            default:
            {
                cout << "Invalid choice" << endl;
            }
            }
        }
        break;
        case 2:
        {
            cout << "1. Delete head\n2. Delete end\n3. Delete a specific node" << endl;
            cout << "Select an option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                List.Delete_head();
            }
            break;
            case 2:
            {
                List.Delete_end();
            }
            break;
            case 3:
            {
                List.Delete_at_Node();
            }
            }
        }
        break;
        case 3:
        {
            List.Display_List();
            cout << "Press any key to continue..." << endl;
            getch();
        }
        break;
        case 4:
        {
            List.Search();
        }
        break;
        case 5:
        {
            List.Update();
        }
        break;
        case 6:
        {
            return 0;
        }
        break;
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    }
}