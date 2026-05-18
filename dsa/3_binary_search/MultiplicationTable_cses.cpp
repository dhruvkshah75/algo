#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
// HARD Leetcode Question 

class Solution {
public:
    // preidcate function that returns FFFFFFTTTTTT => find the first occurence of T
    // Returns True when there are at most K elements that are at least x
    bool predicate(int m, int n, long long k, long long x) {
        long long ctr = 0;
        for(int i=1; i <= m; i++) {
            if(i > x) break;
            if(x/i <= n) 
                ctr += x / i;
            else 
                ctr += n * 1LL;
        }
        if(ctr >= k) 
            return true;
        else 
            return false;
    }

    long long findKthNumber(int m, int n, long long k) {
        // we apply binary search on the ans
        long long low = 1, high = m * 1LL * n;
        long long ans = -1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(predicate(m, n, k, mid)) { 
                ans = mid; 
                high = mid - 1;
            }
            else low = mid + 1;
        }   
        return ans;
    }
};


int main() {
    int m;
    cin >> m;

    long long k = (m *1LL * m) / 2 + 1; 

    Solution s = Solution();
    cout << s.findKthNumber(m, m, k) << endl;
}