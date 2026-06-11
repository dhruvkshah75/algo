#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-all-possible-routes/description

/* Explaination: This is simply states dp where we explore all paths possible 
   since even after reaching the finish we can continue exploring 
   we cant simply return as this counts less numnber of paths so while calculating paths we make adjustments 
   ll paths = (ind == finish) ? 1 : 0 
   This means if we are finish => 1 path is obtained and then allow further exploration 
   The base case is implicit that we stop exploring if fuel finishes 

   Similar to graph problems => dfs on all possible routes 
*/

// =============================================================================================================================================
//                                                  Top Down Approach Memoization dp
// =============================================================================================================================================

typedef long long ll;

class Solution {
private: 
    int finish;
    const int MOD = 1e9+7;

    int dp[100][201];

    int f(int ind, int fuel_left, vector<int> &locations) {
        // base case is implicit => exploration stops when fuel is finished 
        
        if(dp[ind][fuel_left] != -1) return dp[ind][fuel_left];

        // we can either stop when finish reached or continue 
        // if finish reached 1 path unclocked otherwise 0
        ll paths = ((ind == finish) ? 1 : 0);

        for(int j = 0; j < (int)locations.size(); j++) {
            if(ind == j) continue;
            // explore all locations that can be reached 
            int dist = abs(locations[ind] - locations[j]);
            if(fuel_left >= dist) paths = (paths + f(j, fuel_left-dist, locations)) % MOD;
        }

        return dp[ind][fuel_left] = paths % MOD;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        this->finish = finish;

        memset(dp, -1, sizeof(dp));

        return f(start, fuel, locations);
    }
};
// space Complexity = O(N * Fuel) + O(N) 