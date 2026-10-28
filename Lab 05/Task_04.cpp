#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Node
{
    public:
    int Request_ID;
    int User_ID;
    string Model_Name;
    int Processing_Time;
    Node* Next;

    Node(int rid,int uid,string model,int time)
    {
        Request_ID=rid;
        User_ID=uid;
        Model_Name=model;
        Processing_Time=time;
        Next=NULL;
    }
};

class Scheduler
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* current=NULL;
    int NodeCount=0;
    int Quantum=3;

    void Remove_Node(Node* target)
    {
        if(NodeCount==1)
        {
            head=NULL;
            tail=NULL;
            current=NULL;
        }
        else
        {
            Node* prev=head;
            while(prev->Next!=target)
            {
                prev=prev->Next;
            }
            if(current==target)
            {
                current=target->Next;
            }
            prev->Next=target->Next;
            if(target==head)
            {
                head=target->Next;
            }
            if(target==tail)
            {
                tail=prev;
            }
        }
        delete target;
        NodeCount--;
    }

    void Process_One()
    {
        Node* node=current;
        cout << "Processing Request ID: " << node->Request_ID << endl;
        cout << "User ID: " << node->User_ID << endl;
        cout << "Model: " << node->Model_Name << endl;
        if(node->Processing_Time<=Quantum)
        {
            cout << "Time used: " << node->Processing_Time << " units" << endl;
            cout << "Request " << node->Request_ID << " completed and removed" << endl;
            Remove_Node(node);
        }
        else
        {
            node->Processing_Time=node->Processing_Time-Quantum;
            cout << "Time used: " << Quantum << " units" << endl;
            cout << "Remaining time: " << node->Processing_Time << " units" << endl;
            current=node->Next;
        }
    }

    public:
    void Add_Request()
    {
        int rid,uid,time;
        string model;
        cout << "Enter Request ID: ";
        cin >> rid;
        if(head!=NULL)
        {
            Node* move=head;
            do
            {
                if(move->Request_ID==rid)
                {
                    cout << "Request ID already exists" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
                    return;
                }
                move=move->Next;
            }while(move!=head);
        }
        cout << "Enter User ID: ";
        cin >> uid;
        cout << "Enter Model Name: ";
        cin.ignore();
        getline(cin,model);
        cout << "Enter Processing Time (units): ";
        cin >> time;
        Node* newnode=new Node(rid,uid,model,time);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            newnode->Next=newnode;
            current=newnode;
        }
        else
        {
            tail->Next=newnode;
            newnode->Next=head;
            tail=newnode;
        }
        NodeCount++;
        cout << "Request added" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Remove_Request()
    {
        int id;
        if(head==NULL)
        {
            cout << "No active requests" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }
        cout << "Enter ID of the request you want to remove: ";
        cin >> id;
        Node* move=head;
        do
        {
            if(move->Request_ID==id)
            {
                Remove_Node(move);
                cout << "Request removed" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            move=move->Next;
        }while(move!=head);
        cout << "ID not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Process_Next()
    {
        if(head==NULL)
        {
            cout << "No active requests" << endl;
        }
        else
        {
            Process_One();
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Display()
    {
        if(head==NULL)
        {
            cout << "No active requests" << endl;
        }
        else
        {
            cout << "Active requests: " << endl;
            Node* move=head;
            do
            {
                cout << "Request ID: " << move->Request_ID << endl;
                cout << "User ID: " << move->User_ID << endl;
                cout << "Model Name: " << move->Model_Name << endl;
                cout << "Processing Time: " << move->Processing_Time << " units" << endl;
                if(move==current)
                {
                    cout << "(Next to be processed)" << endl;
                }
                move=move->Next;
            }while(move!=head);
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Search()
    {
        int id;
        if(head==NULL)
        {
            cout << "No active requests" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }
        cout << "Enter ID of the request you want to find: ";
        cin >> id;
        Node* move=head;
        do
        {
            if(move->Request_ID==id)
            {
                cout << "Request found" << endl;
                cout << "Request ID: " << move->Request_ID << endl;
                cout << "User ID: " << move->User_ID << endl;
                cout << "Model Name: " << move->Model_Name << endl;
                cout << "Processing Time: " << move->Processing_Time << " units" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            move=move->Next;
        }while(move!=head);
        cout << "ID not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Simulate()
    {
        if(head==NULL)
        {
            cout << "No active requests" << endl;
        }
        else
        {
            for(int i=1;i<=10;i++)
            {
                if(head==NULL)
                {
                    cout << "All requests completed. Simulation stopped at cycle " << i-1 << endl;
                    break;
                }
                cout << "--- Cycle " << i << " ---" << endl;
                Process_One();
            }
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    ~Scheduler()
    {
        if(head==NULL)
        {
            return;
        }
        tail->Next=NULL;
        Node* move=head;
        while(move!=NULL)
        {
            Node* nextNode=move->Next;
            delete move;
            move=nextNode;
        }
    }
};

int main()
{
    int choice;
    Scheduler server;
    while(true)
    {
        cout << "AI Cloud Server Scheduler" << endl;
        cout << "1. Add a request\n2. Remove a completed request\n3. Process the next request\n4. Display active requests\n5. Find a particular request\n6. Simulate 10 scheduling cycles\n7. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                server.Add_Request();
            }
            break;
            case 2:
            {
                server.Remove_Request();
            }
            break;
            case 3:
            {
                server.Process_Next();
            }
            break;
            case 4:
            {
                server.Display();
            }
            break;
            case 5:
            {
                server.Search();
            }
            break;
            case 6:
            {
                server.Simulate();
            }
            break;
            case 7:
            {
                return 0;
            }
            break;
            default:
            {
                cout << "Invalid input" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            break;
        }
    }
    return 0;
}