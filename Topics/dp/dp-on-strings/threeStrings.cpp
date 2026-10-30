
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

template <typename T>
void printVec(const vector<T>& v) {
    for(const auto &x: v) cout << x << " ";
    cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
    cerr << "{"; print(p.first); cerr << " ";
    print(p.second); cerr << "}";
}

template <typename T>
void print(const vector<T> &v) {
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * brute force dp needs three pointers i, j, k to denote each character of the string 
 * here ot optimise this we can make a observation that k = i + j
 * so we dont need extra state for handling this 
 * consider all cases of a[i] == c[i+j] or b[j] == c[i+j] if matches otherwise 
 * skip the current character in either string 
 * */

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n1 = a.length(), n2 = b.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    // dp[i][j] = min number of characters that were changed in str c

    auto f = [&](auto &&self, int i, int j) -> int {
        // both strings are exhausted 
        if(i == n1 && j == n2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int res = 1e9;
        // consider the cases of matching and skipping the current char in c 
        if(i < n1) {
            int cost = (a[i] == c[i+j]) ? 0 : 1;
            res = min(res, cost + self(self, i+1, j));
        }

        if(j < n2) {
            int cost = (b[j] == c[i+j]) ? 0 : 1;
            res = min(res, cost + self(self, i, j+1));
        }

        return dp[i][j] = res;
    };

    int ans = f(f, 0, 0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}