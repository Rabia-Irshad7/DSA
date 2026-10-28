#include <iostream>
using namespace std;

int BinToDec(int binaryNumber)
{
    int rem, mult=1, ans=0;
    while(binaryNumber>0)
    {
        rem=binaryNumber%10;
        ans+=rem*mult;
        binaryNumber=binaryNumber/10;
        mult=mult*2;
    }
    return ans;
    
}

int main() {
    int binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    cout << "Decimal form of " << binaryNumber << " is: " << BinToDec(binaryNumber) << endl;
    return 0;
}