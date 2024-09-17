#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int> & arr)
{
    int n = arr.size();

    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for(; j >= 0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
                
        }
        arr[j+1] = temp;
    }
}

int main()
{
    // vector<int> arr ={10, 1, 7, 4, 8, 2, 11};
    vector<int> arr ={8, 22, 7, 9, 31, 5, 13};
    insertionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) 
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    return 0;   
}