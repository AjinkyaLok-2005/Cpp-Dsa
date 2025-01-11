#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * prev;
    Node * next;

    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node()
    {
        int val = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

// In the print function, it is not necessary to pass the head pointer 
// by reference because the function does not modify the linked list or 
// the value of the head pointer itself
void print(Node * head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head)
{
    int len = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* & head,Node* & tail, int d)
{
    //empty list
    if(head == NULL)
    {
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node * temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* & head, Node * & tail, int d)
{
    //empty list
    if(tail == NULL)
    {
        Node * temp = new Node(d);
        head = temp;  
        tail = temp;
    }
    else
    {
    Node * temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* & head, Node * & tail, int position, int data)
{
    Node * temp = head; 
    Node * nodeToInsert = new Node(data);
    
    if(position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    else
    {
        int cnt = 1;

        while(cnt < position-1)
        {
            temp = temp -> next;
            cnt ++;
        }

        //insert at tail
        if(temp -> next == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }
        else
        {
            nodeToInsert -> next = temp -> next;
            temp -> next -> prev = nodeToInsert;
            temp -> next = nodeToInsert;
            nodeToInsert -> prev = temp;
        }
    }
}

void deleteNode(int position, Node * & head, Node * & tail)
{
    //deleting first node or start node
    if(position == 1)
    {
        Node * temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;  
    }
    else
    {
        //deleting any middle node or last node
        Node * curr = head;
        Node * prev1 = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev1 = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL)
        {
            prev1 -> next = NULL;
            curr -> prev = NULL;
            tail = prev1;
            delete curr;
        }
        else
        {
            curr -> prev = NULL;
            prev1 -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 8, 201);
    print(head);

    cout << getLength(head) << endl;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    return 0;
}