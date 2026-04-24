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

// question link: https://codeforces.com/problemset/problem/628/B

void solve(string &str) {
    int n = str.length();

    // Divisibilty test for 4 => the last 2 digits of the number should be divisible by 4
    
    // dp[i] = number of substrings that are divisible by 4 till the ith position 
    vector<ll> dp(n, 0);

    if((str[0] - '0') % 4 == 0) 
        dp[0] = 1;


    for(int i = 1; i < n; i++) {
        int ones = str[i] - '0', tens = str[i-1] - '0';
        int num = tens * 10 + ones;

        // firstly get the cases from the prev and then add the new counts 
        dp[i] = dp[i-1];

        if(ones % 4 == 0) dp[i] += 1;
        // if end two digits are divisible by 4 then all the numbers ending in this are valid 
        if(num % 4 == 0) 
            dp[i] += i;
    }

    cout << dp[n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    solve(str);
}