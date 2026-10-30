// ========================== precomputation + unbounded knapsack dp ========================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
    cerr << "[ ";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << " ]" << endl;
}

/*
 * generate all possible palindromic numbers <= 4e4
 * and precompute => travel through all numbers to get all the palindromes
 * there are 500 palindromic numbers <= 4e4 
 * each palindromic numbers acts as a denomination and apply unbounded knapsack 
 * 500 * 4e4 => 1e6 which is within bounds 
 */

const int MOD = 1e9 + 7;
const int MAXN = 4e4 + 10;

vector<int> A;
vector<vector<int>> dp;

void precompute() {

    auto check = [&](int num) {
        // return true if the given number is a palindrome or not 
        string str = to_string(num);
        string rev_str = str;
        reverse(all(rev_str));
        return (rev_str == str);
    };

    for(int i = 1; i < MAXN; i++) {
        if(check(i)) A.push_back(i);
    }

    int n = A.size();
    print(n); cerr << endl;

    dp.assign(n+1, vector<int>(MAXN, 0));
    // dp[][0] = 1 and for all other cases dp = 0

    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int ind = n-1; ind >= 0; ind--) {
        for(int left = 1; left < MAXN; left++) {
            // either pick or not pick the current element
            ll res = 0;
            res = (res + dp[ind+1][left]) % MOD;
            if(left - A[ind] >= 0) res = (res + dp[ind][left - A[ind]]) % MOD;
            dp[ind][left] = res;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();   
    int sz = A.size();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << dp[0][n] << endl;
    }
}