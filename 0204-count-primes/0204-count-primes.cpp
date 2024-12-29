class Solution {
public:
    int countPrimes(int n) {
        // Return 0 if n is less than 2 (as there are no primes less than 2)
        if (n <= 2) return 0;

        // Create a boolean array to track prime numbers
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime numbers
        isPrime[0] = isPrime[1] = false;

        // Start from 2 and mark multiples as non-prime
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }

        return count;
    }
};
