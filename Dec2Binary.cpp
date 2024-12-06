#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 0)
    {
        // To store the two's complement of the negative number
        int absValue = -n; // First get the absolute value of the negative number
        absValue = ~absValue + 1; // Take one's complement and add 1 for two's complement

        // Now absValue is in two's complement format
        int ans = 0;
        int place_value = 1;

        // Convert absValue to binary (this is the two's complement form)
        while (absValue != 0)
        {
            int bit = absValue & 1; // Extract the least significant bit
            ans = ans + (bit * place_value); // Add it to the answer with the correct place value
            absValue = absValue >> 1; // Right shift to process the next bit
            place_value *= 10; // Move to the next place value in binary
        }

        cout << "Answer is -" << ans << endl;  // Print the binary representation for negative number
    }
    else
    {
        // DECIMAL TO BINARY for positive number
        int ans = 0;
        int place_value = 1;

        while (n != 0)
        {
            int bit = n & 1; // Extract least significant bit
            ans = ans + (bit * place_value); // Add to the answer with the correct place value
            n = n >> 1; // Right shift to process the next bit
            place_value *= 10; // Move to the next place value in binary
        }

        cout << "Answer is " << ans << endl; // Print binary for positive number
    }

    return 0;
}




























