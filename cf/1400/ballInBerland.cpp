#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1475/C

void solve(int a, int b, int k, vector<int> &boys, vector<int> &girls) {
    
    vector<int> degB(a+1, 0), degG(b+1, 0);

    for(int i = 0; i < k; i++) {
        degB[boys[i]]++; 
        degG[girls[i]]++;
    }

    // total possible pairs is C(k,2)
    // invalid pairs are C(n,2) where n is the deg of either girls and boys 
    auto nCk = [&](int n) {
        // C(n, 2)
        return ((ll)n * (n-1)) / 2;
    };

    ll total_pairs = nCk(k);
    ll invalid_pairs = 0;
    // now calculate the invalid pairs 
    for(int i = 1; i <= a; i++) 
        invalid_pairs += nCk(degB[i]);

    for(int i = 1; i <= b; i++) 
        invalid_pairs += nCk(degG[i]);

    cerr << "total: " << total_pairs << endl;
    cerr << "invalid: " << invalid_pairs << endl;
 
    cout << total_pairs - invalid_pairs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    
    while(t--) {
        int a, b, k;
        cin >> a >> b >> k;

        vector<int> boys(k), girls(k);

        for(int i = 0; i < k; i++) 
            cin >> boys[i];

        for(int i = 0; i < k; i++) 
            cin >> girls[i];

        solve(a, b, k, boys, girls);
    }
}