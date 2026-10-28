#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of square matrix: ";
    cin >> size;
    int array[size][size];
    cout << "Enter elements: " << endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << "[" << i << "]" << "[" << j << "] : ";
            cin >> array[i][j];
        }
    }
    cout << "Matrix: " << endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
    int count=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i!=j)
            {
                if(array[i][j]==0)
                {
                    count++;
                }
            }
             
        }
    }
    if(count==(size*size)-size)
    {
        cout << "Matrix is diagonal" << endl;
    }
    else
    {
        cout << "Matrix is not diagonal" << endl;
    }
    return 0;
}