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

// question link: https://codeforces.com/problemset/problem/1178/B

void solve(string &str) {
    // question is based on dp to count subsegments 

    int n = str.length();

    /* we can use dp to calculate the number of w that can be formed => two consecutive vv form a w
       if str[i] == str[i-1] == v then dp[i] = dp[i-1] + 1 
       if str[i] == 'o' then reset the dp[i]
       For each 'o' in the string at the ith position dp[i-1] * dp[just before next o]  */
    
    // use dp[i] = number of w's formed till the ith position (including i) 
    vector<ll> dp(n);
    dp[0] = 0;


    for(int i = 1; i < n; i++) {        
        if(str[i] == 'v' && str[i-1] == 'v') 
            dp[i] = dp[i-1] + 1;
        else 
            dp[i] = dp[i-1];
    }

    // vvvovvvv => 2 w;s before o and 2 after o till the last then 2 * 2 
    // formula = (if str[i] == 'o') then (number of left w's) * (number of right w's)  
    
    ll result = 0;

    for(int i = 1; i < n; i++) {
        if(str[i] == 'o') {
            int pos = i - 1;
            // number of W's on the right is dp[n-1] - dp[pos]
            result += (dp[n-1] - dp[pos]) * 1LL * dp[pos];
        }
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    solve(str);
}