
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

/*
 * if n >= m then by pigeon hole principle we can say that there are at max 0,1...m-1 => m remainders 
 * therfore overlap occurrs so any segment with two numbers having the same remainder makes that segment 
 * a valid case => this will have elements whose sum adds up to be a multiple of m 
 *
 * other cases when n < m => simply apply dp where n * m <= 1e6
 * so the dp works well within the constraints 
 */

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // if n >= m => true 
    if(n >= m) {
        yes;
        return;
    }

    vector<vector<vector<int8_t>>> dp(n, vector<vector<int8_t>>(m, vector<int8_t>(2, -1)));
    // dp[ind][rem][0/1] => 0/1 to check if at least one element is chosen

    auto f = [&](auto &&self, int ind, int rem, bool picked) -> bool {
        // base case: if rem = 0
        if(picked && rem == 0) return 1;

        // all elements exhausted and the rem was not 0
        if(ind == n) return 0;

        if(dp[ind][rem][picked] != -1) return dp[ind][rem][picked];

        // not_pick the current element in this case  
        bool res = false;
        res = res | self(self, ind+1, rem, picked);

        // pick the current element in the subsequence
        int64_t new_rem = (rem + v[ind]) % m; 
        res = res | self(self, ind+1, static_cast<int>(new_rem), 1);

        return dp[ind][rem][picked] = res;
    };

    bool result = f(f, 0, 0, 0);

    if(result) { yes; }
    else { no; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}