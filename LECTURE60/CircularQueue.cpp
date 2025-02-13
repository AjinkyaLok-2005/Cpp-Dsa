#include<iostream>
using namespace std;

class CircularQueue
{
    public:
    int * arr;
    int front;
    int rear;
    int size;

    CircularQueue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        if((front == 0 && rear == size - 1) || (rear == (front-1) % (size-1)))
        {
            cout << "Queue is Full " << endl;
            return false;
        }
        else if(front == -1) //first element to push
        {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        if(front == -1)
        {
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) //single element is present
        {
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    void print()
    {
        if(front == -1)  // Queue is empty condition
    {
        cout << "Queue is Empty " << endl;
        return;
    }

    cout << "Queue Elements: ";
    
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";
        if (i == rear)  // Stop when the last element is printed
            break;
        i = (i + 1) % size;  // Move circularly
    }
    
    cout << endl;
    }
};

int main()
{
    CircularQueue CQ(5);
    CQ.enqueue(15);
    CQ.enqueue(25);
    CQ.enqueue(35);
    CQ.enqueue(45);
    CQ.enqueue(55);
    CQ.enqueue(65);

    CQ.print();

    cout << "Dequeued: " << CQ.dequeue() << endl; // Removes 15
    cout << "Dequeued: " << CQ.dequeue() << endl; // Removes 25

    CQ.enqueue(65);
    CQ.enqueue(75);
    CQ.enqueue(85);

    CQ.print();
    return 0;
}