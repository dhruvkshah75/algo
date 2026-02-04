#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    // predicate function that returns FFFFFTTTT we have to find the first occurrence of True
    bool canEat(vector<int>&piles, int h, int k) {
        int ctr = 0;  // if this ctr > h then return false, else return true 
        for(int i=0; i<piles.size(); i++) {
            ctr += (piles[i] + k - 1) / k;
            if(ctr > h) return false;
        }
        if(ctr > h) return false;
        else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // apply binary search on k  => The bananas eating speed
        int l = 1, r = *max_element(piles.begin(), piles.end());  // r = max when h = piles.length
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(canEat(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        if(canEat(piles, h, l)) return l;
        else return r;
    }
};

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> piles(n);
    for(int i=0; i<n; i++) {
        cin >> piles[i];
    }

    Solution s = Solution();
    cout << s.minEatingSpeed(piles, h) << endl;

}