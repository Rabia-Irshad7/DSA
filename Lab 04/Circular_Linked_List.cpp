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
    Node *tail = NULL;
    int NodeCount = 0;

    ~LinkedList()
    {
        while (head != NULL)
        {
            Delete_head();
        }
    }

    void Insert_at_First()
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            newnode->next = head;
        }
        else
        {
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }
        NodeCount++;
    }

    void Insert_at_End()
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            newnode->next = head;
        }
        else
        {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
        NodeCount++;
    }


    void Insert_at_Node()
    {
        int value, position;
        if (head == NULL)
        {
            cout << "List is empty\nCreating head " << endl;
            Insert_at_First();
            return;
        }

        cout << "No. of nodes in the list: " << NodeCount << endl;
        cout << "Enter the position where you want to insert the new node: ";
        cin >> position;
        while (position < 1 || position > NodeCount + 1)
        {
            cout << "Invalid number. Enter again: ";
            cin >> position;
        }

        if (position == 1)
        {
            Insert_at_First();
        }
        else if (position == NodeCount + 1)
        {
            Insert_at_End();
        }
        else
        {
            cout << "Enter value: ";
            cin >> value;
            Node *previous = head;
            for (int i = 1; i < position - 1; i++)
            {
                previous = previous->next;
            }
            Node *newnode = new Node(value);
            newnode->next = previous->next;
            previous->next = newnode;
            NodeCount++;
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
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            NodeCount--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
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
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            NodeCount--;
        }
        else
        {
            Node *secondlast = head;
            while (secondlast->next != tail)
            {
                secondlast = secondlast->next;
            }
            secondlast->next = head;
            delete tail;
            tail = secondlast;
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
            return;
        }

        cout << "Enter the position of the node that you want to delete: ";
        cin >> position;
        while (position < 1 || position > NodeCount)
        {
            cout << "Invalid number. Enter again: ";
            cin >> position;
        }

        if (position == 1)
        {
            Delete_head();
        }
        else if (position == NodeCount)
        {
            Delete_end();
        }
        else
        {
            Node *previous = head;
            for (int i = 1; i < position - 1; i++)
            {
                previous = previous->next;
            }
            Node *target = previous->next;
            previous->next = target->next;
            delete target;
            NodeCount--;
        }
    }

    void Display_List()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Total no. of nodes: " << NodeCount << endl;
        cout << "Values: " << endl;
        Node *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void Search()
    {
        int value;
        int position = 1;
        cout << "Enter value to search: ";
        cin >> value;

        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }

        Node *move = head;
        do
        {
            if (move->data == value)
            {
                cout << value << " exists at node " << position << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            move = move->next;
            position++;
        } while (move != head);

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
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }

        cout << "No. of nodes in the list: " << NodeCount << endl;
        cout << "Enter the number of node you want to update: ";
        cin >> position;
        while (position < 1 || position > NodeCount)
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
};

int main()
{
    int choice;
    LinkedList List;
    while (true)
    {
        cout << "Creating a Singly Circular Linked List" << endl;
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
                List.Insert_at_First();
                break;
            case 2:
                List.Insert_at_End();
                break;
            case 3:
                List.Insert_at_Node();
                break;
            default:
                cout << "Invalid choice" << endl;
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
                List.Delete_head();
                break;
            case 2:
                List.Delete_end();
                break;
            case 3:
                List.Delete_at_Node();
                break;
            default:
                cout << "Invalid choice" << endl;
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
            List.Search();
            break;
        case 5:
            List.Update();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}