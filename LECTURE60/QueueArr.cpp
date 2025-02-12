#include<iostream>
using namespace std;

class Queue
{
    public:
    int * arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int element)
    {
        if(rear == size)
        {
            cout << "Queue is Full " << endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int dequeue()
    {
        if(front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear)
            { 
                front = 0;
                rear = 0;            
            }
            return ans;
        }
    }

    int getFront()
    {
        if(front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if(front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if(front == rear)
        {
            cout << "Queue is Empty " << endl;
        }
        else
        {
            cout << "Queue Elements: " << endl;
            for(int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q(10);

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);
    q.enqueue(45);

    q.print();

    q.dequeue();
    q.dequeue();

    q.print();

    cout << q.getFront() << endl;

    return 0;
}