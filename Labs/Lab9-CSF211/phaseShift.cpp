#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1735/C

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
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
    // we can use dsu to connect characters we start with a 

    vector<int> nxt(26, -1);
    // nxt[i] = what letter i maps to 
    DSU dsu(26);

    string result = "";

    for(int i = 0; i < n; i++) {
        int d = str[i] - 'a';

        // check if d is already mapped to something (result[i] -> d)
        int parentD = -1;
        for(int x = 0; x < 26; x++) {
            if(nxt[x] == d) { 
                parentD = x; 
                break; 
            }
        }

        // if parentD is not -1 then d is already assigned to something 
        if(parentD != -1) {
            result += (char)(parentD + 'a');
            continue;
        }

        // not assigned then we must choose the smallest x
        // x != d (no self loop), nxt[x] == -1 (not already assigned), and cycle is not formed 
        int chosen = -1, cycleChosen = -1;;
        for(int x = 0; x < 26; x++) {
            if(x == d || nxt[x] != -1) continue;

            if(dsu.find(x) == dsu.find(d)) {
                // only allow if it completes all 26 
                if(dsu.size[dsu.find(x)] == 26 && cycleChosen == -1)
                    cycleChosen = x;
                continue;
            }
            chosen = x;
            break;
        }

        if(chosen == -1) chosen = cycleChosen;

        nxt[chosen] = d;  // chosen -> d (chosen encrypts to d)
        dsu.unite(chosen, d);        // make connection between chosen and d

        result += (char)(chosen + 'a');
    }

    cout << result << endl;
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