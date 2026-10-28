#include <iostream>
#include <conio.h>
using namespace std;

void Insert(int& size, int& count,int*& array)
{
    int value;
    cout << "Enter value: ";
    cin >> value;
    if(count==size)
    {
        int newSize=size+1;
        int* newArray=new int[newSize];
        for(int i=0;i<count;i++)
        {
            newArray[i]=array[i];
        }
        delete[] array;
        array=newArray;
        array[count]=value;
        count++;
        cout << "Value inserted" << endl;
        cout << "Press any key to go back to main menu" << endl;
        getch();
    }
    else
    {
        array[count]=value;
        count++;
        cout << "Value inserted" << endl;
        cout << "Press any key to go back to main menu" << endl;
        getch();
    }
}

void Delete(int& count, int*& array)
{
    int index;
    cout << "Select the index you want to delete: ";
    cin >> index;
    for(int i=index-1;i<count-1;i++)
    {
        array[i]=array[i+1];
    }
    count--;
    cout << "Value deleted" << endl;
    cout << "Press any key to go back to main menu" << endl;
    getch();
}

void Display(int*& array, int& count)
{
    if(count==0)
    {
        cout << "Array is empty" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "Press any key to go back to main menu" << endl;
        getch();
    }
}

void Search(int& count, int*& array)
{
    int value;
    cout << "Enter the value you want to search: ";
    cin >> value;
    for(int i=0;i<count;i++)
    {
        if(array[i]==value)
        {
            cout << "Value found at index " << i << endl;
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        else
        {
            cout << "Value not found" << endl;
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
    }
}

void Update(int*& array)
{
    int value,index;
    cout << "Enter the index you want to update: ";
    cin >> index;
    cout << "Enter the updated value: ";
    cin >> value;
    array[index-1]=value;
    cout << "Value updated" << endl;
    cout << "Press any key to go back to main menu" << endl;
    getch();
}

int main() {
    int size;
    int count=0;
    cout << "Enter size of array: ";
    cin >> size;
    int* array=new int[size];
    int choice;
    while(true)
    {
        cout << "Dynamic Array Menu" << endl;
        cout << "1. Insert\n2. Delete\n3. Update\n4. Search\n5. Display\n6. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                Insert(size, count, array);
            }
            break;
            case 2:
            {
                Delete(count, array);
            }
            break;
            case 3:
            {
                Update(array);
            }
            break;
            case 4:
            {
                Search(count, array);
            }
            break;
            case 5:
            {
                Display(array, count);
            }
            break;
            case 6:
            {
                return 0;
            }
            break;
        }
    }
    return 0;
}