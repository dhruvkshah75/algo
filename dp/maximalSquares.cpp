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

// question link: https://leetcode.com/problems/maximal-square/description/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // use 2d dp for getting the maximum size of a square 
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j] = side length of the square whose bottom right corner is [i][j]
        int maxSide = 0;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '0') 
                    dp[i][j] = 0;
                else {
                    // we look at the previously 3 calculated points 
                    // the prev 3 points could either be a part of sqaure then add to it if not then 0 will be min 
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }

                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};
