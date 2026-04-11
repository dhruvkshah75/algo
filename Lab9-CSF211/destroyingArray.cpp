#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/722/C

// VERY IMPORTANT QUESTION => DSU + OFFLINE 

struct DSU {
    vector<int> parent, size;
    vector<ll> sum;           // store the some of connected component to get the ans in O(1)
    ll maxSum;

    DSU(int n) : sum(n, 0), parent(n, -1), size(n, 1), maxSum(0) {}
    
    int find(int u) {
        if(parent[u] != -1 && parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        // update the sum of the new group with ultimate parent pu
        sum[pu] += sum[pv];
        maxSum = max(maxSum, sum[pu]);
    }

};

void solve(int n, vector<int> &arr, vector<int> &perm) {
    // Process deletions in reverse as insertions — a very common and important DSU trick
    // in reverse we get that the deletions becomes insertion

    // mark the unavailable nodes as -1 and then revive them 

    DSU d(n+1);

    vector<int> v(n+1, -1);
    vector<ll> result;

    for(int i = n; i >= 1; i--) {
        result.push_back(d.maxSum);

        // revive the element at index perm[i] 
        int idx = perm[i];
        v[idx] = arr[idx];
        d.parent[idx] = idx;          // make the node available in parent in dsu 
        d.sum[idx] = v[idx];

        // Tricky Edge Case: if the node is single => then update the maxSum
        d.maxSum = max(d.maxSum, d.sum[idx]);

        if(idx < n && v[idx+1] != -1) 
            d.unite(idx, idx+1);
        
        if(idx > 1 && v[idx-1] != -1) 
            d.unite(idx, idx-1);  
    }

    reverse(result.begin(), result.end());

    for(ll val: result) 
        cout << val << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n+1), perm(n+1);

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++) 
        cin >> perm[i];

    solve(n, arr, perm);
}