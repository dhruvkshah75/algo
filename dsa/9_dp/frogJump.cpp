#include<bits/stdc++.h>
using namespace std;

// question link: https://takeuforward.org/plus/dsa/problems/frog-jump

int frogJump(vector<int>& heights) {
    int n = heights.size();
    // find out how to reach the ith height using dp => we use a bottom up approach start from 0
    vector<int> dp(n);
    // dp[i] = minimum energy to reach step i
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    
    for(int i = 2; i < n; i++) {
        // way1 = jump from i-1 to i => this energy to reach from i-1 to i + min energy to reach i-1 = dp[i-1]
        int way1 = abs(heights[i] - heights[i-1]) + dp[i-1];
        // way2 = jump from i-2 to i 
        int way2 = abs(heights[i] - heights[i-2]) + dp[i-2];
        dp[i] = min(way1, way2);
    }

    return dp[n-1];
}

// Modified Frog Jump
/*
    In this question we use dp to check the min energy used to reach n-1 
    dp[i] = min cost needed to reach the ith step 
    frog can jump from [i-k, i-1] to i so we just get the min of this and store them in dp[i]
    => that is the get the best jump from any step in i-k to i-1 to ith step 
*/

int frogJumpKthStep(vector<int> &heights, int k) {
    // frog can jump from ith step to [i+1, i+k] anywhere in here 
    int n = heights.size(); 

    vector<int> dp(n);   // dp[i] = min energy to reach to step i 
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        // [i-k, i-1] can jump to ith step
        int j = max(0, i - k);
        int minWay = INT_MAX;
        // calculate the best spot to jump onto to ith step from the window of [i-k, i-1]
        while(j < i) {
            int temp = abs(heights[i] - heights[j]) + dp[j];
            minWay = min(minWay, temp);
            j++;
        }
        dp[i] = minWay;
    }

    return dp[n-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i = 0; i < n; i++) 
        cin >> heights[i];

    cout << frogJump(heights) << endl;
}