#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

/*
    How does this predicate function works ?
    So mid days have passed so the flowers with bloomDay[i] <= mid bloomed, so we have to find 
    if k consecutive flowers have bloomed then we make 1 boquet, keep doing this 
    but if a flower has not bloowed then break there are start searching for the next k consecutive 
    flowers.
    If we are able to make more than m boquets then return true otherwise return false;
*/
class Solution {
public:
    // a predicate function that returns FFFFFTTTT
    // we need to find the first occurrence of T as we need to find the min
    bool canMakeBoquets(vector<int>&bloomDay, int m, int k, int mid) {
        int n = bloomDay.size();
        int i = 0, ctr = 0;
        while(i < n) {
            if(i + k > n) break;  // if k flowers are not left then break 
            int j = i;
            while(j < k + i && bloomDay[j] <= mid) j++;
            if(j == k + i) ctr++; // if k consecutive flowers bloomed then 1 boquet is formed 
            // now we increment i => but with caution 
            if(j == i) i = j + 1;  // did not proceed ahead i.e. the ith element itself did not bloom
            else i = j;
            if(ctr >= m) return true;
        } 
        if(ctr >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m * 1LL * k > n) return -1;  // less flowers than needed to make m boquet 
        int ans = -1;
        int l = 1, r = 1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canMakeBoquets(bloomDay, m, k, mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);

    for(int i=0; i<n; i++) {
        cin >> bloomDay[i];
    }

    Solution s = Solution();
    cout << s.minDays(bloomDay, m, k) << endl;
}
