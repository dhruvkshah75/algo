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

// question link: https://codeforces.com/problemset/problem/1332/C

// based on DSU 
struct DSU {
    vector<int> parent, size;
    
    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] == u) 
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void solve(int n, int k, string &str) {
    
    // using DSU combine the positions that should be equal => str[i] = str[n-k-1] and str[i] = str[i+k]
    DSU d(n);

    // form the components => characters that need to be the same 
    for(int i = 0; i < n; i++) {
        // merge the positions => palindromic merge and periodic merge
        if(i + k < n) 
            d.merge(i+k, i);

        d.merge(i, n-i-1);
    }

    // now connections are formed 
    vector<map<char,int>> freq(n);

    for(int i = 0; i < n; i++) {
        int p = d.find(i);
        // store map of chars for each parent 
        freq[p][str[i]]++;
    }

    int result = 0;
    // The final result => ans += (for each component) size of component - max cnt element in that component 
    for(int i = 0; i < n; i++) {

        if(d.find(i) != i || freq[i].empty()) continue;

        int max_cnt = INT_MIN;
        for(auto &[c, cnt]: freq[i]) {
            max_cnt = max(max_cnt, cnt);
        }

        result += (d.size[i] - max_cnt);
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        solve(n, k, str);
    }
}