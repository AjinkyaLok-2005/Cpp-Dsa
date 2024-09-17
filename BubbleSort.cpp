#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>&  arr)
{
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
    {
        //for round 1 to n-1

        bool swapped = false;

        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(swapped = false)
        {
            //array already sorted
            //BEST CASE COMPLEXITY
            break;
        }

    }

}

int main()
{
    vector<int> arr = {1, 7, 6, 10, 9, 14};

    bubbleSort(arr);  // Pass the vector directly

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) 
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    return 0;   
}