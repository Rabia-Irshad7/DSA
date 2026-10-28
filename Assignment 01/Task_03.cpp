#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Song
{
public:
    int ID;
    string Title;
    string Artist;
    int Duration;    
    Song* prev;
    Song* next;

    Song(int id, string title, string artist, int duration)
    {
        ID=id;
        Title=title;
        Artist=artist;
        Duration=duration;
        prev=NULL;
        next=NULL;
    }
};

class Playlist
{
    Song* head;
    Song* tail;
    Song* current;    
    int size;
    bool repeat;

public:
    Playlist()
    {
        head=NULL;
        tail=NULL;
        current=NULL;
        size=0;
        repeat=false;
    }

    void addSong(int id, string title, string artist, int duration)
    {
        Song* newSong = new Song(id, title, artist, duration);

        if (head==NULL)
        {
            head=newSong;
            tail=newSong;
            current=newSong; 
        }
        else
        {
            tail->next=newSong;   
            newSong->prev=tail;   
            tail=newSong;
        }
        size++;
    }

    void removeSong(int id)
    {
        if (head==NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* move=head;
        while (move!=NULL&&move->ID!=id)
        {
            move=move->next;
        }

        if (move==NULL)
        {
            cout << "Song with ID " << id << " not found." << endl;
            return;
        }

        if (move==current)
        {
            if (move->next!=NULL)
            {
                current=move->next;
            }
            else
            {
                current=move->prev;      
            }
        }

        if (move->prev==NULL)
        {
            head=move->next;          
        }
        else
        {
            move->prev->next=move->next;
        }

        if (move->next==NULL)
        {
            tail=move->prev;              
        }
        else
        {
            move->next->prev=move->prev;
        }

        delete move;
        size--;
        cout << "Song removed." << endl;
    }

    void playNext()
    {
        if(current==NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if(current->next!=NULL)
        {
            current = current->next;
        }
        else if(repeat==true)
        {
            current = head;                 
        }
        else
        {
            cout << "End of playlist." << endl;
            return;
        }

        cout << "Now playing: " << current->Title << " - " << current->Artist << endl;
    }

    void playPrevious()
    {
        if(current==NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if(current->prev!=NULL)
        {
            current=current->prev;
        }
        else if (repeat==true)
        {
            current=tail;              
        }
        else
        {
            cout << "Already at the start of the playlist." << endl;
            return;
        }

        cout << "Now playing: " << current->Title << " - " << current->Artist << endl;
    }

    void search(int id)
    {
        Song* move=head;

        while(move!=NULL)
        {
            if(move->ID==id)
            {
                cout << "Song found" << endl;
                cout << "ID: " << move->ID << endl;
                cout << "Title: " << move->Title << endl;
                cout << "Artist: " << move->Artist << endl;
                cout << "Duration: " << move->Duration/60 << ":";
                if (move->Duration%60<10)
                {
                    cout << "0";           
                }
                cout << move->Duration%60 << endl;
                return;
            }
            move=move->next;
        }

        cout << "Song with ID " << id << " not found." << endl;
    }

    void display()
    {
        if (head==NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* move=head;
        while (move!=NULL)
        {
            if (move==current)
            {
                cout << "> ";             
            }
            else
            {
                cout << "  ";
            }

            cout << move->ID << ". " << move->Title << " - " << move->Artist << " (";
            cout << move->Duration / 60 << ":";
            if (move->Duration % 60 < 10)
            {
                cout << "0";
            }
            cout << move->Duration % 60 << ")" << endl;

            move = move->next;
        }

        cout << "Total songs: " << size << endl;
        if(repeat==true)
        {
            cout << "Repeat: ON" << endl;
        }
        else
        {
            cout << "Repeat: OFF" << endl;
        }
    }

    void shuffle()
    {
        if (size<2)
        {
            cout << "Not enough songs to shuffle." << endl;
            return;
        }

        int playingID=current->ID;        

        for (int i=0;i<size;i++)
        {
            int j=rand()%size;          

            Song* first=head;
            for (int k = 0; k < i; k++)
            {
                first = first->next;          
            }

            Song* second = head;
            for (int k = 0; k < j; k++)
            {
                second = second->next;        
            }

            swap(first->ID, second->ID);
            swap(first->Title, second->Title);
            swap(first->Artist, second->Artist);
            swap(first->Duration, second->Duration);
        }

        Song* move = head;
        while (move->ID != playingID)
        {
            move = move->next;
        }
        current = move;

        cout << "Playlist shuffled." << endl;
    }

    void toggleRepeat()
    {
        if (repeat == true)
        {
            repeat = false;
            cout << "Repeat mode is now OFF." << endl;
        }
        else
        {
            repeat = true;
            cout << "Repeat mode is now ON." << endl;
        }
    }

    void displayCurrent()
    {
        if (current == NULL)
        {
            cout << "No song is playing." << endl;
            return;
        }

        cout << "Currently playing:" << endl;
        cout << "ID: " << current->ID << endl;
        cout << "Title: " << current->Title << endl;
        cout << "Artist: " << current->Artist << endl;
        cout << "Duration: " << current->Duration / 60 << ":";
        if (current->Duration % 60 < 10)
        {
            cout << "0";
        }
        cout << current->Duration % 60 << endl;
    }
};

int main()
{
    srand(time(0)); 

    Playlist playlist;
    int choice;
    int id;
    int duration;
    string title;
    string artist;

    while (true)
    {
        cout << endl;
        cout << "Music Playlist" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. Remove a song" << endl;
        cout << "3. Play next" << endl;
        cout << "4. Play previous" << endl;
        cout << "5. Search a song by ID" << endl;
        cout << "6. Display the playlist" << endl;
        cout << "7. Shuffle the playlist" << endl;
        cout << "8. Turn repeat mode on/off" << endl;
        cout << "9. Display the current song" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Enter song ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter duration in seconds: ";
                cin >> duration;
                playlist.addSong(id, title, artist, duration);
                cout << "Song added." << endl;
                break;
            }

            case 2:
            {
                cout << "Enter song ID to remove: ";
                cin >> id;
                playlist.removeSong(id);
                break;
            }

            case 3:
            {
                playlist.playNext();
                break;
            }

            case 4:
            {
                playlist.playPrevious();
                break;
            }

            case 5:
            {
                cout << "Enter song ID to search: ";
                cin >> id;
                playlist.search(id);
                break;
            }

            case 6:
            {
                playlist.display();
                break;
            }

            case 7:
            {
                playlist.shuffle();
                break;
            }

            case 8:
            {
                playlist.toggleRepeat();
                break;
            }

            case 9:
            {
                playlist.displayCurrent();
                break;
            }

            case 0:
            {
                return 0;
            }

            default:
            {
                cout << "Invalid choice" << endl;
            }
        }
    }
}