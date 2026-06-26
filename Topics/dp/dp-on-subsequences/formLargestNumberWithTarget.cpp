#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/description/

// Very messed up example 

/* Explanation: Unbounded Knapsack dp 
   we are supposed to print the or seq that formed or that added to up to be formed
   Can directly be done using string f => at the end instead of max check which string is better 
   Here we use f(ind, target) => max number of digits that add up to target 

   Here there is infinte supply of each number it can be used multiple times
   The number with maximum number of digits will be the biggest number 
*/

class Solution {
private:
    static constexpr int T = 5e3+1;
    string dp[9][T];

    // return true if a is a better option 
    bool isBetter(const string &a, const string &b) {
        // a is invalid => b is btter string by default
        if(a == "0") return false;
        // a is not invalid therefore better than b("0")
        if(b == "0") return true;

        // now compare the digits 
        if(a.length() != b.length()) 
            return a.length() > b.length();

        // simple lexicographical check
        return a > b;
    }
    
    string f(int ind, int target, vector<int> &cost) {
        // base case: target achieved => no more digits should be added 
        if(target == 0) return "";

        // base case: all indexes processed 
        if(ind < 0) return "0";

        if(dp[ind][target] != "") return dp[ind][target];

        // unbounded knapsack 
        string not_take = f(ind-1, target, cost);

        string take = "0";
        if(target >= cost[ind]) {
            string res = f(ind, target-cost[ind], cost);
            // got a valid string => add this digit at the start
            if(res != "0") 
                take = to_string(ind+1) + res;
        }

        return dp[ind][target] = ((isBetter(take, not_take)) ? take : not_take);
    }
    

public:
    string largestNumber(vector<int>& cost, int target) {
        // n = 9 => cost of 9 digits 

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < T; j++) {
                dp[i][j] = ""; 
            }
        }

        return f(8, target, cost);
    }   
};