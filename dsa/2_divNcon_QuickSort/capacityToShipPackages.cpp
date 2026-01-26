#include <bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

/*
    Algorithm: 
        Binary Search on Answer

        * Search Space: Define the range [L, R], where L = {max}(weights) and R = {sum}(weights).
        * Predicate Function (P(x)): Creates a series of FFFFFTTTTT.
        * Logic: Greedily sum weights; if a sum exceeds capacity x, increment the day counter.
        * Returns: `True` if total days <= target `days`, otherwise `False`.
        * Binary Search:
            1.  Calculate mid = L + (R - L) / 2.
            2.  If P(mid) is T: r = mid. .
            3.  If P(mid) is F: l = mid.
            After the check if check for l and if true then return l or else return r

        ### Complexity
        * Time: O(nlog(sum)).
        * Space: O(1).
*/


class Solution {
public:
    // FFFFFFTTTTT --> find the first occurrence of T 
    bool possibleVal(vector<int>&weights, int days, int val) {
        int ctr = 1;
        int curr_sum = 0;
        for(int i=0; i<weights.size(); i++) {
            curr_sum += weights[i];
            // adding the current element makes it go out of the range so revert the sum to that element and increase the day counter 
            if(curr_sum > val) {  
                curr_sum = weights[i];
                ctr++;
                if(ctr > days) return false;
            }
        }
        if(ctr > days) return false;
        else return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // l is when there is days = weights.size() and r is when there is 1 day
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(possibleVal(weights, days, mid)) r = mid-1;
            else l = mid+1;
        }
        // we first check l as its lower 
        if(possibleVal(weights, days, l)) return l;
        else return r;
    }
};


int main(){
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);

    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }

    Solution s = Solution();
    cout << s.shipWithinDays(weights, days) << endl;
}