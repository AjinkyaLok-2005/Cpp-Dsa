//IMPLEMENTATION OF POINTER ON CHARACTER ARRAYS

#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;
    //attention here
    cout << ch << endl;

    char *c = &ch[0];
    cout << c << endl;
    //PRINTS ENTIRE STRING AND NOT THE ADDRESS

    char temp = 'z'; // jab tak null character nahi milta tab tak print karega
    char *p = &temp;
    cout << p << endl;

    return 0;
}