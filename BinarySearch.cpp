#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;

    int mid = start + (end-start) / 2;
//this can also be written like start+end / 2
//but the above method works for unversal case
//we considered that if in case the values of start and end are greater than (2^31-1) 
//then it would be impossible to add start and end b/c max val. of int is (2^31-1)

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }

        if(key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1; 
        }

        mid = start + (end-start) / 2; 
    }
    return -1;
}


int main()
{

    int even[6] = {2, 4, 6, 8, 12, 16};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenindex = binarySearch(even, 6, 12);

    cout << "Index of 12 is " << evenindex << endl;

    int oddindex = binarySearch(odd, 5, 14);

    cout << "Index of 14 is " << oddindex << endl;

    return 0;
}
