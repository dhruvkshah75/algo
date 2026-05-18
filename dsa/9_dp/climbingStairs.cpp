#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/climbing-stairs/description/

// This is the recurrence relation way
int climbStairs(int n) {
    //base case:
    if(n == 1)
        return 1;
    // the recurrence relation is T(n) = 1*T(n-2) + 1*T(n-1)
    // T(n) = T(n-1) + T(n-2) => simple fibonacci
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) 
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}


// the optimised way is not using the vector => simply use two variables to store the n-1 and n-2th value 
int climbStairsOptimised(int n) {
    // base case:
    if(n == 1 || n == 2)
        return n;

    int a = 1, b = 2;  // a is N-2 and b is N-1
    int result = 0;

    for(int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}


// NOTE: Fibonacci series using recursion 
// Memoization => top down approach 
int rFib(int n, vector<int> &dp) {
    // base case => if it falls to either 1 or 0 
    if(n <= 1) 
        return n;

    // if this already exists then dont caclulate again 
    if(dp[n] != -1)
        return dp[n];

    return dp[n] = rFib(n-1, dp) + rFib(n-2, dp);

}

int fibonacci(int n) {
    vector<int> dp(n+1, -1);
    return rFib(n, dp);
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;
}