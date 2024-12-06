#include<iostream>
using namespace std;

void print(int *p)
{
    cout << p << endl;
}

void update(int *p)
{
    // p = p + 1;
    // cout << " inside " << p << endl; 

    *p = *p + 1;
}
    // cout << endl << "Size : " << sizeof(arr) << endl;

int getSum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


int main()
{
    int value = 5;
    int *p = &value;

    // print(p);
    // cout << " Before " << p << endl;    
    // update(p);
    // cout << " After " << p << endl; 
       
    //BOTH THE ABOVE COUT WILL PRINT THE SAME ADDRESS OF P, 
    //THIS IS B/C, WE ARE PRINTING THE SAME P THAT IS PRESENT IN THE MAIN FUNCTION
    //AND NOT IN THE UPDATE FUNCTION
    //IF WE WRITE THE COUT COMMAND IN THE UPDATE FUNCTION THEN IT WILL PRINT THE UPDATED ADDRESS 

    cout << " Before " << *p << endl;    
    update(p);
    cout << " After " << *p << endl; 

    int arr[6] = {1, 2, 3, 4, 5, 8};

    cout << " Sum is : " << getSum(arr+3, 6) << endl;

    return 0;
}
