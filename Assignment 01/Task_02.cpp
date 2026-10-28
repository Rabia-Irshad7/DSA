#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
using namespace std;

class Block 
{
    public:
    int ID;
    string Transaction;
    time_t Time;
    int previousHash;
    int currentHash;
    Block* next;

    Block(int id, string transaction)
    {
        ID=id;
        Transaction=transaction;
        Time=time(nullptr);
        previousHash = 0;
        currentHash = 0;
        next = nullptr;
    }
};

class Blockchain 
{
    Block* head;
    int size;

public:
    Blockchain() 
    {
        head = NULL;
        size = 0;
    }

    int calculateHash(int id, string transaction, time_t timestamp, int previousHash) 
    {
        int sum=id+previousHash+timestamp;
        for(int i=0;i<transaction.length();i++) 
        {
            sum=sum+transaction[i];     
        }
        return sum;               
    }

    Block* createBlock(int id, string transaction, int previousHash) 
    {
        Block* newBlock=new Block(id,transaction);
        return newBlock;
    }

    void addBlock(int id, string transaction) 
    {
        if (head==NULL) 
        {
            head=createBlock(id, transaction, 0);
            size++;
            return;
        }
        else
        {
            Block* move=head;
            while (move->next!=NULL) 
            {
                move=move->next;
            }
            move->next=createBlock(id, transaction, move->currentHash);
            size++;
        }
    }

    void display() 
    {
        if (head==NULL) 
        {
            cout << "Chain is empty." << endl;
            return;
        }

        Block* move=head;
        while (move!=NULL) 
        {
            cout << "Block ID: " << move->ID << endl;
            cout << "Transaction: " << move->Transaction << endl;
            cout << "Timestamp: " << ctime(&move->Time);
            cout << "Previous Hash: " << move->previousHash << endl;
            cout << "Current Hash: " << move->currentHash << endl;
            move = move->next;
        }
        cout << "Total blocks: " << size << endl;
    }

    void search(int id) 
    {
        Block* move=head;

        while(move!=NULL) 
        {
            if(move->ID==id) 
            {
                cout << "Block found" << endl;
                cout << "Block ID: " << move->ID << endl;
                cout << "Transaction: " << move->Transaction << endl;
                cout << "Timestamp: " << ctime(&move->Time);
                cout << "Previous Hash: " << move->previousHash << endl;
                cout << "Current Hash: " << move->currentHash << endl;
                return;
            }
            move = move->next;
        }
        cout << "Block with ID " << id << " not found." << endl;
    }

    void deleteBlock(int id) 
    {
        Block* move=head;
        Block* prev=NULL;

        if (head==NULL) 
        {
            cout << "Chain is empty" << endl;
            return;
        }

        while (move!=NULL&&move->ID!=id) 
        {
            prev=move;
            move=move->next;
        }

        if (move==NULL) 
        {
            cout << "Block with ID " << id << " not found." << endl;
            return;
        }

        if (prev==NULL) 
        {
            head=move->next;     
        }
        else 
        {
            prev->next=move->next;
        }

        Block* after=move->next;     
        delete move;
        size--;

        int newPrevHash;
        if (prev==NULL) 
        {
            newPrevHash=0;          
        }
        else 
        {
            newPrevHash=prev->currentHash;
        }

        while (after!=NULL) 
        {
            after->previousHash=newPrevHash;
            after->currentHash=calculateHash(after->ID, after->Transaction, after->Time, after->previousHash);

            newPrevHash=after->currentHash;   
            after=after->next;
        }

        cout << "Block " << id << " deleted." << endl;
    }

    void verifyChain() 
    {
        if (head==NULL) 
        {
            cout << "Chain is empty." << endl;
            return;
        }

        bool valid=true;
        Block* move=head;
        Block* prev=NULL;

        while (move!=NULL) 
        {
            int recalculated=calculateHash(move->ID, move->Transaction, move->Time, move->previousHash);
            if (recalculated!=move->currentHash) 
            {
                cout << "Block " << move->ID << ": data or hash has been modified!" << endl;
                valid=false;
            }

            if (prev==NULL) 
            {
                if (move->previousHash!=0) 
                {
                    cout << "Block " << move->ID << ": first block should have previous hash 0!" << endl;
                    valid=false;
                }
            }
            else if(move->previousHash!=prev->currentHash) 
            {
                cout << "Block " << move->ID << ": link to previous block is broken!" << endl;
                valid = false;
            }

            prev=move;
            move=move->next;
        }

        if(valid==true) 
        {
            cout << "Chain is valid." << endl;
        }
        else 
        {
            cout << "Chain has been tampered with!" << endl;
        }
    }

};

int main() 
{
    Blockchain chain;
    int choice;
    int id;
    string transaction;
    
    while(true)
    {
        cout << "Blockchain Transaction Chain" << endl;
        cout << "1. Add a block" << endl;
        cout << "2. Display the chain" << endl;
        cout << "3. Search a block by ID" << endl;
        cout << "4. Delete a block" << endl;
        cout << "5. Verify the chain" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) 
        {
            case 1:
            {
                cout << "Enter block ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter transaction: ";
                getline(cin, transaction);
                chain.addBlock(id, transaction);
                cout << "Block added." << endl;
                break;
            }
    
            case 2:
            {
                chain.display();
                cout << "Press any key to continue..." << endl;
                getch();
                break;
            }
    
            case 3:
            {
                cout << "Enter block ID to search: ";
                cin >> id;
                chain.search(id);
                break;
            }
    
            case 4:
            {
                cout << "Enter block ID to delete: ";
                cin >> id;
                chain.deleteBlock(id);
                break;
            }
    
            case 5:
            {
                chain.verifyChain();
                break;
            }
    
            case 6:
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