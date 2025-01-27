#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack
{
    public:
    Node * top;

    Stack()
    {
        this -> top = NULL;
    }

    void push(int data)
    {
        Node * newNode = new Node(data);
        if(top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode -> next = top;
            top = newNode;
        }

        cout << data << " is pushed into the stack " << endl;
    }

    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack UnderFlow " << endl;
            return;
        }

        Node * temp = top;
        int value = temp -> data;
        top = top -> next;
        delete temp;
        cout << value << " is popped from the stack " << endl;
    }

    int peek()
    {
        if(top != NULL)
        {
            return top -> data;
        }
        else
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st;

    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);

    cout << endl;

    st.pop();
    st.pop();
    
    cout << endl;

    st.push(100);

    cout << endl;

    cout << "Top element after popping: " << st.peek() << endl;

    cout << endl;

    cout << (st.isEmpty() ? "Stack is Empty " : "Stack is not Empty ") << endl;

    return 0;
}