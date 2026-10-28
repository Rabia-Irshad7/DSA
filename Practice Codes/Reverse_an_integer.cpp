#include <iostream>
#include<math.h>
using namespace std;
int count(int n)
{
    int count=0;
    while(n>0)
    {
        n=n/10;
        count++;
    }
    return count;
}

int Reverse(int n, int count)
{
    int ans=0,rem,num;
    while(n>0)
    {
        rem=n%10;
        n/=10;
        num=rem*pow(10,count-1);
        ans+=num;
        count--;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reverse of " << n << "=" << Reverse(n,count(n));
    return 0;
}