#include <iostream>
using namespace std;

const int N = 5;

bool friends_[N][N] = {
    { false, true,  false, true,  true  }, 
    { true,  false, true,  false, true  },  
    { false, true,  false, false, false },  
    { true,  false, false, false, true  }, 
    { true,  true,  false, true,  false }  
};

void printMatrix() {
    cout << "  ";
    for (int i = 0; i < N; i++)
    {
        cout << i << " ";
    } 
    cout << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << i << " ";
        for (int j = 0; j < N; j++)
        {
            if(friends_[i][j]==true)
            {
                cout << "* ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool haveCommonFriend(int a, int b) 
{
    for (int k = 0; k < N; k++) 
    {
        if (friends_[a][k] && friends_[b][k])
        {
             return true;
        }
    }
    return false;
}

int main() 
{
    cout << "Friendship matrix (* = friends): " << endl;
    printMatrix();
    int a, b;
    cout << "Enter two people to check (0-4): ";
    cin >> a >> b;
    if (a >= 0 && a < N && b >= 0 && b < N) 
    {
        if(haveCommonFriend(a,b)==true)
        {
            cout << a << " and " << b << " have common friend" << endl;
        }
        else
        {
            cout << a << " and " << b << " do not have common friend" << endl;
        }
    } 
    else 
    {
        cout << "Invalid person index.\n";
    }

    return 0;
}