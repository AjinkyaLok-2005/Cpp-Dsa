#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL; 
    }

    //destructor
    ~Node()
    {
        int value = this -> data;
        //memory free
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for the node with data " << value << endl;
    }
};

void insertAtHead(Node * &head, int d) //reference islye liya hai kyuki original LL me hi change ho
{   
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp; 
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
    cout << endl;
}

void insertAtPosition(Node* & head, Node* & tail, int position, int d)
{
    //insert at start
    if(position == 1)
    {
        insertAtHead(head, d);
        return ;
    }

    Node * temp = head;
    int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    //insert at tail
    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return ;
    }

    //creating a node for d

    Node * nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node * & head, Node * & tail)
{
    //deleting first node or start node
    if(position == 1)
    {
        Node * temp = head;
        head = head -> next;
        //memory free
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node * curr = head;
        Node * prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL)
        {
            prev -> next = NULL;
            curr -> next = NULL;
            tail = prev;
            delete curr;
        }
        else
        {
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
}

int main()
{
    //created a new node
    Node* node1 = new Node(10);

    //head pointeed to node1
    Node* head = node1;
    Node* tail  = node1;
    print(head);

    insertAtTail(tail, 12);

    print(head);

    insertAtTail(tail, 15);

    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    cout << "head " << head -> data << endl;  
    cout << "tail " << tail -> data << endl;  

    deleteNode(3, head, tail);
    print(head);
    
    cout << "head " << head -> data << endl;  
    cout << "tail " << tail -> data << endl;  

    return 0;
}