#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
  int n = arr.size();  // Get size from vector

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}

int main() {
  vector<int> arr = {64, 25, 12, 22, 11};

  selectionSort(arr);  // Pass the vector directly

  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
