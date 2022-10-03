#include <iostream>
#include <stack>
using namespace std;

string postfixtoinfix( string postfix)
{stack<string> s;

    string infix;
    for (int i = 0; i < postfix.length(); i++)
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {string op(1,postfix[i]);
            s.push(op);
        }
        else 
        {
            string op1, op2;
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            string exp = ('(' + op2 + postfix[i] + op1 + ')');
            s.push(exp);
        }
    }


    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "enter the expression" << endl;
    cin >> postfix;
    cout << "postfix is :: " << postfix << endl
         << endl;
    infix = postfixtoinfix( postfix);
    cout << "infix is :: " << infix << endl;
    cout << "======================================" << endl;
    return 0;
}