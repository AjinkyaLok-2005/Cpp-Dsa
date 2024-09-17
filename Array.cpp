#include<iostream>
#include<climits>
using namespace std;


void printArray(int arr[],int size){

    
    cout << "Printing the array" << " " <<endl;

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
         
    }
    cout << "Printing done" << " " <<endl;

}


int main(){
    //declare
    int number[15];

    cout << "Value at 15 index" << " "<< number[14] << endl;
    // cout << "Value at 20 index" << " "<< number[20] << endl;


    int second[3] = {5, 7, 11};

    cout << "Value at 2 index" << " "<< second[2] << endl;

    cout << "Everything is fine" << endl;

    int  third[15] = {2,7};

    // printArray(third, 15);
    // cout << endl; 


    int fourth[10] = {0};


    // printArray(fourth, 10);


    int fifth[10] = {1};
    // printArray(fifth, 10);

    int fifthSize = sizeof(fifth) / sizeof(int);
    cout << "Size of fifth " << fifthSize << " " << endl;

    char ch[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << ch[3] << endl;

    cout << "Printing the array" << " " <<endl;

    for(int i = 0; i < 5; i++)
    {
        cout << ch[i] <<" ";
         
    }
    cout << "Printing done" << " " <<endl;

    return 0;
}



int getMax(int num[], int n)
{
    int MAX = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        MAX = max(MAX, num[i]);  //this is inbuilt function for max
        // if(num[i] > max)
        // {
        //     max = num[i];
        // }
    }

    // return max;
    return MAX;
}

int getMin(int num[], int n)
{
    int MINI = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        MINI = min(MINI,num[i]); //this is inbuilt function for min
        // if(num[i] < min)
        // {
        //     min = num[i];
        // }
    }

    // return min;
    return MINI;
}


int main() {

    int size;
    cin >> size;

    int num[100];

    for(int i = 0; i < size; i++)
    {
        cin >> num[i];
    }


    cout << "Maximum value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;
    return 0;
}

