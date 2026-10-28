#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Node
{
    public:
    int Lecture_ID;
    string Lecture_Title;
    int Duration;
    Node* next;

    Node(int id,string title,int duration)
    {
        Lecture_ID=id;
        Lecture_Title=title;
        Duration=duration;
        next=NULL;
    }
};

class Playlist
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* current=NULL;
    int NodeCount=0;
    bool Repeat=false;

    public:
    void Add_Lecture()
    {
        int id,duration;
        string title;
        cout << "Enter Lecture ID: ";
        cin >> id;
        if(head!=NULL)
        {
            Node* move=head;
            do
            {
                if(move->Lecture_ID==id)
                {
                    cout << "Lecture ID already exists" << endl;
                    cout << "Press any key to continue..." << endl;
                    getch();
                    return;
                }
                move=move->next;
            }while(move!=head);
        }
        cout << "Enter Lecture Title: ";
        cin.ignore();
        getline(cin,title);
        cout << "Enter Duration (minutes): ";
        cin >> duration;
        Node* newnode=new Node(id,title,duration);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            newnode->next=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }
        NodeCount++;
        cout << "Lecture added" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Delete_Lecture()
    {
        int id;
        if(head==NULL)
        {
            cout << "Playlist is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }
        cout << "Enter ID of the lecture you want to delete: ";
        cin >> id;
        Node* move=head;
        Node* prev=tail;
        do
        {
            if(move->Lecture_ID==id)
            {
                if(NodeCount==1)
                {
                    head=NULL;
                    tail=NULL;
                    current=NULL;
                }
                else
                {
                    if(current==move)
                    {
                        current=move->next;
                    }
                    prev->next=move->next;
                    if(move==head)
                    {
                        head=move->next;
                    }
                    if(move==tail)
                    {
                        tail=prev;
                    }
                }
                delete move;
                NodeCount--;
                cout << "Lecture deleted" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            prev=move;
            move=move->next;
        }while(move!=head);
        cout << "ID not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Start()
    {
        if(head==NULL)
        {
            cout << "Playlist is empty" << endl;
        }
        else
        {
            current=head;
            cout << "Playlist started" << endl;
            cout << "Now playing: " << current->Lecture_Title << endl;
            cout << "Lecture ID: " << current->Lecture_ID << endl;
            cout << "Duration: " << current->Duration << " minutes" << endl;
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Play_Next()
    {
        if(current==NULL)
        {
            cout << "Start the playlist first" << endl;
        }
        else if(current->next==head&&Repeat==false)
        {
            cout << "End of playlist. Turn on repeat mode to start again" << endl;
        }
        else
        {
            current=current->next;
            cout << "Now playing: " << current->Lecture_Title << endl;
            cout << "Lecture ID: " << current->Lecture_ID << endl;
            cout << "Duration: " << current->Duration << " minutes" << endl;
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Skip()
    {
        if(current==NULL)
        {
            cout << "Start the playlist first" << endl;
        }
        else
        {
            cout << "Skipped: " << current->Lecture_Title << endl;
            if(current->next==head&&Repeat==false)
            {
                cout << "End of playlist. Turn on repeat mode to start again" << endl;
            }
            else
            {
                current=current->next;
                cout << "Now playing: " << current->Lecture_Title << endl;
                cout << "Lecture ID: " << current->Lecture_ID << endl;
                cout << "Duration: " << current->Duration << " minutes" << endl;
            }
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Display()
    {
        if(head==NULL)
        {
            cout << "Playlist is empty" << endl;
        }
        else
        {
            cout << "Playlist: " << endl;
            Node* move=head;
            do
            {
                cout << "Lecture ID: " << move->Lecture_ID << endl;
                cout << "Lecture Title: " << move->Lecture_Title << endl;
                cout << "Duration: " << move->Duration << " minutes" << endl;
                if(move==current)
                {
                    cout << "(Currently playing)" << endl;
                }
                move=move->next;
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
            cout << "Playlist is empty" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            return;
        }
        cout << "Enter ID of the lecture you want to search: ";
        cin >> id;
        Node* move=head;
        do
        {
            if(move->Lecture_ID==id)
            {
                cout << "Lecture found" << endl;
                cout << "Lecture ID: " << move->Lecture_ID << endl;
                cout << "Lecture Title: " << move->Lecture_Title << endl;
                cout << "Duration: " << move->Duration << " minutes" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            move=move->next;
        }while(move!=head);
        cout << "ID not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Count()
    {
        cout << "Total number of lectures: " << NodeCount << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Repeat_Mode()
    {
        if(Repeat==false)
        {
            Repeat=true;
            cout << "Repeat mode is ON" << endl;
        }
        else
        {
            Repeat=false;
            cout << "Repeat mode is OFF" << endl;
        }
        cout << "Press any key to continue..." << endl;
        getch();
    }

    ~Playlist()
    {
        if(head==NULL)
        {
            return;
        }
        tail->next=NULL;
        Node* move=head;
        while(move!=NULL)
        {
            Node* nextNode=move->next;
            delete move;
            move=nextNode;
        }
    }
};

int main()
{
    int choice;
    Playlist list;
    while(true)
    {
        cout << "Smart Learning Playlist" << endl;
        cout << "1. Add a lecture\n2. Delete a lecture\n3. Start the playlist\n4. Play the next lecture\n5. Display all lectures\n6. Search for a lecture\n7. Count lectures\n8. Skip the current lecture\n9. Repeat mode on/off\n10. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                list.Add_Lecture();
            }
            break;
            case 2:
            {
                list.Delete_Lecture();
            }
            break;
            case 3:
            {
                list.Start();
            }
            break;
            case 4:
            {
                list.Play_Next();
            }
            break;
            case 5:
            {
                list.Display();
            }
            break;
            case 6:
            {
                list.Search();
            }
            break;
            case 7:
            {
                list.Count();
            }
            break;
            case 8:
            {
                list.Skip();
            }
            break;
            case 9:
            {
                list.Repeat_Mode();
            }
            break;
            case 10:
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