#include <bits/stdc++.h>
using namespace std;

// OPTIMISED VERSION OF CODE => this version reduces the size of the map 
long long solve(int n, std::vector<int> &nums, int k) {
    // n is the length of the nums array 

    unordered_map<int,int> mp;
    long long count = 0;
    int prefix = 0;
    mp[0] = 1;    // entire prefix is the subarray

    // take the % k of all the prefix sums => prefix[j] - prefix[i] = x*k
    // on taking % k => prefix[j] = prefix[i]
    for(int i = 0; i < n; i++) {
        prefix += nums[i];
        prefix = (prefix % k + k) % k;  // => bring down all the no into [0, k-1]
        count += mp[prefix] * 1LL;
        // now fill the map always 
        mp[prefix]++;
    }

    return count;
}