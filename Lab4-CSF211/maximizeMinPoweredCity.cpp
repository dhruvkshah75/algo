// VERY IMPORTANT 
#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/
// HARD Leetcode Question

// BINARY SEARCH On Answer and SLIDING WINDOW (Difference array concept)

/*
    For the predicate function we check if the min value of the power array can be brought to x 
    for this we use sliding window approach of difference array to track where we have made changes to the power in the array
    when we encounter a tower with less power than x (the min we want) 
    Suppose we encountered <= x case at ith index then we place new towers at i+r (greedy)
    While doing this we update the diff array at i and i + 2r + 1 and we compare the updated the power that is the 
    current_additions += diff[i] => total_power = power[i] + current_additions   
*/


class Solution {
    // predicate functions returns TTTTTTFFFFFF => find the last occurrence of T
    bool isPossible(vector<long long>&power, int r, int k, long long x) {
        // can we get the min value of power to be >= x by placing k additional towers 
        // some sort of sliding window concept => use difference arrays 
        int n = power.size();
        vector<long long> diff(n+1, 0);
        // this var maintains the additions we need to add to
        long long current_additions = 0;    
        long long cnt = 0;  // if this exceeds k return false

        for(int i=0; i<n; i++) {
            current_additions += diff[i];  // check if some additions were made or not 

            long long total_power = power[i] + current_additions;

            if(total_power >= x) continue;
            // at i + r if power[i] < x ==> this is the best way 
            long long needed = x - total_power;
            cnt += needed;  // these many towers are used 
            if(cnt > k) 
                return false;
            
            // the range of adding the tower is i to i + 2r
            // so we put -needed in the diff array at i + 2r + 1;
            current_additions += needed;
            
            if(i + 2*r + 1 < n) {
                diff[i + 2*r + 1] -= needed;
            }
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        // r is the range of the tower 

        vector<long long> prefix(n);
        prefix[0] = stations[0];
        for(int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + stations[i] * 1LL;

        // using the prefix sum array we calculate the power array 
        // i.e. how many stations provide power to the ith city
        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            // Sum in range [left, right] is prefix[right] - prefix[left-1]
            power[i] = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
        }

        // applying binary search on the ans that is what will the max strength 
        long long low = *min_element(power.begin(), power.end());
        long long high = 2e12;  
        long long ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(isPossible(power, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};


int main() {
    int n, k, r;
    cin >> n >> r >> k;

    vector<int> stations(n);
    for(int i=0; i<n; i++)
        cin >> stations[i];

    Solution s = Solution();
    long long ans = s.maxPower(stations, r, k);
    cout << ans << endl;
}