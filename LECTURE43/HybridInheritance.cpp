#include<iostream>
using namespace std;

class A
{
    public:
    void func1()
    {
        cout << "Inside Class A " << endl;       
    }
};

class D
{
    public:
    void func4()
    {
        cout << "Inside Class D " << endl;       
    }
};

class B : public A
{
    public:
    void func2()
    {
        cout << "Inside Class B " << endl;       
    }
};

class C : public A, public D
{
    public:
    void func3()
    {
        cout << "Inside Class C " << endl;       
    }
};

int main()
{
    A obj1;
    obj1.func1();
    
    cout << endl;

    D obj4;
    obj4.func4();

    cout << endl;

    B obj2;
    obj2.func1();
    obj2.func2();

    cout << endl;

    C obj3;
    obj3.func1();//from A
    obj3.func4();//from D
    obj3.func3();//from C itself

    cout << endl;

    return 0;
}
