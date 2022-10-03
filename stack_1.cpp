#include <iostream>
using namespace std;

class Stack
{
private:
    int top{-1};
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
        return 0;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int popval = arr[top];
            arr[top] = 0;
            top--;
            return popval;
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            cout << arr[pos] << endl;
        return 0;}
    }
    void change(int position, int value)
    {
        arr[position] = value;
        cout << "value changed" << endl;
    }
    void display()
    {
        for (int i = 4; i >=0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack a;
    int option, position, value;
    do
    {
        cout << "enter the option number of the funtion to perform" << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. is Full" << endl;
        cout << "4. is empty" << endl;
        cout << "5. count" << endl;
        cout << "6. display" << endl;
        cout << "7. change" << endl;
        cout << "8. peek" << endl;
        cout << "============================================================" << endl;
        cout << "============================================================" << endl;

        cin >> option;

        switch(option)
        {
        case 1:
            cin >> value;
            a.push(value);
            cout << "value pushed" << endl;
            break;
        case 2:
            cout << "value popped --" << a.pop() << endl;
            break;
        case 3:
            if (a.isFull() == true)
            {
                cout << "stack is full"<<endl;;
            }
            else
            {
                cout << "stack  is not full"<<endl;
            }
            break;
        case 4:
            if (a.isEmpty() == true)
            {
                cout << "stack is empty"<<endl;
            }
            else
            {
                cout << "stack is not empty"<<endl;
            }
            break;
        case 5:
            cout << "count is " << a.count();
            break;
        case 6:
            a.display();
            break;
        case 7:
            cout << "enter the value and position to be changed--" << endl;
            cin >> value >> position;
            a.change(position, value);
            break;
        case 8:
            cout << "enter the position to peek";
            cin >> position;
            a.peek(position);
            break;
        default:
            cout << "enter the number from given options"<<endl;
        }

    } while (option != 0);

        return 0;
}