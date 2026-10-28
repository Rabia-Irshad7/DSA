#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Node
{
public:
    int key;
    string value;
    Node *prev;
    Node *next;

    Node(int k, const string &v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
    int capacity;
    int size;
    Node *head;
    Node *tail;

public:
    LRUCache(int c)
    {
        capacity = c;
        size - 0;
        head = NULL;
        tail = NULL;
    }

    ~LRUCache()
    {
        Node *move = head;
        while (move != NULL)
        {
            Node *temp = move;
            move = move->next;
            delete temp;
        }
    }

    void put(int key, string value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                temp->value = value;
                if (temp == head)
                {
                    return;
                }

                temp->prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                else
                {
                    tail = temp->prev;
                }

                temp->prev = NULL;
                temp->next = head;
                head->prev = temp;
                head = temp;
                return;
            }
            temp = temp->next;
        }

        if (size == capacity)
        {
            Node *last = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete last;
            size--;
        }

        Node *newNode = new Node(key, value);
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    void get(int key, string value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (temp != head)
                {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                    {
                        temp->next->prev = temp->prev;
                    }
                    else
                    {
                        tail = temp->prev;
                    }

                    temp->prev = NULL;
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                }
                cout << "Cache: [" << key << ":" << value << "]" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Key not found" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Cache is empty." << endl;
            return;
        }

        cout << "Cache: ";
        Node *move = head;
        while (move != NULL)
        {
            cout << "[" << move->key << ": " << move->value << "]";
            if (move->next != NULL)
            {
                cout << endl;
            }
            move = move->next;
        }
        cout << endl;
    }

    void displaySize()
    {
        cout << "Cache size: " << size << " / " << capacity << endl;
    }
};

int main()
{
    LRUCache cache(3);
    int choice;
    int key;
    string value;
    while (true)
    {
        cout << "LRU Cache: Capacity = 3" << endl;
        cout << "1. Put cache value" << endl;
        cout << "2. Get cache value" << endl;
        cout << "3. Display cache" << endl;
        cout << "4. Display cache size" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin.ignore();
            getline(cin, value);
            cache.put(key, value);
            break;
        }
        case 2:
        {
            cout << "Enter key: ";
            cin >> key;
            cache.get(key, value);
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }
        case 3:
        {
            cache.display();
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }
        case 4:
        {
            cache.displaySize();
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }

    return 0;
}