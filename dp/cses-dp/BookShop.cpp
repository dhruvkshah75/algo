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
#define rall(x) x.rbegin(), x.rend()

#define f(i, x, n) for(int i = x; i < n; i++) 

// question link: https://cses.fi/problemset/task/1158

// 0-1 Knapsack Variant where space optimisation is needed 

/*
int f(int ind, int sum, vector<int> &pr, vector<int> &pg) {
    // base case: total price budget done 
    if(sum == 0) return 0;

    // base case: last ind reached
    if(ind == 0) {
        // buy the last book if price <= sum
        if(pr[0] <= sum) return pg[0];
        else return 0; 
    }

    // explore all cases 
    int not_take = f(ind-1, sum, pr, pg);

    int take = 0;
    if(sum >= pr[ind]) take = pg[ind] + f(ind-1, sum-pr[ind], pr, pg);

    return max(not_take, take);
}
*/

// f(ind, budget) = max number pages read in suffix[ind....n] and budget left 

void solve(int n, int x, vector<int> &pr, vector<int> &pg) {
    
    vector<int> prev(x+1, 0), curr(x+1, 0);
    // prev => dp[i-1] and curr => dp[i]
    // dp[i][W] = max no of pages read in pf[0...i] in W budget 

    // base case: W = 0 => dp = 0

    // base case: i = 0 => pr[0] <= W dp = pg[0]
    for(int w = pr[0]; w <= x; w++) 
        prev[w] = pg[0];

    for(int i = 1; i < n; i++) {
        curr[0] = 0;

        for(int w = 0; w <= x; w++) {

            int not_take = prev[w];
            int take = 0;
            if(w >= pr[i]) take = pg[i] + prev[w-pr[i]];
            
            curr[w] = max(take, not_take);
        }

        swap(prev, curr);
    }

    // since we have a budget of max x => take the max of dp[n-1]
    cout << *max_element(all(prev)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    
    vector<int> prices(n), pages(n);

    f(i, 0, n) {
        cin >> prices[i];
    }

    f(i, 0, n) {
        cin >> pages[i];
    }

    solve(n, x, prices, pages);
}