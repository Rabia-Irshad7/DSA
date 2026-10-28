#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
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
            RemoveHead();
        }
    }

    Node *GetNode(int position)
    {
        Node *move;
        if (position <= NodeCount / 2)
        {
            move = head;
            for (int i = 1; i < position; i++)
            {
                move = move->next;
            }
        }
        else
        {
            move = tail;
            for (int i = NodeCount; i > position; i--)
            {
                move = move->prev;
            }
        }
        return move;
    }

    void InsertFirst(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            newnode->next = newnode; 
            newnode->prev = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = tail;
            head->prev = newnode;
            tail->next = newnode;
            head = newnode;
        }
        NodeCount++;
    }

    void InsertEnd(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            newnode->next = newnode;
            newnode->prev = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = tail;
            tail->next = newnode;
            head->prev = newnode;
            tail = newnode;
        }
        NodeCount++;
    }

    void Insert_at_First()
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        InsertFirst(value);
    }

    void Insert_at_End()
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        InsertEnd(value);
    }

    void Insert_at_Node()
    {
        int value, position;
        if (head == NULL)
        {
            cout << "List is empty\nEnter a value to create head: ";
            cin >> value;
            InsertFirst(value);
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

        cout << "Enter value: ";
        cin >> value;

        if (position == 1)
        {
            InsertFirst(value);
        }
        else if (position == NodeCount + 1)
        {
            InsertEnd(value);
        }
        else
        {
            Node *current = GetNode(position);
            Node *newnode = new Node(value);
            newnode->prev = current->prev;
            newnode->next = current;
            current->prev->next = newnode;
            current->prev = newnode;
            NodeCount++;
        }
    }

    void RemoveHead()
    {
        if (head == tail) 
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        NodeCount--;
    }

    void RemoveEnd()
    {
        if (head == tail) 
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        NodeCount--;
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
            RemoveHead();
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
            RemoveEnd();
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
            RemoveHead();
        }
        else if (position == NodeCount)
        {
            RemoveEnd();
        }
        else
        {
            Node *target = GetNode(position);
            target->prev->next = target->next;
            target->next->prev = target->prev;
            delete target;
            NodeCount--;
        }
    }

    void Display_Forward()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Total no. of nodes: " << NodeCount << endl;
        cout << "Values (head to tail): " << endl;
        Node *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head); 
    }

    void Display_Backward()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Total no. of nodes: " << NodeCount << endl;
        cout << "Values (tail to head): " << endl;
        Node *temp = tail;
        do
        {
            cout << temp->data << endl;
            temp = temp->prev;
        } while (temp != tail); 
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

        GetNode(position)->data = value;
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
        cout << "Creating a Doubly Circular Linked List" << endl;
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
            cout << "1. Display forward\n2. Display backward" << endl;
            cout << "Select an option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                List.Display_Forward();
                break;
            case 2:
                List.Display_Backward();
                break;
            default:
                cout << "Invalid choice" << endl;
            }
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