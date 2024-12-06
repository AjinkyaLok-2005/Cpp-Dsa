#include<iostream>
using namespace std;

int main()
{
    int row, col;
    row = 3;

    //Creating a Jagged Array
    int** arr = new int* [row];
    int sizes[] = {4, 2, 3};

    for(int i = 0; i < row; i++)
    {
        arr[i] = new int[sizes[i]];
    } 

    //taking input
    cout << "Enter the elements in the array " << endl; 
    for(int i = 0; i < row; i++)
    {
        for(int j = 0 ; j < sizes[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    //giving output
    cout << endl;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}