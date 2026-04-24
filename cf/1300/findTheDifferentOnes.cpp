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

// question link: https://codeforces.com/problemset/problem/1927/D

void solve(int n, vector<int> &arr) {
    
    // use a next_diff array which stores the next element not equal to i 
    // next_diff[i] = j (smallest index j => j > i) such that a[j] != i => can be found in one traversal from right to left 

    vector<int> next_diff(n+1, -1);

    for(int i = n-1; i >= 1; i--) {
        if(arr[i] != arr[i + 1]) next_diff[i] = i + 1;
        else next_diff[i] = next_diff[i + 1];
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        if(next_diff[l] == -1 || next_diff[l] > r) 
            cout << -1 << " " << -1 << endl;
        else 
            cout << l << " " << next_diff[l] << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n+1);

        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        solve(n, arr);
    } 
}