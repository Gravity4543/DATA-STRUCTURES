#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int precidence(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
    return 0;
}
string infixtoprefix(stack<char> s, string infix)
{
    string prefix;
    //cout<<"reverse"<<endl;
    reverse(infix.begin(), infix.end());
        for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {//cout<<"operand working"<<endl;
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                prefix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {//cout<<"operator working"<<endl;
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else if (!s.empty())
            {
                if ((precidence(infix[i]) > precidence(s.top())))
                {
                    s.push(infix[i]);
                }
                else if (precidence(infix[i]) == precidence(s.top()) && infix[i] == '^')
                {
                    while (precidence(infix[i]) == precidence(s.top()) && infix[i] == '^')
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if(precidence(infix[i]) == precidence(s.top())){
                    s.push(infix[i]);
                }
                else
                {
                    while((!s.empty()) && (precidence(infix[i]) < precidence(s.top())))
                    {
                        char temp = s.top();
                        prefix += temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        char temp = s.top();
        prefix += temp;
        s.pop();
    }
   
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string infix, prefix;
    cout << "enter the expression" << endl;
    cin >> infix;
    stack<char> s;
    cout << "infix is :: " << infix << endl
         << endl;
    prefix = infixtoprefix(s, infix);
    cout << "prefix is :: " << prefix << endl;
    cout << "======================================" << endl;
    return 0;
}