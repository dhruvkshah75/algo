// ===================================== math + number theory =============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/

/**
 * using seive of erathosnos get the prime factorisation of all the numbers <= 1000
 * we cannot multply all the numbers and simply get the prime factorisation as product <= 1e9 
 * instead all the prime factors of each number in the array can be used to get the unique or distinct 
 * prime factors => store in set to count number of distinct 
 * 
 * using sieve we get prime Numbers in O(N * Log(Log(N))) and prime factorisation in O(Log(N))
 **/

class Solution {
private:
	const int MAXN = 1e3+10;
	vector<int> spf;

	void sieve() {
        spf.resize(MAXN);
        iota(spf.begin(), spf.end(), 0);

		spf[0] = 0;
		spf[1] = 1;

		for(int i = 2; i * i < MAXN; i++) {
			if(spf[i] == i) {  // spf[i] = i means that i is a prime number 
				for(int j = i * i; j < MAXN; j += i) 
					if(spf[j] == j) spf[j] = i;
			}
		}
		// O(N*LogLogN)
	}

public:
    int distinctPrimeFactors(vector<int> &nums) {
        // precompute all the primes 
		sieve();

        int n = nums.size();

        unordered_set<int> st;
        // store all the unique prime factors of nums[i] 

        for(int i = 0; i < n; i++) {
            // prime factorize this number 
            int num = nums[i];

            while(num > 1) {
                int p = spf[num];
                if(st.find(p) == st.end()) st.insert(p);

                // skip all the occurrences of p 
                while(num % p == 0)
                    num /= p;
            }
            // O(LogN)
        }

        return (int)st.size();
    }
};