#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://takeuforward.org/plus/dsa/problems/ninja's-training


// =============================================================================================================================
//                                          Bottom Up approach (tabulation) dp 
// ============================================================================================================================= 

// non optimised in space 
class Solution {
public:
    int ninjaTraining(vector<vector<int>> &matrix) {
        // n * 3 matrix 
        int n = matrix.size();

        /* Use a 2d vector dp where dp[i][j] denotes the max merit points earned till the ith day 
           dp[i][j] = matrix[i][j] + matrix[i-1][j' != j] */

        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                int max_prev = 0;

                for(int k = 0; k < 3; k++) {
                    if(k == j) continue;
                    max_prev = max(dp[i][k], max_prev);
                }

                dp[i+1][j] = matrix[i][j] + max_prev;
            }
        }

        return max({dp[n][0], dp[n][1], dp[n][2]});
    }
};

class SpaceOptimisedSolution {
public: 
    int ninjaTraining(vector<vector<int>> &matrix) {
        // n * 3 matrix 
        int n = matrix.size();

        /* Use a 2d vector dp where dp[i][j] denotes the max merit points earned till the ith day 
           dp[i][j] = matrix[i][j] + matrix[i-1][j' != j] 
           For space optimisation only maintain the merit points for the last occured day */

        vector<int> dp(3, 0), temp(3, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                int max_prev = 0;

                for(int k = 0; k < 3; k++) {
                    if(k == j) continue;
                    max_prev = max(dp[k], max_prev);
                }
                temp[j] = matrix[i][j] + max_prev;
            }

            dp = temp;
        }

        return max({dp[0], dp[1], dp[2]});
    }
};


// =============================================================================================================================
//                                  Top Down Approach (Memoization) dp  
// =============================================================================================================================
class RecursiveSolution {
private:
    int f(int day, int lastTask, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        // define the base case 
        if(day == 0) {
            int maxi = 0;

            for(int j = 0; j < 2; j++) {
                if(lastTask == j) continue;
                maxi = max(maxi, matrix[0][j]);
            }

            return maxi;
        }

        // if this subtree in the recursion is tree already known then just return 
        if(dp[day][lastTask] != -1) 
            return dp[day][lastTask];

        int maxi = 0;

        for(int task = 0; task < 3; task++) {
            if(task == lastTask) continue;
            // calling again with the lastTask as the task done on the current day 
            int points = matrix[day][task] + f(day-1, task, matrix, dp);
            maxi = max(maxi, points);
        }

        return dp[day][lastTask] = maxi;
    }

public:
    int ninjaTraining(vector<vector<int>> &matrix) {
        // n * 3 matrix 
        int n = matrix.size();

        // apply recursion with 0 as the base case where we stop 
        // keep a variable of the last task that we performed

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return f(n-1, -1, matrix, dp);
    }
};
