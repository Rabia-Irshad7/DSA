#include <iostream>
using namespace std;

int DecToBin(int DecNum)
{
    int rem, ans = 0, mult = 1;
    while (DecNum >= 1)
    {
        rem = DecNum % 2;
        DecNum = DecNum / 2;
        ans += rem * mult;
        mult = mult * 10;
    }
    return ans;
}
int main()
{
    int DecNum;
    cout << "Enter a decimal number: ";
    cin >> DecNum;
    cout << "Binary number for " << DecNum << " is: " << DecToBin(DecNum) << endl;
    return 0;
}