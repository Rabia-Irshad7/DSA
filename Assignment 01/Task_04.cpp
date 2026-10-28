
#include <iostream>
#include <string>
using namespace std;

class Lesson 
{
public:
    int ID;
    string Title;
    int Duration;       
    bool Completed;
    Lesson* next;
    Lesson* prev;

    Lesson(int id, string t, int d) 
    {
        ID = id;
        Title = t;
        Duration = d;
        Completed = false;
        next = NULL;
        prev = NULL;
    }
};

class Course 
{
    Lesson* head;
    Lesson* tail;
    int count;

    Lesson* findByID(int id) 
    {
        Lesson* cur=head;
        while(cur!=NULL) 
        {
            if(cur->ID==id)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

    void printLesson(Lesson* l)
    {
        cout << "ID: " << l->ID << endl;
        cout << "Title: " << l->Title << endl;
        cout << "Duration: " << l->Duration << " min)" << endl;
    }

public:
    Course() 
    {
        head=NULL;
        tail=NULL;
        count=0;
    }

    ~Course() 
    {
        while(head!=NULL)
        {
            Lesson* temp=head;
            head=head->next;
            delete temp;
        }
    }

    void insertAtEnd(int id, string title, int duration) 
    {
        if(findByID(id)!=NULL) 
        {
            cout << "Lesson ID " << id << " already exists." << endl;
            return;
        }

        Lesson* n=new Lesson(id, title, duration);

        if(head==NULL) 
        {         
            head=n;
            tail=n;
        } 
        else 
        {
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
        count++;
        cout << "Added: " << title << endl;
    }

    void deleteLesson(int id) 
    {
        Lesson* cur=findByID(id);
        if(cur==NULL) 
        {
            cout << "Lesson ID " << id << " not found." << endl;
            return;
        }

        if(cur->prev!=nullptr)
        {
            cur->prev->next = cur->next;
        }
        else
        {
             head = cur->next;  
        }         

        if (cur->next!=NULL)
        {
            cur->next->prev = cur->prev;
        }
        else
        {
            tail = cur->prev;  
        }

        cout << "Deleted: " << cur->Title << endl;
        delete cur;
        count--;
    }

    void search(int id) 
    {
        Lesson* cur=head;
        while(cur!=NULL) 
        {
            if (cur->ID == id) 
            {
                cout << "Found lesson" << endl; 
                printLesson(cur);
                return;
            }
            cur = cur->next;
        }
        cout << "Lesson ID " << id << " not found." << endl;
    }

    void displayForward() 
    {
        if (head == nullptr) 
        {
            cout << "Course is empty." << endl;
            return;
        }
        cout << "Course (forward)" << endl;
        Lesson* cur = head;
        while(cur!=NULL) 
        {
            printLesson(cur);
            cur = cur->next;
        }
    }

    void displayBackward() 
    {
        if (tail == NULL) 
        {
            cout << "Course is empty." << endl;
            return;
        }
        cout << "Course (backward)" << endl;
        Lesson* cur = tail;
        while (cur != NULL) 
        {
            printLesson(cur);
            cur = cur->prev;
        }
    }

    void markComplete(int id) 
    {
        Lesson* cur = findByID(id);
        if (cur == NULL) 
        {
            cout << "Lesson ID " << id << " not found." << endl;
            return;
        }
        cur->Completed = true;
        cout << "Completed: " << cur->Title << endl;
    }

    void showProgress() 
    {
        if (count == 0) 
        {
            cout << "Course is empty." << endl;
            return;
        }
        int done = 0;
        Lesson* cur = head;
        while (cur != NULL) 
        {
            if (cur->Completed)
            {
                done++;
            }
            cur = cur->next;
        }
        cout << "Progress: " << done << "/" << count << " lessons (" << (done * 100) / count << "%)" << endl;
    }
};

int main() 
{
    Course course;
    int choice;

    while(true)
    {
        cout << "COURSE NAVIGATION MENU" << endl;;
        cout << " 1. Add lesson" << endl;
        cout << " 2. Delete lesson" << endl;
        cout << " 3. Search" << endl;
        cout << " 4. Show course (forward)" << endl;
        cout << " 5. Show course (backward)" << endl;
        cout << " 6. Mark lesson complete" << endl;
        cout << " 7. Show progress" << endl;
        cout << " 8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        int id, duration, pos;
        string title;

        switch (choice) 
        {
        case 1:
        {
            cout << "Lesson ID: ";
            cin >> id;
            cin.ignore();
            cout << "Title: ";
            getline(cin, title);
            cout << "Duration (min): ";
            cin >> duration;
            course.insertAtEnd(id, title, duration);
            break;
        }

        case 2:
        {
            cout << "Lesson ID to delete: ";
            cin >> id;
            course.deleteLesson(id);
            break;
        }

        case 3:
        {
            cout << "Lesson ID to search: ";
            cin >> id;
            course.search(id);
            break;
        }

        case 4:
        {
            course.displayForward();
            break;
        }

        case 5:
        {
            course.displayBackward();
            break;
        }

        case 6:
        {
            cout << "Lesson ID to mark complete: ";
            cin >> id;
            course.markComplete(id);
            break;
        }

        case 7:
        {
            course.showProgress();
            break;
        }

        case 8:
        {
            return 0;
        }

        default:
        {
            cout << "Invalid choice." << endl;
        }
        }
    } 

}