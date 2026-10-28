#include <iostream>
#include<conio.h>
#include <ctime>
using namespace std;

class Node
{
    public:
    string URL;
    string Page_Title;
    string Visit_Time;
    Node* next;
    Node* prev;

    Node(string url,string title)
    {
        URL=url;
        Page_Title=title;
        time_t now=time(0);
        Visit_Time=ctime(&now);
        Visit_Time.pop_back();
        next=NULL;
        prev=NULL;
    }
};

class List
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* currentPage=NULL;
    int NodeCount=0;

    public:
    void Visit_page()
    {
        string url;
        string title;
        cout << "Enter URL of the webpage: ";
        cin >> url;
        cout << "Enter Title of the web page: ";
        cin.ignore();
        getline(cin,title);
        if(head==NULL)
        {
            Node* newnode=new Node(url,title);
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
            tail=newnode;
            currentPage=newnode;
            NodeCount++;
        }
        else
        {
            Node* newnode=new Node(url,title);
            tail->next=newnode;
            newnode->next=NULL;
            newnode->prev=tail;
            tail=newnode;
            currentPage=newnode;
            NodeCount++;
        }
        cout << "Visiting webpage: " << currentPage->Page_Title << endl;
        cout << "URL: " << currentPage->URL << endl;
        cout << "Visit Time: " << currentPage->Visit_Time << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

    void Back()
    {
        if(currentPage==NULL)
        {
            cout << "No browsing history" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else if(currentPage->prev==NULL)
        {
            cout << "No previous page" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            currentPage=currentPage->prev;
            cout << "Visiting webpage: " << currentPage->Page_Title << endl;
            cout << "URL: " << currentPage->URL << endl;
            cout << "Visit Time: " << currentPage->Visit_Time << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Forward()
    {
        if(currentPage==NULL)
        {
            cout << "No browsing history" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else if(currentPage->next==NULL)
        {
            cout << "No next page" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            currentPage=currentPage->next;
            cout << "Visiting webpage: " << currentPage->Page_Title << endl;
            cout << "URL: " << currentPage->URL << endl;
            cout << "Visit Time: " << currentPage->Visit_Time << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Display()
    {
        if(head==NULL)
        {
            cout << "No borwsing history" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "Browsing history: " << endl;
            Node* move=head;
            while(move!=NULL)
            {
                cout << "Page Title: " << move->Page_Title << endl;
                cout << "URL: " << move->URL << endl;
                cout << "Visit Time: " << move->Visit_Time << endl;
                move=move->next;
            }
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Display_Backwards()
    {
        if(head==NULL)
        {
            cout << "No borwsing history" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "Browsing history (newest to oldest): " << endl;
            Node* move=tail;
            while(move!=NULL)
            {
                cout << "Page Title: " << move->Page_Title << endl;
                cout << "URL: " << move->URL << endl;
                cout << "Visit Time: " << move->Visit_Time << endl;
                move=move->prev;
            }
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    void Search()
    {
        if (head==NULL)
        {
            cout << "No browsing history" << endl;
            return;
        }

        string url;
        cout << "Enter URL to search: ";
        cin >> url;

        Node* move = head;
        while (move!=NULL)
        {
            if (move->URL==url)
            {
                cout << "URL found" << endl;
                cout << "Title: " << move->Page_Title << endl;
                cout << "Visit time: " << move->Visit_Time << endl;
                return;
            }
            move = move->next;
        }
        cout << "URL not found" << endl;
    }

    void Clear_History()
    {
        Node* move=head;
        while (move!=NULL)
        {
            Node* nextNode=move->next;  
            delete move;
            move=nextNode;
        }
        head=NULL;
        tail=NULL;
        currentPage=NULL;
        NodeCount=0;
    }

    ~List()      
    {
        Clear_History();
    }

    void Delete()
    {
        string url;
        if(head==NULL)
        {
            cout << "No browsing history" << endl;
            return;
        }
        cout << "Enter URL of the page you want to delete from history: ";
        cin >> url;
        Node* move=head;
        while(move!=NULL)
        {
            if(move->URL==url)
            {
                if (currentPage == move)
                {
                    if (move->prev!=NULL)
                    {
                        currentPage = move->prev;
                    } 
                    else
                    {
                        currentPage = move->next;
                    } 
                }
                if(move==head&&move==tail)
                {
                    head=NULL;
                    tail=NULL;
                }
                else if(move==head)
                {
                    head=head->next;
                    head->prev=NULL;
                }
                else if(move==tail)
                {
                    tail=tail->prev;
                    tail->next=NULL;
                }
                else
                {
                    move->prev->next=move->next;
                    move->next->prev=move->prev;
                }
                delete move;
                NodeCount--;
                cout << "Webpage deleted from browser history" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                return;
            }
            else
            {
                move=move->next;
            }
        }
        cout << "Page not found" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

};

int main() {
    int choice;
    List list;
    while(true)
    {
        cout << "Web Browser Navigation" << endl;
        cout << "1. Visit a new page\n2. Go Back\n3. Go Forward\n4. Display complete browser history\n5. Delete a page\n6. Search page from history\n7. Display history from newest to oldest\n8. Clear browser history\n9. Exit" << endl;
        cout << "select an option: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                list.Visit_page();
            }
            break;
            case 2:
            {
                list.Back();
            }
            break;
            case 3:
            {
                list.Forward();
            }
            break;
            case 4:
            {
                list.Display();
            }
            break;
            case 5:
            {
                list.Delete();
            }
            break;
            case 6:
            {
                list.Search();
            }
            break;
            case 7:
            {
                list.Display_Backwards();
            }
            break;
            case 8 :
            {
                list.Clear_History();
                cout << "History cleared" << endl;
                cout << "Press any key to continue" << endl;
                getch();
            }
            break;
            case 9:
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
        }
    }
    
    
    return 0;
}
