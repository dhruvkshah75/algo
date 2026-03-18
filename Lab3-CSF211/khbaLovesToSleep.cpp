#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/2167/E

bool canPlace(int k, int x, vector<int> &a, int dist) {
    int n = a.size();
    long long count = 0;

    if(dist == 0)
        return true;

    // make all the gaps inclusive so there is no ambiguity 
    // left gap: [0, a[0]-dist]
    if (a[0] - dist >= 0)
        count += (a[0] - dist) + 1;

    // middle gaps: (a[i], a[i+1]) => valid zone: [a[i]+dist, a[i+1]-dist]
    for (int i = 0; i + 1 < n; i++) {
        long long L = a[i] + dist;
        long long R = a[i+1] - dist;
        if (R >= L)
            count += (R -L + 1);
    }

    // right gap: [a[n-1]+dist, x] => place them at distance of 1 
    if (a[n-1] + dist <= x)
        count += (x - (a[n-1] + dist)) + 1;

    return count >= k;
}

void solve(int k, int x, vector<int>&a) {
    int n = a.size(); 

    sort(a.begin(), a.end());

    // we can apply binary search on the ans 
    // can we place k teleports that all the friends take more than x min to reach closest teleport 
    int l = 0, r = x;
    int maxDist = 0;
    // the predicate function returns TTTTTTFFFFF => find the last occurrence of T
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(canPlace(k, x, a, mid)) {
            maxDist = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    // now we start placing teleports at distance of maxDist 
    vector<int> result;

    if(maxDist == 0) {
        for(int i = 0; i < k; i++) 
            cout << i << " ";
        cout << endl;
        return;
    }

    // =============== PLACE TELEPORTS ======================

    // left gap: [0, a[0]-maxDist] 
    for(int i = 0; i <= a[0] - maxDist; i++) {
        // place until result size is k 
        if(result.size() == k) break;
        // if valid then only place teleports 
        if(i <= a[0] - maxDist)
            result.push_back(i);
    }

    // middle gaps : [a[0] + maxDist, a[n-1] - maxDist]
    for(int g = 0; g + 1 < n && result.size() < k; g++) {
        // keep updating the gap of L and R 
        long long L = a[g] + maxDist;
        long long R = a[g+1] - maxDist;
        for(long long i = L; i <= R && result.size() < k; i++)
            result.push_back(i);
    }

    // right gap: [a[n-1] + maxDiist, x]
    for(int i = a[n-1] + maxDist; i <= x; i++) {
        if(result.size() == k) break;
        // place only if position is valid in the interval 
        if(i <= x)
            result.push_back(i);
    }

    // print the result 
    for(int &loc: result) 
        cout << loc << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> a(n);

        for(int i=0; i<n; i++)
            cin >> a[i];

        solve(k, x, a);
    }
}