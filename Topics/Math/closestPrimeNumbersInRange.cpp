// ===================================================== Number theory ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/

class Solution {
private:
	int N;
	vector<bool> isPrime;

	void sieve() {
		isPrime[0] = false;
		isPrime[1] = false;

		for(int i = 2; i * i < N; i++) {
			if(isPrime[i]) {
				// mark out all the multiples of i (prime number)
				for(int j = i * i; j < N; j += i) 
					isPrime[j] = false;
			}
		}
	}

public:
    vector<int> closestPrimes(int left, int right) {
    	N = right + 1;
        isPrime.resize(N, true);
        
        // precompute all the primes in the range [2...right]
        sieve();

        vector<int> res(2, -1);

        // now traverse through all numbers in the range [left, right] and get the pair with min diff 
        int prev = -1, min_diff = 1e9;

        for(int j = left; j <= right; j++) {
        	if(!isPrime[j]) continue;

        	// j is prime so compare with prev prime number 
        	if(prev != -1 && j-prev < min_diff) {
        		res[0] = prev;
        		res[1] = j;

        		min_diff = j-prev;
        	}

        	// update the prev prime number 
        	prev = j;
        }

        return res;
    }
};