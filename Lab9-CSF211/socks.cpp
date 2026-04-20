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

// question link: https://codeforces.com/problemset/problem/731/C

struct DSU {
    vector<int> parent, size;
    vector<unordered_map<int,int>> freq;
    // freq[parent][color] = count => one map per node in map  
    
    // color of the parent sock of that component 
    DSU(int n, vector<int> &color) : parent(n), size(n, 1), freq(n) {
        iota(all(parent), 0);
        // initially all the colors are 1 
        for(int i = 0; i < color.size(); i++) 
            freq[i][color[i]] = 1;
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];

        // now pu contains both pv and pu so update the maps of pu 
        for(auto &[col, cnt]: freq[pv]) 
            freq[pu][col] += cnt;
        
        // now clear the maps of pv 
        freq[pv].clear();
    }
};

void solve(int n, int m, vector<int> &colors) {

    /* Each day requires a pair of socks (l, r) to have the same color.
       Group all socks that must match using DSU.
       For each final component, we must pick one color for all socks in it.
       To minimize repaints, keep the majority color and repaint the rest.
       Repaints for a component = size - max_color_frequency. */

    DSU d(n, colors);

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;    // make the indexing 0 based 
        // l and r socks are supposed to used on the ith day 
        d.merge(l, r);
    }

    // now the components left out we must use the formula size - freq of color 
    int result = 0;

    for(int i = 0; i < n; i++) {
        if(d.find(i) == i && !d.freq[i].empty()) {
            // for the ith component get the color with max freq 
            int max_freq = 0;

            for(auto &[col, cnt]: d.freq[i]) {
                max_freq = max(max_freq, cnt);
            }
            result += d.size[i] - max_freq;
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    // n socks, m days (m edges), k colors 
    cin >> n >> m >> k;

    vector<int> colors(n);
    for(int &c: colors)
        cin >> c;

    solve(n, m, colors);
}