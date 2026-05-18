#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1609/D

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

    bool merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];

        return true;
    }
};

void solve(int n, int d) {
    // we must use exactly i introductions 
    
    DSU dsu(n+1);

    // we proccess the connections => if person x and person y not known then we connect them with 1 move 
    // if x and y already friends then we get one bonus move we use that to connect it to the next big group

    int extra_moves = 0;

    for(int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;

        // if they are already friends then we gain one extra move 
        if(!dsu.merge(x, y)) {
            extra_moves++;
        }

        // now the total number of acquintances will be (extra_moves + 1) max groups 
        unordered_set<int> seen;
        vector<int> compSize;

        for(int i = 1; i <= n; i++) {
            if(dsu.find(i) == i && !seen.count(i)) {
                compSize.push_back(dsu.size[i]);
                seen.insert(i);
            }
        }
        // sort in reverse to get the top group sizes
        sort(allr(compSize));

        int count = 0;

        for(int j = 0; j < min(extra_moves + 1, (int)compSize.size()); j++) {
            count += compSize[j];
        }


        // there are count number of people in the same component => so count-1 acquaintances for a person 
        cout << count - 1 << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    solve(n, d);
}