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

// question link: https://codeforces.com/problemset/problem/920/C

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

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void solve(int n, vector<int> &arr, string &str) {
    
    /* use DSU to connect the places that can be swapped and store the values in the map 
       so we can then replace them with the increasing ordering for that component and then at the end 
       check if the array is sorted after a sequence of swaps */

    DSU d(n);

    for(int i = 0; i+1 < n; i++) {
        if(str[i] == '1') {
            d.merge(i, i+1);
        }
    }

    map<int,vector<int>> mp;
    // mp[parent] = values in this component

    for(int i = 0; i < n; i++) {
        mp[d.find(i)].push_back(arr[i]);
    }

    // now sort all the components in descending order so we can start placing them in the array 
    for(auto &[p, v]: mp) 
        sort(allr(v));
    // <= O(N * Log(N))

    for(int i = 0; i < n; i++) {
        int p = d.find(i);
        arr[i] = mp[p].back();
        mp[p].pop_back();
    }

    // check if it is sorted or not 
    for(int i = 0; i + 1 < n; i++) {
        if(arr[i] > arr[i + 1]) {
            no; return;
        }
    }

    yes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    string str;

    for(int i = 0; i < n; i++)  
        cin >> arr[i];

    cin >> str;

    solve(n, arr, str);
}