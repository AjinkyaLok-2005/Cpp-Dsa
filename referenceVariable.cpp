#include<iostream>
using namespace std;

/*
THE BELOW TWO FUNCTIONS WILL GIVE ERROR
int& func(int a)
{
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n)
{
    int* ptr = &n;
    return ptr;
}
*/

void update2(int &n)
{
    n++;
}


void update1(int n)
{
    n++;
}

int getSum(int *arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    /*
    int n = 5;
    
    cout << "Before " << n << endl;
    update1(n);
    cout << "After " << n << endl;

    cout << endl;

    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;
    */

    // char ch = 'q';
    // cout << sizeof(ch) << endl;

    // char *c = &ch;
    // cout << sizeof(c) << endl;

    int n; 
    cin >> n;

    //variable size array
    int* arr = new int[n];

    //taking input in array
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "Answer is : " << ans;

    return 0;

}