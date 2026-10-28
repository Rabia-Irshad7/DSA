#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char value)
    {
        data=value;
        next=NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top=NULL;
    }

    ~Stack() 
    {
        while (top!=NULL) 
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    void push(char x)
    {
        Node *newnode=new Node(x);
        newnode->next=top;
        top=newnode;
    }

    void pop()
    {
        if (top==NULL)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            Node *temp=top;
            top=top->next;
            delete temp;
        }
    }

    char peek()
    {
        if (top==NULL)
        {
            return 0;
        }
        else
        {
            return top->data;
        }
    }

    bool is_empty()
    {
        return top==NULL;
    }

};

int main() 
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    Stack st;
    bool balanced=true;

    for (int i=0;i<expression.length();i++) 
    {
        char ch=expression[i];

        if (ch=='(' || ch=='{' || ch=='[') 
        {
            st.push(ch);
        }
        else if (ch==')' || ch=='}' || ch==']') 
        {
            if (st.is_empty()) 
            {
                balanced=false;
                break;
            }

            char topChar=st.peek();

            if ((ch==')' && topChar=='(') || (ch=='}' && topChar=='{') || (ch==']' && topChar=='[')) 
            {
                st.pop();
            }
            else 
            {
                balanced=false;
                break;
            }
        }
    }

    if (!st.is_empty()) 
    {
        balanced=false;
    }

    if (balanced) 
    {
        cout << "Balanced" << endl;
    }
    else 
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}