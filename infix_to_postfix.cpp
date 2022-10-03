#include <iostream>
#include <stack>

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
string infixtopostfix(stack<char> s, string infix)
{
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
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
                postfix += temp;
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
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
                    s.push(infix[i]);
                }
                else
                {
                    while(!s.empty() && precidence(infix[i]) <= precidence(s.top()))
                    {
                        char temp = s.top();
                        postfix += temp;
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
    postfix += temp;
    s.pop();
}

return postfix;
}
int main()
{
    string infix, postfix;
    cout << "enter the expression" << endl;
    cin >> infix;
    stack<char> s;
    cout << "infix is :: " << infix << endl<<endl;
    postfix = infixtopostfix(s, infix);
    cout << "postfix is :: " << postfix << endl;
    cout<<"======================================"<<endl;
  return 0;
}