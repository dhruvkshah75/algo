#include <bits/stdc++.h>
using namespace std;

// returns FFFFFTTTTT => find the first occurrence of T
bool isPossible(vector<int>&a, long long k, long long x) {
    // returns True if there are atleast k pairs whose distance <= x
    long long ctr = 0;
    int n = a.size();
    int i = 0, j = 1;
    while(i < n && j < n) {
        while(j < n && a[j] - a[i] <= x) j++;
        if(i == j){
            j++;
            continue;
        }
        ctr += (j - i - 1) * 1LL;
        i++;
        if(j == n) break;
    }
    // if j ends first then add all the remaining combinations 
    ctr += ((j-i) *1LL* (j-i-1)) / 2;

    return (ctr >= k);
}

long long solve(int n, std::vector<int> &a, long long k) {

    sort(a.begin(), a.end());
    // applying binary search on the ans that is what would be the kth smallest distance
    long long l = 0, r = a[n-1] - a[0];
    long long ans = 0;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
        if(isPossible(a, k, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;
}
