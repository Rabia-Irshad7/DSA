#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int Task_ID;
    string Task_Description;
    string Priority;
    string Status;
    Node *Next_Task;
    Node(int id, string desc, string priority, string status)
    {
        Task_ID = id;
        Task_Description = desc;
        Priority = priority;
        Status = status;
        Next_Task = NULL;
    }
};

class Task_Manager
{
    Node *head = NULL;

public:
    int NodeCount = 0;
    ~Task_Manager()
    {
        Node* move = head;
        while(move != NULL)
        {
            Node* next = move->Next_Task; 
            delete move;
            move = next;
        }
        head = NULL;
    }

    bool idExists(int id)
    {
        Node*move=head;
        while(move!=NULL)
        {
            if(move->Task_ID==id)
            {
                return true;
            }
            else
            {
                move=move->Next_Task;
            }
        }
        return false;
        
    }

    void Insert_at_First()
    {
        int id;
        string desc, priority, status;
        cout << "Creating new task" << endl;
        cout << "Enter task ID: ";
        cin >> id;
        while(idExists(id))
        {
            cout << "ID exists. Enter again" << endl;
            cin >> id;
        }
        cout << "Enter Task decsription: ";
        cin.ignore();
        getline(cin, desc);
        cout << "Enter priority (High, Medium, Low): ";
        cin >> priority;
        while (!(priority == "High" || priority == "high" || priority == "Medium" || priority == "medium" || priority == "Low" || priority == "low"))
        {
            cout << "Please enter correctly" << endl;
            cin >> priority;
        }
        cout << "Enter status (Pending, In-progress, Done): ";
        cin >> status;
        while (!(status == "Pending" || status == "pending" || status == "Done" || status == "done" || status == "In-Progress" || status == "in-progress"))
        {
            cout << "Please enter correctly" << endl;
            cin >> status;
        }
        if (head == NULL)
        {
            Node *newnode = new Node(id, desc, priority, status);
            head = newnode;
            newnode->Next_Task = NULL;
            NodeCount++;
            cout << "Task inserted" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            Node *newnode = new Node(id, desc, priority, status);
            newnode->Next_Task = head;
            head = newnode;
            NodeCount++;
            cout << "Task inserted" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
    void Insert_at_End()
    {
        int id;
        string desc, priority, status;
        cout << "Creating new task" << endl;
        cout << "Enter task ID: ";
        cin >> id;
        while(idExists(id))
        {
            cout << "ID exists. Enter again" << endl;
            cin >> id;
        }
        cout << "Enter Task decsription: ";
        cin.ignore();
        getline(cin, desc);
        cout << "Enter priority (High, Medium, Low): ";
        cin >> priority;
        while (!(priority == "High" || priority == "high" || priority == "Medium" || priority == "medium" || priority == "Low" || priority == "low"))
        {
            cout << "Please enter correctly" << endl;
            cin >> priority;
        }
        cout << "Enter status (Pending, In-progress, Done): ";
        cin >> status;
        while (!(status == "Pending" || status == "pending" || status == "Done" || status == "done" || status == "In-Progress" || status == "in-progress" ))
        {
            cout << "Please enter correctly" << endl;
            cin >> status;
        }
        if (head == NULL)
        {
            Node *newnode = new Node(id, desc, priority, status);
            head = newnode;
            newnode->Next_Task = NULL;
            NodeCount++;
            cout << "Task inserted" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            Node *move = head;
            while (move->Next_Task != NULL)
            {
                move = move->Next_Task;
            }
            Node *newnode = new Node(id, desc, priority, status);
            move->Next_Task = newnode;
            newnode->Next_Task = NULL;
            NodeCount++;
            cout << "Task inserted" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
    void Insert_at_Node()
    {
        int id,after_id;
        string desc, priority, status;
        if (head == NULL)
        {
            cout << "List is empty. Creating head: " << endl;
        }
        cout << "Creating new task" << endl;
        cout << "Enter task ID: ";
        cin >> id;
        while(idExists(id))
        {
            cout << "ID exists. Enter again" << endl;
            cin >> id;
        }
        cout << "Enter Task decsription: ";
        cin.ignore();
        getline(cin, desc);
        cout << "Enter priority (High, Medium, Low): ";
        cin >> priority;
        while (!(priority == "High" || priority == "high" || priority == "Medium" || priority == "medium" || priority == "Low" || priority == "low"))
        {
            cout << "Please enter correctly" << endl;
            cin >> priority;
        }
        cout << "Enter status (Pending, In-progress, Done): ";
        cin >> status;
        while (!(status == "Pending" || status == "pending" || status == "Done" || status == "done" || status == "In-Progress" || status == "in-progress" ))
        {
            cout << "Please enter correctly" << endl;
            cin >> status;
        }
        if (head == NULL)
        {
            Node *newnode = new Node(id, desc, priority, status);
            head = newnode;
            newnode->Next_Task = NULL;
            NodeCount++;
            cout << "Task inserted" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "Enter Task ID after which you want to insert task: ";
            cin >> after_id;
            Node *move = head;
            while (move != NULL)
            {
                if (move->Task_ID == after_id)
                {
                    Node *newnode = new Node(id, desc, priority, status);
                    newnode->Next_Task = move->Next_Task;
                    move->Next_Task = newnode;
                    NodeCount++;
                    cout << "Task inserted" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
                    return;
                }
                else
                {
                    move = move->Next_Task;
                }
            }
            cout << "ID not found" << endl;
        }
    }
    void Delete()
    {
        int id;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "Enter ID of the task you want to delete: ";
            cin >> id;
            Node *move = head;
            Node *prev = head;
            while (move != NULL)
            {
                if (move->Task_ID == id)
                {
                    if (move == head)
                    {
                        head = head->Next_Task;
                        delete move;
                        cout << "Task deleted" << endl;
                        cout << "Press any key to continue..." << endl;
                        getch();
                        NodeCount--;
                        return;
                    }
                    else
                    {
                        while (prev->Next_Task != move)
                        {
                            prev = prev->Next_Task;
                        }
                        prev->Next_Task = move->Next_Task;
                        delete move;
                        cout << "Task deleted" << endl;
                        cout << "Press any key to continue..." << endl;
                        getch();
                        NodeCount--;
                        return;
                    }
                }
                move = move->Next_Task;
            }
            cout << "ID not found" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
    void Display()
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
            while (move != NULL)
            {
                cout << "Task ID: " << move->Task_ID << endl;
                cout << "Task Description: " << move->Task_Description << endl;
                cout << "Priority: " << move->Priority << endl;
                cout << "Status: " << move->Status << endl;
                move = move->Next_Task;
            }
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Search()
    {
        int id;
        cout << "Enter the ID of the task you want to search: ";
        cin >> id;
        Node *move = head;
        while (move != NULL)
        {
            if (move->Task_ID == id)
            {
                cout << "Task Found!" << endl;
                cout << "Task ID: " << move->Task_ID << endl;
                cout << "Task description: " << move->Task_Description << endl;
                cout << "Task Priority: " << move->Priority << endl;
                ;
                cout << "Task status: " << move->Status << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            else
            {
                move = move->Next_Task;
            }
        }
        cout << "ID not found..." << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Update()
    {
        int id, choice;
        cout << "Enter ID of the task you want to update: ";
        cin >> id;
        Node *move = head;
        while (move != NULL)
        {
            if (move->Task_ID == id)
            {
                cout << "1. Update ID\n2. Update Description\n3. Update Priority\n4. Update Status" << endl;
                cout << "Select an option: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cout << "Enter updated ID: ";
                    cin >> move->Task_ID;
                    while(idExists(move->Task_ID))
                    {
                        cout << "ID exists. Enter again" << endl;
                        cin >> move->Task_ID;
                    }
                    cout << "ID updated\n Press any key to continue..." << endl;
                    getch();
                }
                break;
                case 2:
                {
                    cout << "Enter updated description: ";
                    cin.ignore();
                    getline(cin, move->Task_Description);
                    cout << "Description updated\n Press any key to continue..." << endl;
                    getch();
                }
                break;
                case 3:
                {
                    cout << "Enter updated priority: ";
                    cin >> move->Priority;
                    while (!(move->Priority == "High" || move->Priority == "high" || move->Priority == "Medium" || move->Priority == "medium" || move->Priority == "Low" || move->Priority == "low"))
                    {
                        cout << "Please enter correctly" << endl;
                        cin >> move->Priority;
                    }
                    cout << "Priority updated\n Press any key to continue..." << endl;
                    getch();
                }
                break;
                case 4:
                {
                    cout << "Enter updated status: ";
                    cin >> move->Status;
                    while (!(move->Status == "Pending" || move->Status == "pending" || move->Status == "Done" || move->Status == "done" || move->Status == "In-Progress" || move->Status == "in-progress" ))
                    {
                        cout << "Please enter correctly" << endl;
                        cin >> move->Status;
                    }
                    cout << "Status updated\n Press any key to continue..." << endl;
                    getch();
                }
                break;
                default:
                {
                    cout << "Invalid input" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
                }
                }
                return;
            }
            else
            {
                move = move->Next_Task;
            }
        }
        cout << "ID not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Mark_Done()
    {
        int id;
        cout << "Enter ID of task you want to mark done: ";
        cin >> id;
        Node *move = head;
        {
            while (move != NULL)
            {
                if (move->Task_ID == id)
                {
                    move->Status = "Done";
                    cout << "Task marked done\nPress any key to continue..." << endl;
                    getch();
                    return;
                }
                move = move->Next_Task;
            }
            cout << "ID not found" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Display_Pending()
    {
        int count = 0;
        Node *move = head;
        while (move != NULL)
        {
            if (move->Status == "Pending" || move->Status == "pending")
            {
                cout << "Task ID: " << move->Task_ID << endl;
                cout << "Task Description: " << move->Task_Description << endl;
                cout << "Task Priority: " << move->Priority << endl;
                cout << "Task status: " << move->Status << endl;
                count++;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            move = move->Next_Task;
        }
        if (count == 0)
        {
            cout << "No pending tasks" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Display_Completed()
    {
        int count = 0;
        Node *move = head;
        while (move != NULL)
        {
            if (move->Status == "Done" || move->Status == "done")
            {
                cout << "Task ID: " << move->Task_ID << endl;
                cout << "Task Description: " << move->Task_Description << endl;
                cout << "Task Priority: " << move->Priority << endl;
                cout << "Task status: " << move->Status << endl;
                count++;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            move = move->Next_Task;
        }
        if (count == 0)
        {
            cout << "No completed tasks" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
};

int main()
{
    Task_Manager List;
    int choice;
    while (true)
    {
        cout << "AI Agent Task Manager" << endl;
        cout << "1. Insert Task\n2. Delete Task\n3. Search Task\n4. Update Task\n5. Display total number of tasks\n6. Marks task as done\n7. Display pending tasks\n8. Display completed tasks\n9. Display all tasks\n10. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "1. Insert at first\n2. Insert at end\n3. Insert at any point" << endl;
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
            break;
            default:
            {
                cout << "Invalid choice" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            break;
            }
        }
        break;
        case 2:
        {
            List.Delete();
        }
        break;
        case 3:
        {
            List.Search();
        }
        break;
        case 4:
        {
            List.Update();
        }
        break;
        case 5:
            {
                cout << "Total number of tasks: " << List.NodeCount << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            break;
        case 6:
        {
            List.Mark_Done();
        }
        break;
        case 7:
        {
            List.Display_Pending();
        }
        break;
        case 8:
        {
            List.Display_Completed();
        }
        break;
        case 9:
        {
            List.Display();
        }
        break;
        case 10:
        {
            return 0;
        }
        break;
        default:
        {
            cout << "Invalid choice" << endl;
        }
        break;
        }
    }
}