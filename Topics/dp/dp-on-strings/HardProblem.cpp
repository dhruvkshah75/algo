#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e15;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fr(i, x, n) for(int i = x; i < n; i++)

// question link: https://codeforces.com/problemset/problem/706/C

/* Explaination: We select the string to be either from strs or rev_strs 
   At each step we have two options => reverse the string at a cost of cost[ind] 
   or keep the original string => do both these cases and check does this ensure lexicographical ordering of these two 
   
   Reccurrence => f(ind, prev_case)
   prev_case = 0 => means first string nothing before this string 
   prev_case = 1 => the strs[ind-1] was not reversed 
   prev_case = 2 => the previous string was reversed */


ll f(int ind, int prev_case, vector<int> &costs, vector<string> &strs, vector<string> &rev_strs, vector<vector<ll>> &dp) {
    // base case: all the strings are processed 
    if((size_t)ind == costs.size()) return 0;

    if(dp[ind][prev_case] != -1) return dp[ind][prev_case];
    
    // try all possible cases of either reversing the string or not 
    // => only when prev is lexicographically smaller
    string prev = "";
    if(prev_case == 1) prev = strs[ind-1];
    else if(prev_case == 2) prev = rev_strs[ind-1];

    ll not_rev = inf;
    if(prev_case == 0 || prev <= strs[ind]) {
        // current string is not reversed => cost = 0
        not_rev = f(ind+1, 1, costs, strs, rev_strs, dp);
    }

    ll rev = inf;
    if(prev_case == 0 || prev <= rev_strs[ind]) {
        // the current string is reversed for cost[ind]
        rev = costs[ind] + f(ind+1, 2, costs, strs, rev_strs, dp);
    }

    return dp[ind][prev_case] = min(rev, not_rev);
}

void solve(int n, vector<int> &costs, vector<string> &strs, vector<string> &rev_strs) {
    
    vector<vector<ll>> dp(n, vector<ll>(3, -1));

    // starting from the 0th index => prev_case = 0 => no previous string 
    ll res = f(0, 0, costs,  strs, rev_strs, dp);

    if(res >= inf) cout << -1 << endl;
    else cout << res << endl;
}
// Space Complexity = O(StrLen* N) + O(3 * N) + O(N), Time Complexity = O(N * StringLen)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> costs(n);

    fr(i, 0, n) {
        cin >> costs[i];
    }

    vector<string> strs(n), rev_strs(n); 

    fr(i, 0, n) {
        cin >> strs[i];
        string rev = strs[i];
        reverse(all(rev));
        rev_strs[i] = rev;
    }

    solve(n, costs, strs, rev_strs);
}