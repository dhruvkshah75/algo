// ============================================= DSU + Number Theory =================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// question link: https://leetcode.com/problems/greatest-common-divisor-traversal/description/

/* Explanation: DSU + prime factorisation logic
   Here for two indices to be connected i, j => gcd(nums[i], nums[j]) > 1 
   so we could get the prime factorization of each number and then connect each number to 
   its primefactor => a number n can have at most Log(n) number of prime factors 

   To get the prime factorization of a number <= 1e5 => use sieve of erathosnes to get the 
   smallest prime factor of a number and then divide the number n continuouly by its prime factor (smallest)

   in the end after making all the connections if all the elements are part of the same component 
   i.e. traversal is possible then we return true 

   spf[i] = i means i is prime 
   Prime Factorization of a Number is done using Smallest Prime Factor (Sieve of Erathosthenes)
*/

class Solution {
private:
    static constexpr int MAXN = 1e5+10;
    // spf[i] = smallest prime factor of i 
    vector<int> spf; 

    void precomputePrimes(int n) {
        // calculate primes for numbers <= n
        spf.resize(MAXN);
        iota(spf.begin(), spf.end(), 0);

        for(int i = 2; i*i <= n; i++) {
            if(spf[i] == i) {   // if i is prime 
                // for all the multiples of i will have spf = i
                for(int j = i*i; j <= n; j += i) {  
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    vector<int> getPrimeFactors(int n) {
        // get unique prime factors 
        vector<int> res;

        // divide the num continuously by their smallest prime factor
        while(n > 1) {
            int pf = spf[n];
            res.push_back(pf);

            // remove all occurrences of pf to get unique pf
            while(n % pf == 0)
                n /= spf[n];
        }
        return res;
    }

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        bool sameComponent(int u, int v) {
            return find(u) == find(v);
        }
    };
 

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return true;

        // Note: A simple base case => if nums contains 1 and some x then return false => gcd(x, 1) = 1 
        for(int num: nums) {
            if(num == 1) return false;
        }

        int mx = *max_element(nums.begin(), nums.end());

        precomputePrimes(mx);

        DSU d(mx+1);   // DSU contains all the numbers 

        // connect each number to its prime factors 

        for(int i = 0; i < n; i++) {
            for(int pf: getPrimeFactors(nums[i])) 
                d.unite(pf, nums[i]);
        }
        // O(N*Log(M))

        // after making all the connections now check how many components are there for each nums belongs to 
        for(int i = 1; i < n; i++) {
            if(!d.sameComponent(nums[i], nums[0])) return false;
        }

        return true;
    }
};