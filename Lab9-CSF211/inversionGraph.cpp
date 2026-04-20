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

// question link: https://codeforces.com/problemset/problem/1638/C

void solve(int n, vector<int> &p) {
    
    /* we must find i < j and pi > pj 
       Use prefix max and suffix min conecpt to get the inversions in O(n)
    */

    vector<int> prefix_max(n), suffix_min(n);

    prefix_max[0] = p[0];
    for(int i = 1; i < n; i++)
        prefix_max[i] = max(prefix_max[i-1], p[i]);

    suffix_min[n-1] = p[n-1];
    for(int i = n-2; i >= 0; i--) 
        suffix_min[i] = min(suffix_min[i+1], p[i]);

    // a new component starts when prefix_max[i-1] < suffix_min[i] => 0...i-1 and i..n-1 (left and right) boundary 
    int components = 1;

    for(int i = 1; i < n; i++) 
        if(prefix_max[i-1] < suffix_min[i]) components++;

    cout << components << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);

        for(int i = 0; i < n; i++) 
            cin >> p[i];

        solve(n, p);
    }
}