#include <iostream>

using namespace std;

class Numbers
{
private:
    int size;
    int* ptr;
public:
    Numbers():size(0),ptr(0)
    {

    }
    void setValue(int n, int arr[])
    {
        size=n;
        ptr=new int[size];
        for(int i=0;i<size;i++)
        {
            ptr[i]=arr[i];
        }
    }
    Numbers(const Numbers &obj)
    {
        size=obj.size;
        ptr=new int[size];
        for(int i=0;i<size;i++)
        {
            ptr[i]=obj.ptr[i];
            cout << "Copy constructor is called" << endl;
        }
    }
    Numbers& operator=(const Numbers &obj)
    {
        if(this==&obj)
        {
            return *this;
        }
        delete[] ptr;

        size=obj.size;
        ptr=new int[size];
        for(int i=0;i<size;i++)
        {
            cout << "Copy assignment operator called" << endl;
        }
        return *this;
    }
    ~Numbers()
    {
        delete[] ptr;
        cout << "Destructor called" << endl;
    }

    void Display()
    {
        for(int i=0;i<size;i++)
        {
            cout << ptr[i] << " " << endl;
        }
    }

};

int main()
{
    int arr[4]={11,22,33,44};
    Numbers Num1;
    Num1.setValue(4, arr);

    Numbers Num2(Num1);

    cout << "Num1: ";
    Num1.Display();
    cout << "Num2: ";Num2.Display();

    Numbers Num3;
    Num3=Num1;
    cout << "Num3: ";
    Num3.Display();
    return 0;
}
