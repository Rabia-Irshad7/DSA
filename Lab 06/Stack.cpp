#include <iostream>
#include <conio.h>
#include <string>
#include <cctype>
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

class string_Node
{
    public:
    string data;
    string_Node *next;

    string_Node(string value)
    {
        data=value;
        next=NULL;
    }
};

class OpStack
{
    Node *top;

public:
    OpStack()
    {
        top=NULL;
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

    void display()
    {
        if (top==NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *move=top;

        while (move!=NULL)
        {
            cout << move->data << endl;
            move=move->next;
        }
    }

    int precedence(char x)
    {
        if (x == '+' || x == '-')
        {
            return 1;
        }
        else if (x == '*' || x == '/' || x == '%')
        {
            return 2;
        }
        else if (x == '^')
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }

    string infix_to_postfix()
    {
        string expression;
        string answer;

        cout << "Enter an infix expression: ";
        cin >> expression;

        for (int i=0;i<expression.length();i++)
        {
            char c=expression[i];

            if (isalnum(c))
            {
                answer=answer+c;
            }
            else if (c=='(')
            {
                push(c);
            }
            else if (c==')')
            {
                while (!is_empty()&&peek()!='(')
                {
                    answer=answer+peek();
                    pop();
                }

                if(!is_empty() && peek()=='(')
                {
                    pop();
                }
            }
            else
            {
                while (!is_empty() && peek()!='(' && (precedence(peek())>precedence(c) || (precedence(peek())==precedence(c) && c!='^')))
                {
                    answer=answer+peek();
                    pop();
                }
                push(c);
            }
        }
        while (!is_empty())
        {
            answer=answer+peek();
            pop();
        }
        return answer;
    }

    string infix_to_prefix()
    {
        string expression;
        string answer;

        cout << "Enter an infix expression: ";
        cin >> expression;

        for (int i=0, j=expression.length()-1; i<j ;i++, j--)
        {
            char temp=expression[i];
            expression[i]=expression[j];
            expression[j]=temp;
        }

        for (int i=0;i<expression.length();i++)
        {
            if (expression[i]=='(')
            {
                expression[i] = ')';
            }
            else if(expression[i]==')')
            {
                expression[i] = '(';
            }
        }

        for (int i=0;i<expression.length();i++)
        {
            char c=expression[i];

            if (isalnum(c))
            {
                answer=answer+c;
            }
            else if (c=='(')
            {
                push(c);
            }
            else if (c==')')
            {
                while (!is_empty()&&peek()!='(')
                {
                    answer=answer+peek();
                    pop();
                }

                if(!is_empty() && peek()=='(')
                {
                    pop();
                }
            }
            else
            {
                while (!is_empty() && peek()!='(' && (precedence(peek())>precedence(c) || (precedence(peek())==precedence(c) && c=='^')))
                {
                    answer=answer+peek();
                    pop();
                }
                push(c);
            }
        }
        while (!is_empty())
        {
            answer=answer+peek();
            pop();
        }

        for (int i = 0, j = answer.length() - 1; i < j; i++, j--)
        {
            char temp = answer[i];
            answer[i] = answer[j];
            answer[j] = temp;
        }

        return answer;
    }

    ~OpStack()
    {
        while (!is_empty())
        {
            Node *temp=top;
            top=top->next;
            delete temp;
        }
    }
};

class StringStack
{
    string_Node *top;

public:
    StringStack()
    {
        top = NULL;
    }

    void push(string x)
    {
        string_Node *newnode = new string_Node(x);
        newnode->next = top;
        top = newnode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            string_Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek()
    {
        if (top == NULL)
            return "";

        return top->data;
    }

    bool is_empty()
    {
        return top == NULL;
    }

    string postfix_to_infix()
    {
        string expression;
        string answer;

        cout << "Enter a postfix expression: ";
        cin >> expression;

        for (int i = 0; i < expression.length(); i++)
        {
            string c(1, expression[i]);

            if (isalnum(c[0]))
            {
                push(c);
            }
            else
            {
                string op2 = peek();
                pop();

                string op1 = peek();
                pop();

                string result = "(" + op1 + c + op2 + ")";
                push(result);
            }
        }

        answer=peek();
        pop();

        return answer;
    }

    string prefix_to_infix()
    {
        string expression;
        string answer;

        cout << "Enter a prefix expression: ";
        cin >> expression;

        for (int i = expression.length() - 1; i >= 0; i--)
        {
            string c(1, expression[i]);

            if (isalnum(c[0]))
            {
                push(c);
            }
            else
            {
                string op1 = peek();
                pop();

                string op2 = peek();
                pop();

                string result = "(" + op1 + c + op2 + ")";
                push(result);
            }
        }

        answer=peek();
        pop();
        
        return answer;
    }

    string postfix_to_prefix()
    {
        string expression;
        string answer;

        cout << "Enter a postfix expression: ";
        cin >> expression;

        for (int i = 0; i < expression.length(); i++)
        {
            string c(1, expression[i]);

            if (isalnum(c[0]))
            {
                push(c);
            }
            else
            {
                string op2 = peek();
                pop();

                string op1 = peek();
                pop();

                string result = c + op1 + op2;
                push(result);
            }
        }

        answer=peek();
        pop();
        
        return answer;
    }

    string prefix_to_postfix()
    {
        string expression;
        string answer;

        cout << "Enter a prefix expression: ";
        cin >> expression;

        for (int i = expression.length() - 1; i >= 0; i--)
        {
            string c(1, expression[i]);

            if (isalnum(c[0]))
            {
                push(c);
            }
            else
            {
                string op1 = peek();
                pop();

                string op2 = peek();
                pop();

                string result = op1 + op2 + c;
                push(result);
            }
        }

        answer=peek();
        pop();
        
        return answer;
    }

    ~StringStack()
    {
        while (!is_empty())
        {
            pop();
        }
    }
};

int main()
{
    int choice;
    OpStack s;
    StringStack s1;

    while (true)
    {
        cout << "Stack implementation" << endl;
        cout << "1. Infix to postfix conversion\n"
             << "2. Infix to prefix conversion\n"
             << "3. Prefix to infix conversion\n"
             << "4. Prefix to postfix conversion\n"
             << "5. Postfix to infix conversion\n"
             << "6. Postfix to prefix conversion\n"
             << "7. Exit" << endl;

        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << s.infix_to_postfix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 2:
        {
            cout << s.infix_to_prefix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 3:
        {
            cout << s1.prefix_to_infix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 4:
        {
            cout << s1.prefix_to_postfix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 5:
        {
            cout << s1.postfix_to_infix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 6:
        {
            cout << s1.postfix_to_prefix() << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            break;
        }

        case 7:
            return 0;

        default:
            cout << "Invalid input" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }

    return 0;
}