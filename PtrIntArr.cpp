#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {23, 122, 41, 67};

/*
    cout <<"address of first memory block is "<< arr << endl;
    cout << arr[0] << endl;
    cout << "Address of first memory block is " << &arr[0] << endl;

    cout << "4th " << *arr << endl;
    cout << "5th " << *arr + 1 << endl;
    cout << "6th " << *(arr + 1) << endl;
    cout << "7th " << *(arr) + 1 << endl;  
    cout << "8th " << arr[2] << endl;  
    cout << "9th " << *(arr + 2) << endl;  

    int i = 3;
    cout << i[arr] << endl;
*/

/*    //PROCESSING ON ARRAY
    int temp[10];
    cout << sizeof(temp) << endl;
    cout << "1st" << sizeof(*temp) << endl;
    cout << "2st" << sizeof(&temp) << endl;

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl; //address
    cout << sizeof(*ptr) << endl; 
    cout << sizeof(&ptr) << endl; //address

*/


    int a[20] = {1, 2, 3, 5};
    // cout << " -> " << &a[0] << endl;
    // cout << &a << endl;
    // cout << a << endl;

    int *p = &a[0];
    cout << p << endl; //address of arr[0]
    cout << *p << endl; //Value 
    cout << " -> " << &p << endl; // address of p itself


    // int arr[10];

    // //ERROR
    // //arr = arr + 1;

    // int *ptr = &arr[0];
    // cout << ptr << endl;
    // ptr = ptr + 1; // yahape array k first block ka address increment 
    // cout << ptr << endl;

    return 0;
}