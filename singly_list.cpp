#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
class Singlylinkedlist
{
public:
    Node *Head;
    Singlylinkedlist()
    {
        head = NULL;
    }
    Singlylinkedlist(Node *n)
    {
        head = n;
    }
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // append
    void append(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "node exist already" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "node appended" << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "node appended" << endl;
            }
        }
    }

    // prepend

    void prepend(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "node exist already" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "node prepended" << endl;
        }
    }
    // insert
    void insert(int k, Node *n)
    {
        node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "no noded exist" << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << "node exist already" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "node inserted" << endl;
            }
        }
    }
    // delete
    void delete (int k)
    {
        if (head == NULL)
        {
            cout << "list empty" << endl;
        }
        else if(head!=Null){
            if(head->key=k){
                head=head->next;
                cout<<"unlinked"<<endl;
            }
            else{
                Node* temp=NULL;
                Node* prevptr=head;
                Node* curtptr=head->next;
                while(curtptr!=NULL){
                    if(curtptr->key=k){
                        temp=curtptr;
                        curtptr=NULL;
                    }
                    else{
                        prevptr=prevptr->next;
                        curtptr=curtptr->next;
                    }
                }
                if(temp!=NULL){
                    prevptr->next=temp->next;
                    cout<<"unlinked"<<endl;
                }
                else{
                    cout<<"NODE DOSNT EXIST"<<endl;
                }
            }

        }
    }
};
int main()
{

    return 0;
}