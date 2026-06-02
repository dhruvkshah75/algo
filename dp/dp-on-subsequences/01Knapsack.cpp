// ==================================================== dp on Subsequences ==============================================================


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// ==================================================== 0 / 1 Knapsack ==================================================================

/* A theif enters the room and wants to steal as many items as possible 
   The thief has a bag with a weight capacity => each item that the theif steals has a weight and a value 
   Steal in such a way that the value of the items is maximised 

   ex: weight = [3, 4, 5] and value = [30, 50, 60] and bagW = 8 (weight capacity of the bag) 
   ans: steal 3:30 and 6:60 => total value = 90 
   
   This question can be solved using 0/1 knapsack => choose either to steal or not for that weight   
   
   Greedy fails because the inputs are not uniform => doesnt ensure that picking the best option first gives us the correct answer 


   Solution: 
   explore possible combinations of selecting the weights => recursion is used for this 
   
   1. express everything in terms of indexes => (ind, W)   (W = Bag wieght left)
   2. explore all possibilities => pick or non pick 
   3. max of all possibilities is the result 
*/

// ================================================================================================================================================
//                                                     Top Down Approach (Memoization) dp        
// ================================================================================================================================================

class RecursiveSolution {
private: 
   int dp[1001][1001];
   // dp[ind][W] => dp of arbitrary size 

   int f(int x, int W, vector<pii> &items) {
      // base case => bag is full 
      if(W == 0) return 0;

      // last item left
      if(x == 0) return ((W >= items[0].first) ? items[0].second : 0);

      // OR 
      // if(W == 0 || x < 0) return 0;
      
      if(dp[x][W] != -1) 
         return dp[x][W];

      // cases when the theif steals or does not steal => if stealing then add the value of the item 
      int not_take = f(x - 1, W, items);
      int take = 0;
      if(W >= items[x].first) take = items[x].second + f(x - 1, W - items[x].first, items);

      return dp[x][W] = max(take, not_take);
   }

public: 
   int maximumValueStole(int W, vector<pii> &items) {
      // items[i] = {weight, value}
      // W is the weight cap of the bag

      int n = items.size();

      memset(dp, -1, sizeof(dp));

      return f(n - 1, W, items);
   }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================



class Solution {
public: 
   int maxProfit(vector<int> &val, vector<int> &wt, int n, int W){

      vector<vector<int>> dp(n, vector<int>(W + 1, 0));

      // start from the bases cases 
      // W = 0 => dp[i][0] = 0 (already done) 
      for(int w = wt[0]; w <= W; w++)  
         dp[0][w] = val[0];

      for(int i = 1; i < n; i++) {
         for(int w = 0; w <= W; w++) {
            // either steal the item or not => 0/1 kanpsack 

            int not_take = dp[i - 1][w];
            int take = 0;
            // if theif steals this item then add the value of the item stole 
            if(w >= wt[i]) take = val[i] + dp[i - 1][w - wt[i]];

            dp[i][w] = max(take, not_take);
         }
      }

      return dp[n - 1][W];
   }
};


// =========================================== Space Optimised Solution ==========================================================================================

class SpaceOptimisedSolution {
public:
   int maxProfit(vector<int> &val, vector<int> &wt, int n, int W) {
      // since each calc depends on the prev index so we can space optimise this solution 

      vector<int> prev(W + 1, 0), curr(W + 1);

      // start with the base cases => prev denotes [i - 1] and curr denotes [i]
      for(int w = wt[0]; w <= W; w++) 
         prev[w] = val[0];

      // base case 2: w = 0 => curr[0] = 0

      for(int i = 1; i < n; i++) {
         curr[0] = 0;

         for(int w = 0; w <= W; w++) {
            // either steal or not 
            int not_take = prev[w];
            int take = 0;
            if(w >= wt[i]) take = val[i] + prev[w - wt[i]];
            curr[w] = max(take, not_take);
         }

         prev = curr;
      }

      // after all the iterations prev denotes all the values of dp[n - 1][0...W]
      return prev[W];
   }
};


// above solution can be further space optimised to use only one array O(W) instead of O(2 * W)
// space optimised using 1d array O(W)

class SuperSpaceOptimisedSolution {
public:
   int maxProfit(vector<int> &val, vector<int> &wt, int n, int W) {
      // since each calc depends on the prev index so we can space optimise this solution 

      vector<int> prev(W + 1, 0);

      // start with the base cases => prev denotes [i - 1] and curr denotes [i]
      for(int w = wt[0]; w <= W; w++) 
         prev[w] = val[0];

      // base case 2: w = 0 => curr[0] = 0

      for(int i = 1; i < n; i++) {
         for(int w = W; w >= 0; w--) {
            // either steal or not 
            int not_take = prev[w];
            int take = 0;
            if(w >= wt[i]) take = val[i] + prev[w - wt[i]];
            prev[w] = max(take, not_take);
         }
      }

      // after all the iterations prev denotes all the values of dp[n - 1][0...W]
      return prev[W];
   }
};
