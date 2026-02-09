#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
// HARD Leetcode Question 

class Solution {
public:
    // preidcate function that returns FFFFFFTTTTTT => find the first occurence of T
    // Returns True when there are at most K elements that are at least x
    bool predicate(int m, int n, int k, int x) {
        int ctr = 0;
        for(int i=1; i <= m; i++) {
            if(i > x) break;
            if(x/i <= n) 
                ctr += x / i;
            else 
                ctr += n;
        }
        if(ctr >= k) 
            return true;
        else 
            return false;
    }

    int findKthNumber(int m, int n, int k) {
        // we apply binary search on the ans
        int low = 1, high = m * n;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
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
    int m, n, k;
    cin >> m >> n >> k;

    Solution s = Solution();
    cout << s.findKthNumber(m, n, k) << endl;
}