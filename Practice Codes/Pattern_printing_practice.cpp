#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter a number: ";
   cin >> n;
   int num=1;
   for(int i=0;i<n;i++)
   {
        for(int j=n-i-1;j>=1;j--)
        {
            cout << " ";
        }
        cout << "*";
        for(int j=1;j<num;j++)
        {
            cout << " ";
        }
        num+=2;
        if(i!=0)
            cout << "*";
        cout << endl;
   }
    return 0;
}