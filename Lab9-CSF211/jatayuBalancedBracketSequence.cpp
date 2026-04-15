#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()

// question link: https://codeforces.com/problemset/problem/1726/C

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void solve(int n, string &str) {
    // using a stack we get the valid sequences 

    DSU d(2*n);
    // nodes are the vertices 

    stack<int> st;
    // this helps to find last seen seq at a specific nesting level 
    vector<int> last_at_level(n+2, -1);
    int current_level = 0;

    for(int i = 0; i < 2*n; i++) {
        if(str[i] == '(') {
            current_level++;
            st.push(i);
        }
        else {
            int topIdx = st.top();
            st.pop();
            d.unite(topIdx, i);

            // if there was sequence right before this seq at the same level 
            if(last_at_level[current_level] != -1) 
                d.unite(i, last_at_level[current_level]);

            // store the value at the current level 
            last_at_level[current_level] = topIdx;

            // clear the next level for future moves 
            last_at_level[current_level + 1] = -1;
            // we just closed this nesting so reduce the current level by 1 
            current_level--;
        }
    }

    // we always have a complete valid sequence so connect the first index and last index 
    d.unite(0, 2*n-1);

    int cnt = 0;

    for(int i = 0; i < 2*n; i++) {
        if(d.find(i) == i) cnt++;
    }
    // no of connected components 
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        solve(n, str);
    }
}