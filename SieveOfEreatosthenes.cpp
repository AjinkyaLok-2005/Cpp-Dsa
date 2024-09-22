//efficient for prime numbers counting

#include<iostream>
#include<vector>

using namespace std;

int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> primes(n+1, true);

    primes[0] = primes[1] = false;

    // Mark all multiples of 'i' as not prime
    for(int i = 2; i < n; i++)
    {
        if(primes[i]) // whether the value of primes[i] is true.
        cnt++;

        for(int j = 2*i; j < n; j = j+i)
        {
            primes[j] = 0; // Mark multiple as false
        }
    }
    return cnt;
}

int main()
{
    int n = 40;

    cout << "Number of Prime Numbers less than " << n << " is: " << countPrimes(n) << endl;
    return 0;
}